#include <neon_learn.h>

int main()
{
    printf("===========Neon Get & Set Instructions===========\n");
    int8x8_t vdata1 = {0, 10, 100, 127, -10, -100, -128, -128};
    int8x8_t vdata2 = {4, 9,  27,  3,   -9,  -100, -128, -1};
    int8x8_t vdata3 = {0, 1, 2, 3, 4, 5, 6, 7};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");
    print_neon<int8x8_t, int8_t>(vdata3, "vdata3:");

    // vmul
    int8x8_t vdata_0 = vmul_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_0, "vmul  :");

    // vmull
    int16x8_t vmul_1 = vmull_s8(vdata1, vdata2);
    print_neon<int16x8_t, int16_t>(vmul_1, "vmull :");

    // vmla
    int8x8_t vmla_0 = vmla_s8(vdata3, vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vmla_0, "vmla :");

    // vmlal
    int16x8_t vmla_1 = vmlal_s8(vmovl_s8(vdata3), vdata1, vdata2);
    print_neon<int16x8_t, int16_t>(vmla_1, "vmlal:");

    // vmls
    int8x8_t vmls_0 = vmls_s8(vdata3, vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vmls_0, "vmls :");

    // vmlsl
    int16x8_t vmls_1 = vmlsl_s8(vmovl_s8(vdata3), vdata1, vdata2);
    print_neon<int16x8_t, int16_t>(vmls_1, "vmlsl:");

    return 0;
}