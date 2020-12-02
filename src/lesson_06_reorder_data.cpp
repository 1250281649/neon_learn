#include <neon_learn.h>

int main()
{
    printf("===========Neon Reorder Instructions===========\n");
    int8_t  data8[16] = TEST_DATA;
    {
        int8x8_t s8_1 = vld1_s8(data8);
        print_neon<int8x8_t, int8_t>(s8_1, "vdata1:");
        int8x8_t s8_2 = vld1_s8(&data8[8]);
        print_neon<int8x8_t, int8_t>(s8_2, "vdata2:");

        int8x8_t s8_reorder = vext_s8(s8_1, s8_2, 3);
        print_neon<int8x8_t, int8_t>(s8_reorder, "vdata3:");
    }

    {
        printf("\ntest vtbl instruction\n");
        int8x8_t s8_1 = vld1_s8(data8);
        print_neon<int8x8_t, int8_t>(s8_1, "vdata:");
        int8x8_t tbl = {1,1,2,3,3,7,-1,9};
        int8x8_t s8_2 = vtbl1_s8(s8_1, tbl);
        print_neon<int8x8_t, int8_t>(tbl, "index:");
        print_neon<int8x8_t, int8_t>(s8_2, "tbl 1:");

        int8x8x2_t s8_3 = vld2_s8(data8);
        print_neon<int8x8x2_t, int8_t>(s8_3, "vdata:");
        int8x8_t tbl_2 = {1,1,2,3,3,7,-1,9};
        int8x8_t s8_4 = vtbl2_s8(s8_3, tbl_2);
        print_neon<int8x8_t, int8_t>(tbl_2, "index:");
        print_neon<int8x8_t, int8_t>(s8_4, "tbl 2:");
    }

    {
        printf("\ntest vrev instruction\n");
        int8x8_t vdata = vld1_s8(data8);
        print_neon<int8x8_t, int8_t>(vdata, "vdata:");
        int8x8_t rev_1 = vrev16_s8(vdata);
        print_neon<int8x8_t, int8_t>(rev_1, "rev_1:");

        int8x8_t rev_2 = vrev32_s8(vdata);
        print_neon<int8x8_t, int8_t>(rev_2, "rev_2:");

        int8x8_t rev_3 = vrev64_s8(vdata);
        print_neon<int8x8_t, int8_t>(rev_3, "rev_3:");
    }

    {
        printf("\ntest vrev instruction\n");
        int8x8_t vdata1 = {0,1,2,3,4,5,6,7};
        int8x8_t vdata2 = {8,9,10,11,12,13,14,15};

        print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
        print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

        int8x8x2_t trn_1 = vtrn_s8(vdata1, vdata2);
        print_neon<int8x8x2_t, int8_t>(trn_1, "trn_1:");
    }

    {
        printf("\ntest vzip instruction\n");
        int8x8_t vdata1 = {0,1,2,3,4,5,6,7};
        int8x8_t vdata2 = {8,9,10,11,12,13,14,15};

        print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
        print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

        int8x8x2_t zip_1 = vzip_s8(vdata1, vdata2);
        print_neon<int8x8x2_t, int8_t>(zip_1, "zip_1:");
    }

    {
        printf("\ntest vuzp instruction\n");
        int8x8_t vdata1 = {0,1,2,3,4,5,6,7};
        int8x8_t vdata2 = {8,9,10,11,12,13,14,15};

        print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
        print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");

        int8x8x2_t uzp_1 = vuzp_s8(vdata1, vdata2);
        print_neon<int8x8x2_t, int8_t>(uzp_1, "uzp_1:");
    }

    {
        printf("\ntest vbsl instruction\n");
        int8x8_t vdata1 = {0,1,2,3,4,5,6,7};
        int8x8_t vdata2 = {8,9,10,11,12,13,14,15};
        uint8x8_t vmask = {0, 3, 255, 8, 7, 127, 255, 10};

        print_neon<int8x8_t, int8_t>(vdata1, "vdata1:");
        print_neon<int8x8_t, int8_t>(vdata2, "vdata2:");
        print_neon<uint8x8_t, uint8_t>(vmask, "vmask :");

        int8x8_t zbsl_1 = vbsl_s8(vmask, vdata1, vdata2);
        print_neon<int8x8_t, int8_t>(zbsl_1, "zbsl_1:");
    }

    return 0;
}