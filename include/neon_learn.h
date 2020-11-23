#include <stdio.h>
#include <arm_neon.h>

template <typename T>
void print_neon_value_hex(T value)
{
    int data_size = sizeof(T);
    uint8_t *p = (uint8_t*)(&value);
    for(int i=0; i<data_size; i++)
    {
        printf("%d\t", *p++);
    }
    printf("\n");
}

template <typename T1, typename T2>
void print_neon(T1 value)
{
    int data_size = sizeof(T1) / sizeof(T2);
    T2 *p = (T2*)(&value);
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