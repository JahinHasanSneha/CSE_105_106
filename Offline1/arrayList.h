#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int capacity;
    int length;
    int current;
} arrayList;

void init(arrayList *list)
{
    list->array = (int *)malloc(2 * sizeof(int));
    list->capacity = 2;
    list->length = 0;
    list->current = 0;
}

void free_list(arrayList *list)
{
    free(list->array);
    list->array = NULL;
    list->capacity = 0;
    list->length = 0;
    list->current = 0;
}

void increase_capacity(arrayList *list)
{
    int new_capacity = list->capacity * 2;
    int *new_array = (int *)realloc(list->array, new_capacity * sizeof(int));
    if (new_array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Capacity increased from %d to %d\n", list->capacity, new_capacity);
    list->array = new_array;
    list->capacity = new_capacity;
}

void decrease_capacity(arrayList *list)
{
    int new_capacity = list->capacity / 2;
    if (new_capacity < 2)
    {
        new_capacity = 2;
    }
    int *new_array = (int *)realloc(list->array, new_capacity * sizeof(int));
    if (new_array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Capacity decreased from %d to %d\n", list->capacity, new_capacity);
    list->array = new_array;
    list->capacity = new_capacity;
}

void print(arrayList *list)
{
    if (list->length == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[");
    for (int i = 0; i < list->current; i++)
    {
        printf(" %d", list->array[i]);
    }
    printf(" |");
    for (int i = list->current; i < list->length; i++)
    {
        printf(" %d", list->array[i]);
    }
    printf(" ]\n");
}

void insert(int item, arrayList *list)
{
    if (list->length >= list->capacity / 2)
    {
        increase_capacity(list);
    }
    for (int i = list->length; i > list->current; i--)
    {
        list->array[i] = list->array[i - 1];
    }
    list->array[list->current] = item;
    list->length++;
    list->current++;
}

int delete_cur(arrayList *list)
{
    if (list->length == 0 || list->current == 0)
    {
        return -1;
    }
    int deleted = list->array[list->current - 1];
    for (int i = list->current - 1; i < list->length - 1; i++)
    {
        list->array[i] = list->array[i + 1];
    }
    list->length--;
    if (list->current > list->length)
    {
        list->current = list->length;
    }

    // Check if we need to shrink the array
    if (list->length < list->capacity / 4)
    {
        decrease_capacity(list);
    }
    return deleted;
}

void append(int item, arrayList *list)
{
    if (list->length >= list->capacity / 2)
    {
        increase_capacity(list);
    }
    list->array[list->length] = item;
    if (list->current == 0 && list->length > 0)
    {
        list->current = list->length;
    }
    list->length++;
}
int size(arrayList *list)
{
    return list->length;
}
void reverse_range(int k, arrayList *list)
{
    if (k <= 1 || list->length <= 1)
        return;

    int n = list->length;

    for (int start = 0; start < n; start += k)
    {
        int left = start;
        int right = start + k - 1;

        if (right >= n)
            right = n - 1;

        // Reverse current block
        while (left < right)
        {
            int temp = list->array[left];
            list->array[left] = list->array[right];
            list->array[right] = temp;
            left++;
            right--;
        }
    }
}
void skip_delete(int k, arrayList *list)
{
    if (k < 0 || list->length == 0)
        return;

    int write = 0;      // position where we will write the next kept element
    int count = 0;      // counts how many elements we have kept in current group

    for (int read = 0; read < list->length; read++)
    {
        count++;

        if (count == k + 1)          // time to delete this element
        {
            count = 0;               // reset counter for next group
            // simply skip copying this element
        }
        else
        {
            // keep this element
            list->arr[write] = list->arr[read];
            write++;
        }
    }

    list->length = write;   // update the new length of the list
}
void rotate(int r, arrayList *list)
{
    int val;
    if (r == 0)
    {

        val = list->array[0];
        for (int i = 0; i < list->length - 1; i++)
        {
            list->array[i] = list->array[i + 1];
        }
        list->array[list->length-1] = val;
    }
    else
    {
        val = list->array[list->length - 1];
        for (int i = 0; i < list->length - 1; i++)
        {
            list->array[i + 1] = list->array[i];
        }
        list->array[0] = val;
    }
}
void prev(int n, arrayList *list)
{
    list->current -= n;
    if (list->current < 0)
    {
        list->current = 0;
    }
}

void next(int n, arrayList *list)
{
    list->current += n;
    if (list->current > list->length)
    {
        list->current = list->length;
    }
}

int is_present(int n, arrayList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->array[i] == n)
        {
            return 1;
        }
    }
    return 0;
}

void clear(arrayList *list)
{
    free_list(list);
    init(list);
}

int delete_item(int item, arrayList *list)
{
    if (list->length == 0)
    {
        printf("%d not found\n", item);
        return -1;
    }
    int found = 0;
    for (int i = 0; i < list->length; i++)
    {
        if (list->array[i] == item)
        {
            found = 1;

            for (int j = i; j < list->length - 1; j++)
            {
                list->array[j] = list->array[j + 1];
            }
            list->length--;
            if (i < list->current)
            {
                list->current--; // cursor moves left if deleted before it
            }
            else if (i == list->current && list->current >= list->length)
            {
                list->current = list->length - 1; // if cursor was last, move to new last
            }

            printf("%d is deleted\n", item);

            if (list->length < list->capacity / 4)
            {
                decrease_capacity(list);
            }
            return 1;
        }
    }
    return 0;
}

int search(int item, arrayList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        if (list->array[i] == item)
        {
            return i;
        }
    }
    return -1;
}

int find(int ind, arrayList *list)
{
    if (ind < 0 || ind >= list->length)
    {
        return -1;
    }
    return list->array[ind];
}

int update(int ind, int value, arrayList *list)
{
    if (ind < 0 || ind >= list->length)
    {
        return -1;
    }
    int old = list->array[ind];
    list->array[ind] = value;
    return old;
}

int trim(arrayList *list)
{
    if (list->length == 0)
    {
        return -1;
    }
    int last = list->array[list->length - 1];
    list->length--;
    if (list->current > list->length)
    {
        list->current = list->length;
    }
    if (list->length < list->capacity / 4)
    {
        decrease_capacity(list);
    }
    return last;
}
void swap_ind(int ind1, int ind2, arrayList *list)
{
    if (ind1 < 0 || ind1 >= list->length || ind2 < 0 || ind2 >= list->length)
    {
        return;
    }
    int temp = list->array[ind1];
    list->array[ind1] = list->array[ind2];
    list->array[ind2] = temp;
}

void reverse(arrayList *list)
{
    if (list->length <= 1)
        return;
    for (int i = 0, j = list->length - 1; i < j; i++, j--)
    {
        int temp = list->array[i];
        list->array[i] = list->array[j];
        list->array[j] = temp;
    }

    // Move cursor only if it was at index 0
    if (list->current == 0 && list->length > 1)
    {
        list->current = list->length - 1;
    }
}
