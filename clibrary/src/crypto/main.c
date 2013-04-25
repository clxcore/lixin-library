#include "crc32.h"
#include "md5.h"
#include "sha1.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    char src[] = "hello";
    MD5_CTX md5_ctx;
    SHA1_CTX sha1_ctx;
    unsigned char md5_result[MD5_DIGEST_LENGTH] = {0};
    unsigned char sha1_result[SHA1_DIGEST_LENGTH] = {0};
    unsigned i;

    MD5Init(&md5_ctx);
    MD5Update(&md5_ctx, src, sizeof(src)-1);
    MD5Final(md5_result, &md5_ctx);
    printf("MD5:  ");
    for (i = 0; i < sizeof(md5_result); ++i) {
        printf("%02x", md5_result[i]);
    }
    printf("\n");

    SHA1Init(&sha1_ctx);
    SHA1Update(&sha1_ctx, src, sizeof(src)-1);
    SHA1Final(sha1_result, &sha1_ctx);
    printf("SHA1: ");
    for (i = 0; i < sizeof(sha1_result); ++i) {
        printf("%02x", sha1_result[i]);
    }
    printf("\n");

    uint32_t crc = 0;
    crc = CRC32(0, src, sizeof(src)-1);
    printf("CRC32:%08x\n", crc);
    return 0;
}
