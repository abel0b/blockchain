#ifndef BLOCKCHAIN_H
#ifndef BLOCKCHAIN_H

struct Blockchain {
    struct Array * blocks;
};

struct Blockchain * blockchain_make();
void blockchain_destroy();

#endif
