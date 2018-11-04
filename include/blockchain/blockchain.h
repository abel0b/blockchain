#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "array/array.h"
#include <stdio.h>
#include "blockchain/block.h"

struct Blockchain {
    struct Array * blocks;
};

struct Blockchain * blockchain_make();

void blockchain_destroy(struct Blockchain * Blockchain);

void blockchain_add_block(struct Blockchain * blockchain, void * data, int data_length);

void blockchain_debug(struct Blockchain * blockchain, FILE * stream);

#endif
