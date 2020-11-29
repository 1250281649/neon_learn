#include <neon_learn.h>

int main()
{
    printf("===========Neon ADD Instructions===========\n");
    int8x8_t vdata1 = {0, 10, 100, 127, -10, -100, -128, -128};
    int8x8_t vdata2 = {4, 9,  27,  3,   -9,  -100, -128, -1};
    int16x8_t vdata3 = {0, 10, 100, 127, -10, -100, -128, -128};
    int16x8_t vdata4 = {4, 9,  27,  3,   -9,  -100, -128, -1};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    // VADD2
    int8x8_t vdata_0 = vadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_0, "vadd  :");

    // vaddl
    int16x8_t vadd_1 = vaddl_s8(vdata1, vdata2);
    print_neon<int16x8_t, int16_t>(vadd_1, "vaddl :");

    // vaddw
    int16x8_t vadd_3 = vaddw_s8(vdata4, vdata1);
    print_neon<int16x8_t, int16_t>(vadd_3, "vaddw :");

    // vhadd
    int8x8_t vadd_4 = vhadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vadd_4, "vhadd :");

    // vrhadd
    int8x8_t vadd_5 = vrhadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vadd_5, "vrhadd:");

    // vqadd
    int8x8_t vadd_6 = vqadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vadd_6, "vqadd :");

    int8x8_t vadd_7 = vaddhn_s16(vdata3, vdata4);
    print_neon<int8x8_t, int8_t>(vadd_7, "vaddhn:");

    return 0;
}