#include "blockchain/node.h"

int main(int argc, char * argv[]) {
    struct Node * node = node_make();
    return node_run(node);
}