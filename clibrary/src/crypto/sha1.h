/*
 * Copyright (c) 2000-2006 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 * 
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef CRYPTO_HASH_SHA1_H
#define CRYPTO_HASH_SHA1_H

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SHA1_DIGEST_LENGTH (20)

typedef struct crypto_hash_sha1_ctx_t {
    union {
        uint8_t  b8[20];
        uint32_t b32[5];  /* state (ABCDE) */
    } h;
    union {
        uint8_t  b8[8];
        uint32_t b32[2];
        uint64_t b64[1];  /* # of bits, modulo 2^64 (msb first) */
    } c;
    union {
        uint8_t  b8[64];
        uint32_t b32[16]; /* input buffer */
    } m;
    uint8_t  count;       /* unused; for compatibility only */
} SHA1_CTX;

/* For compatibility with the other SHA-1 implementation. */
#define SHA1Init(c)         crypto_hash_sha1_init(c)
#define SHA1Update(c, b, l) crypto_hash_sha1_update(c, b, l)
#define SHA1Final(b, c)     crypto_hash_sha1_result(c, b)

extern void SHA1Init(SHA1_CTX *);
extern void SHA1Update(SHA1_CTX *, const void *, size_t);
extern void SHA1Final(void *, SHA1_CTX *);

#ifdef  __cplusplus
}
#endif

#endif /* CRYPTO_HASH_SHA1_H */
