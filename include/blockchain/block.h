#ifndef BLOCK_H
#define BLOCK_H

#define HASH_SIZE 256;

struct Block {
    unsigned int id;
    unsigned int nonce;
    char hash[HASH_SIZE];
    char * data;
    int data_size;
};

struct Block * block_make();
void block_destroy();

#endif
