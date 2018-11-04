#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <openssl/sha.h>
#include <stdint.h>

struct Block {
    uint64_t id;
    uint64_t timestamp;
    uint8_t prevHash[SHA256_DIGEST_LENGTH];
    uint16_t data_length;
    void * data;
};

struct Block * block_make(struct Block * prev, unsigned char * data, int data_length);

void block_hash(struct Block * block, unsigned char * dest);

void block_debug(struct Block * block, FILE * stream);

void block_destroy(struct Block * block);

#endif
