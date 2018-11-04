#include "blockchain/block.h"
#include "openssl/sha.h"
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

struct Block * block_make(struct Block * prev, unsigned char * data, int data_length) {
    struct Block * block = malloc(sizeof(struct Block));
    memset(block->prevHash, 0, SHA256_DIGEST_LENGTH);
    if (prev == NULL) {
        block->id = 0;
    }
    else {
        block->id = prev->id + 1;
        block_hash(prev, block->prevHash);
    }
    block->timestamp = time(NULL);
    block->data = data;
    block->data_length = data_length;
    return block;
}

void block_hash(struct Block * block, unsigned char * dest) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, &block->id, sizeof(uint64_t));
    SHA256_Update(&sha256, &block->timestamp, sizeof(uint64_t));
    SHA256_Update(&sha256, &block->prevHash, sizeof(uint8_t) * SHA256_DIGEST_LENGTH);
    SHA256_Update(&sha256, &block->data_length, sizeof(uint16_t));
    SHA256_Update(&sha256, &block->data, block->data_length);
    SHA256_Final(dest, &sha256);
}

void block_debug(struct Block * block, FILE * stream) {
    fprintf(stream, " Block id: %lu\n", block->id);
    fprintf(stream, "Timestamp: %s", ctime(&block->timestamp));
    fprintf(stream, " PrevHash: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
       fprintf(stream, "%02x", block->prevHash[i]);
    }
    fprintf(stream, "\n");
    unsigned char hash_buffer[SHA256_DIGEST_LENGTH];
    fprintf(stream, "     Hash: ");
    block_hash(block, hash_buffer);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
       fprintf(stream, "%02x", hash_buffer[i]);
    }
    fprintf(stream, "\n");

    fprintf(stream, "----------------------------------------------------------------------------\n");
}

void block_destroy(struct Block * block) {
    free(block);
}