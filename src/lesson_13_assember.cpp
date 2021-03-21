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

TEST(Assember, vadd)
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
