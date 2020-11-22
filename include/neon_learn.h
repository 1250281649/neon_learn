#include <stdio.h>
#include <arm_neon.h>

template <typename T>
void print_neon_valude(T value)
{
    int data_size = sizeof(T);
    uint8_t *p = (uint8_t*)(&value);
    for(int i=0; i<data_size; i++)
    {
        printf("%d\t", *p++);
    }
    printf("\n");
}

template <typename T>
void print_array(T *data, int len)
{
    uint8_t *p = (uint8_t*)(data);
    for(int i=0; i<len; i++)
    {
        printf("%d\t", *p++);
    }
    printf("\n");
}