#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

#define TEST_DATA_PATH "/sdcard/blackbox/testdata"

#define TIMESTAMP_START(stage) uint64_t startUsec_##stage = GetCurrentTimestap()

#define TIMESTAMP_END(stage, stage_name)                        \
  do {                                                          \
    uint64_t endUsec_##stage = GetCurrentTimestap();            \
    printf("The time cost of %s is [%llu] us.\n", (stage_name), \
           (endUsec_##stage - startUsec_##stage));              \
  } while (0);

#define TIME_COST(stament, stage_name) \
    do {                                                        \
        uint64_t start, end, avg = 0, min_time = UINT64_MAX;    \
        for(int i=0; i<100; i++)                                \
        {                                                       \
            start = GetCurrentTimestap();                       \
            stament;                                            \
            end = GetCurrentTimestap();                         \
            uint64_t temp = end-start;                          \
            if(temp < min_time) min_time = temp;                \
            avg += temp;                                        \
        }                                                       \
        printf("[%s] time cost sumary:\n", stage_name);           \
        printf("  --average cost:%lld\n", avg/100);               \
        printf("  --min cost:%lld\n", min_time);                  \
    } while (0);

int WriteBinaryFile(const char* path, void* data, int len);

int ReadBinaryFile(const char* path, void** data, int *len);

std::string GetDataPath(const char* path);

uint64_t GetCurrentTimestap();