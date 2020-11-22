#include <stdio.h>
#include <arm_neon.h>

int main()
{
    printf("===========Neon Types===========\n");
    printf("64 bit registers:\n");
    printf("int8x8_t size:%d\n", sizeof(int8x8_t));
    printf("int16x4_t size:%d\n", sizeof(int16x4_t));
    printf("int32x2_t size:%d\n", sizeof(int32x2_t));
    printf("int64x1_t size:%d\n", sizeof(int64x1_t));
    printf("float16x4_t size:%d\n", sizeof(float16x4_t));
    printf("float32x2_t size:%d\n", sizeof(float32x2_t));

    printf("\n128 bit registers:\n");
    printf("int8x16_t size:%d\n", sizeof(int8x16_t));
    printf("int16x8_t size:%d\n", sizeof(int16x8_t));
    printf("int32x4_t size:%d\n", sizeof(int32x4_t));
    printf("int64x2_t size:%d\n", sizeof(int64x2_t));
    printf("float16x8_t size:%d\n", sizeof(float16x8_t));
    printf("float32x4_t size:%d\n", sizeof(float32x4_t));

    return 0;
}