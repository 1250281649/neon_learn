#include <neon_learn.h>

int main()
{
    printf("===========Neon Compare Instructions===========\n");
    int8x8_t vdata1 = {0, 1, 3, 7, 127, -1, -3, -128};
    int8x8_t vdata2 = {0, 2, 3, 8, -128, -2, -3, 127};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    int8x8_t vdata_0 = vmvn_s8(vdata1);
    print_neon<int8x8_t, int8_t>(vdata_0, "vmvn  :");

    int8x8_t vdata_1 = vand_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_1, "vand  :");

    int8x8_t vdata_2 = vorr_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_2, "vorr  :");

    int8x8_t vdata_3 = veor_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_3, "veor  :");

    int8x8_t vdata_4 = vcls_s8(vdata1);
    print_neon<int8x8_t, int8_t>(vdata_4, "vcls  :");

    int8x8_t shift_value_l = {1,1,1,1,1,1,1,1};
    int8x8_t shift_value_r = {-1,-1,-1,-1,-1,-1,-1,-1};
    int8x8_t vdata_5 = vshl_s8(vdata1, shift_value_l);
    print_neon<int8x8_t, int8_t>(vdata_5, "vshl  :");

    int8x8_t vdata_6 = vshl_s8(vdata1, shift_value_r);
    print_neon<int8x8_t, int8_t>(vdata_6, "vshr :");

    int8x8_t vdata_7 = vrshl_s8(vdata1, shift_value_r);
    print_neon<int8x8_t, int8_t>(vdata_7, "vrshl:");

    return 0;
}