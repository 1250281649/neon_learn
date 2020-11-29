#include <neon_learn.h>

int main()
{
    printf("===========Neon Compare Instructions===========\n");
    int8x8_t vdata1 = {0, 10, 20, 127, -10, -100, -128, -128};
    int8x8_t vdata2 = {4, 9,  20,  3,   -9,  -100, -128, -1};

    print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
    print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

    uint8x8_t vdata_0 = vceq_s8(vdata1, vdata2);
    print_neon<uint8x8_t, uint8_t>(vdata_0, "vceq  :");

    uint8x8_t vdata_1 = vcge_s8(vdata1, vdata2);
    print_neon<uint8x8_t, uint8_t>(vdata_1, "vcge  :");

    uint8x8_t vdata_2 = vcgt_s8(vdata1, vdata2);
    print_neon<uint8x8_t, uint8_t>(vdata_2, "vcgt  :");

    uint8x8_t vdata_3 = vcle_s8(vdata1, vdata2);
    print_neon<uint8x8_t, uint8_t>(vdata_3, "vcle  :");

    uint8x8_t vdata_4 = vclt_s8(vdata1, vdata2);
    print_neon<uint8x8_t, uint8_t>(vdata_4, "vclt  :");

    return 0;
}