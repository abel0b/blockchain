#ifndef NODE_H
#define NODE_H

#include "blockchain/blockchain.h"

struct Node {
    struct Blockchain * blockchain;
};

struct Node * node_make();

int node_run(struct Node * node);

void node_destroy(struct Node * node);

#endif