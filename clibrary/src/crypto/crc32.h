#ifndef CRYPTO_HASH_CRC32_H
#define CRYPTO_HASH_CRC32_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CRC32(c, b, l) crypto_hash_crc32(c, b, l)

uint32_t CRC32(uint32_t crc, const void *buf, size_t size);

#ifdef  __cplusplus
}
#endif

#endif
