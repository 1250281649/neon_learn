#include <neon_learn.h>

int main()
{
    printf("===========Neon Math Instructions===========\n");
    int8x8_t vdata1 = {0, 10, 100, 127, -10, -100, -128, -128};
    int8x8_t vdata2 = {4, 9,  27,  3,   -9,  -100, -128, -1};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    int8x8_t vdata_0 = vabs_s8(vdata1);  // vabs
    print_neon<int8x8_t, int8_t>(vdata_0, "vabs  :");

    int8x8_t vdata_1 = vneg_s8(vdata1);  // vneg
    print_neon<int8x8_t, int8_t>(vdata_1, "vneg  :");

    int8x8_t vdata_2 = vmax_s8(vdata1, vdata2);  // vmax
    print_neon<int8x8_t, int8_t>(vdata_2, "vmax  :");

    int8x8_t vdata_3 = vmin_s8(vdata1, vdata2);  // vmin
    print_neon<int8x8_t, int8_t>(vdata_3, "vmin  :");

    return 0;
}