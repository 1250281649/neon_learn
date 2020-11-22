#include <stdio.h>
#include <arm_neon.h>

template <typename T>
void print_neon_valude(T value)
{
    int data_size = sizeof(T);
    int8_t *p = (int8_t*)(&value);
    for(int i=0; i<data_size; i++)
    {
        printf("%d\t", *p);
    }
    printf("\n");
}
