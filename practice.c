#include <stdio.h>

int main()
{
    int sum = 0;
    int count = 30;
    while (count <= 30)
    {
        sum = sum + count;
        count++;
        printf( "Sum %d", sum );
    }
}