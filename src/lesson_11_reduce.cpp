#include <neon_learn.h>

int main()
{
    printf("===========Neon Compare Instructions===========\n");
    int8x8_t vdata1 = {0, 1, 2, 3, 4, 5, 6, 7};
    int8x8_t vdata2 = {8, 9, 10, 11, 12, 13, 14, 15};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    int8x8_t vdata_0 = vpadd_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_0, "vpadd :");

    int8x8_t vdata_1 = vpmax_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_1, "vpmax :");

    int8x8_t vdata_2 = vpmin_s8(vdata1, vdata2);
    print_neon<int8x8_t, int8_t>(vdata_2, "vpmin :");

    return 0;
}