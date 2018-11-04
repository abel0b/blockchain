#include "blockchain/blockchain.h"
#include "blockchain/block.h"
#include "array/array.h"
#include <stdlib.h>

struct Blockchain * blockchain_make() {
    struct Blockchain * blockchain = malloc(sizeof(struct Blockchain));
    blockchain->blocks = array_make();
    return blockchain;
}

void blockchain_add_block(struct Blockchain * blockchain, void * data, int data_length) {
    struct Block * prev_block;
    if (array_length(blockchain->blocks) > 0) {
        prev_block = array_last(blockchain->blocks);
    }
    else {
        prev_block = NULL;
    }

    struct Block * block = block_make(prev_block, data, data_length);
    array_push(blockchain->blocks, block);
}

void blockchain_debug(struct Blockchain * blockchain, FILE * stream) {
    struct ArrayIterator it = array_it_make(blockchain->blocks);
    while(!array_it_end(it)) {
        block_debug(array_it_get(it), stream);
        it = array_it_next(it);
    }
}

void blockchain_destroy(struct Blockchain * blockchain) {
    struct ArrayIterator it = array_it_make(blockchain->blocks);
    while(!array_it_end(it)) {
        block_destroy(array_it_get(it));
        it = array_it_next(it);
    }
    array_destroy(blockchain->blocks);
    free(blockchain);
}