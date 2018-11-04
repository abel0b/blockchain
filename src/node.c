#include "blockchain/node.h"
#include "openssl/sha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node * node_make() {
    struct Node * node = malloc(sizeof(struct Node));
    node->blockchain = blockchain_make();
    return node;
}

int node_run(struct Node * node) {
    blockchain_add_block(node->blockchain, NULL, 0);
    blockchain_add_block(node->blockchain, NULL, 0);
    blockchain_add_block(node->blockchain, NULL, 0);

    blockchain_debug(node->blockchain, stdout);
    node_destroy(node);
    return EXIT_SUCCESS;
}

void node_destroy(struct Node * node) {
    blockchain_destroy(node->blockchain);
    free(node);
}