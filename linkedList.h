#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int element;
    struct node *next;
    struct node *prev;
} node;

typedef struct
{
    node *head;
    node *tail;
    node *curN;
    int current;
    int length;
} linkedList;

void init(linkedList *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->current = 0;
    list->curN = NULL;
    list->length = 0;
}

void free_list(linkedList *list)
{
    node *temp = list->head;
    while (temp != NULL)
    {
        node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    list->curN = NULL;
    list->current = 0;
}

void print(linkedList *list)
{
    if (list->length == 0)
    {
        printf("[ . ]\n");
        return;
    }
    printf("[");

    node *temp = list->head;
    int count = 0;
    while (count < list->current && temp != NULL)
    {
        printf(" %d", temp->element);
        temp = temp->next;
        count++;
    }

    printf(" |");

    while (temp != NULL)
    {
        printf(" %d", temp->element);
        temp = temp->next;
    }

    printf(" ]\n");
}

void insert(int item, linkedList *list)
{
    node *n = (node *)malloc(sizeof(node));
    n->element = item;
    n->next = NULL;
    n->prev = NULL;

    if (list->length == 0)
    {

        list->head = n;
        list->tail = n;
        list->curN = n;
        list->current = 1;
        list->length = 1;
        return;
    }

    if (list->current == 0)
    {

        n->next = list->head;
        list->head->prev = n;
        list->head = n;
        list->curN = n;
    }
    else if (list->current == list->length)
    {

        n->prev = list->tail;
        list->tail->next = n;
        list->tail = n;
        list->curN = n;
    }
    else
    {

        node *temp = list->head;
        for (int i = 0; i < list->current && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {

            free(n);
            return;
        }

        n->next = temp;
        n->prev = temp->prev;
        if (temp->prev != NULL)
        {
            temp->prev->next = n;
        }
        else
        {
            list->head = n;
        }
        temp->prev = n;
        list->curN = n;
    }

    list->length++;
    list->current++;
}


void append(int item, linkedList *list)
{
    node *n = (node *)malloc(sizeof(node));
    n->element = item;
    n->next = NULL;
    n->prev = list->tail;

    if (list->length == 0)
    {
        list->head = n;
        list->tail = n;

        if (list->current == 0)
        {
            list->current = 1;
        }
    }
    else
    {
        list->tail->next = n;
        list->tail = n;
    }

    list->length++;
}

int size(linkedList *list)
{
    return list->length;
}

void prev(int n, linkedList *list)
{
    list->current -= n;
    if (list->current < 0)
    {
        list->current = 0;
    }
}

void next(int n, linkedList *list)
{
    list->current += n;
    if (list->current > list->length)
    {
        list->current = list->length;
    }
}

int is_present(int n, linkedList *list)
{
    node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->element == n)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void clear(linkedList *list)
{
    free_list(list);
    init(list);
}

int delete_item(int item, linkedList *list)
{
    if (list->length == 0)
    {
        return 0;
    }

    node *temp = list->head;
    int index = 0;

    while (temp != NULL)
    {
        if (temp->element == item)
        {
            // Remove node from list
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                list->head = temp->next;
            }

            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            else
            {
                list->tail = temp->prev;
            }

            // Update cursor if needed
            if (index < list->current)
            {
                list->current--;
            }

            node *to_delete = temp;
            temp = temp->next;
            free(to_delete);
            list->length--;

            return 1;
        }
        temp = temp->next;
        index++;
    }

    return 0;
}

void swap_ind(int ind1, int ind2, linkedList *list)
{
    if (ind1 < 0 || ind1 >= list->length || ind2 < 0 || ind2 >= list->length)
    {
        return;
    }

    node *node1 = list->head;
    for (int i = 0; i < ind1 && node1 != NULL; i++)
    {
        node1 = node1->next;
    }

    node *node2 = list->head;
    for (int i = 0; i < ind2 && node2 != NULL; i++)
    {
        node2 = node2->next;
    }

    if (node1 == NULL || node2 == NULL)
    {
        return;
    }

    int temp = node1->element;
    node1->element = node2->element;
    node2->element = temp;
}

int search(int item, linkedList *list)
{
    node *temp = list->head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->element == item)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int find(int ind, linkedList *list)
{
    if (ind < 0 || ind >= list->length)
    {
        return -1;
    }

    node *temp = list->head;
    for (int i = 0; i < ind && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return -1;
    }

    return temp->element;
}

int update(int ind, int value, linkedList *list)
{
    if (ind < 0 || ind >= list->length)
    {
        return -1;
    }

    node *temp = list->head;
    for (int i = 0; i < ind && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return -1;
    }

    int old = temp->element;
    temp->element = value;
    return old;
}
int delete_cur(linkedList *list)
{
    if (list->length == 0 || list->current == 0)
    {
        return -1;
    }

    node *temp = list->head;
    for (int i = 0; i < list->current - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return -1;
    }

    int deleted = temp->element;

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {

        list->head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    else
    {
        list->tail = temp->prev;
    }

    list->length--;

    if (list->current > list->length)
    {
        list->current = list->length;
    }

    free(temp);
    return deleted;
}

int trim(linkedList *list)
{
    if (list->length == 0)
    {
        return -1;
    }

    node *last = list->tail;
    int value = last->element;

    if (last->prev != NULL)
    {
        last->prev->next = NULL;
    }
    else
    {
        list->head = NULL;
    }

    list->tail = last->prev;
    free(last);
    list->length--;

    if (list->current > list->length)
    {
        list->current = list->length;
    }

    return value;
}

void reverse(linkedList *list)
{
    if (list->length <= 1)
        return;

    node *current = list->head;
    node *temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}