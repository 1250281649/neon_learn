#include <gtest/gtest.h>
#include <neon_learn.h>
#include "tools/utils.h"

TEST(Assember, basic)
{
    asm("mov r0, r0");
    
    /* Rotating bits example */
    int y = 0;
    int x = 0xA5;
    asm("mov %[result], %[value], ror #1" : [result] "=r" (y) : [value] "r" (x));
    ASSERT_EQ(y, 0x80000052);
}

TEST(Assember, vadd_reg)
{
    int8x8_t vdata1 = {0, 10, 100, 127, -10, -100, -128, -128};
    int8x8_t vdata2 = {4, 9,  27,  3,   -9,  -100, -128, -1};
    int8x8_t result = {4, 19, 127, -126, -19, 56, 0, 127};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    // VADD2
    int8x8_t vdata_0 = vadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_0, "vadd  :");

    asm volatile(
        "vadd.s8 %[vdata1], %[vdata2], %[vdata_0]"
        : [vdata_0] "+X" (vdata_0)
        : [vdata1] "X" (vdata1), [vdata2] "X" (vdata1)
    );
    ASSERT_EQ(IsEqual(vdata_0, result), true);
}

void vadd_int8(int8_t *A, int8_t *B, int8_t*C, int32_t len)
{
    int8x8_t va;
    int8x8_t vb;
    int8x8_t vc;
    for(int i=0; i<len; i+=8)
    {
        va = vld1_s8(&A[i]);
        vb = vld1_s8(&B[i]);
        vc = vqadd_s8(va, vb);
        vst1_s8(&C[i], vc);
    }
}

void vadd_int8_asm(int8_t *A, int8_t *B, int8_t*C, int32_t len)
{
    int8x8_t va;
    int8x8_t vb;
    int8x8_t vc;
    for(int i=0; i<len; i+=8)
    {
        asm(
            "adds r6, %[A], %[i]\n"
            "vld1.s8 %[va], [r6]\n"
            "adds r7, %[B], %[i]\n"
            "vld1.s8 %[vb], [r7]\n"
            "vqadd.s8 %[vc], %[vb], %[va]"
            : [va] "+X" (va), [vb] "+X" (vb), [vc] "+X" (vc)
            : [i] "r" (i), [A] "r" (A), [B] "r" (B)
        );
        vst1_s8(&C[i], vc);
    }
}

void add_int8(int8_t *A, int8_t *B, int8_t*C, int32_t len)
{
    for(int i=0; i<len; i++)
    {
        int t = (A[i]+B[i]);
        C[i] = t > 127 ? 127 : (t < -128 ? -128 : t);
    }
}

TEST(Assember, vadd_func)
{
    const int32_t length = 65536;
    int8_t* A = (int8_t*)malloc(sizeof(int8_t) * length);
    int8_t* B = (int8_t*)malloc(sizeof(int8_t) * length);
    int8_t* C = (int8_t*)malloc(sizeof(int8_t) * length);
    int8_t* R = (int8_t*)malloc(sizeof(int8_t) * length);

    for(int i=0; i<length; i++)
    {
        A[i] = rand() % 128;
        B[i] = rand() % 128;
    }

    TIME_COST(vadd_int8(A, B, C, length), "neon c:");
    TIME_COST(vadd_int8_asm(A, B, R, length), "neon asm:");

    EXPECT_EQ(memcmp(C, R, length), 0);

    free(A);
    free(B);
    free(C);
    free(R);
}