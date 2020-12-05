#include "utils.h"

int WriteBinaryFile(const char* path, void* data, int len)
{
	FILE* fp;

	fp = fopen(path, "wb+");
	if (fp == NULL)
	{
		printf("Can't open %s\n", path);
		return -1;
	}

	fseek(fp, SEEK_SET, 0);
	fwrite(data, 1, len, fp);
	fclose(fp);

    return 0;
}

int ReadBinaryFile(const char* path, void** data, int *len)
{
    FILE* fp;

	fp = fopen(path, "rb");
	if (fp == NULL)
	{
		printf("Can't open %s\n", path);
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
    int real_size = ftell(fp);
    *len = real_size;
	fseek(fp, 0L, SEEK_SET);

    if(*data == NULL)
    {
        *data = malloc(real_size);
        if(*data == NULL)
        {
            perror("Memory Not Enough\n");
            fclose(fp);
            return -1;
        }
    }

    fread(*data, 1, real_size, fp);

	fclose(fp);

    return 0;
}

std::string GetDataPath(const char* path)
{
	char s[256];
	snprintf(s, sizeof(s), "%s/%s", TEST_DATA_PATH, path);

	return std::string(s);
}


uint64_t GetCurrentTimestap() {
  struct timeval tv {};
  int ret = gettimeofday(&tv, nullptr);
  auto total_use_time = tv.tv_usec + tv.tv_sec * 1000000;  // 1000000: seconds to microseconds
  return static_cast<uint64_t>(total_use_time);
}
