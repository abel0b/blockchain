#include <stdio.h>
#include "array/array.h"
#include "inut/assert.h"
#include "inut/test.h"
#include "blockchain/block.h"
#include "gcrypt.h"
#include <stdint.h>

typedef struct TestResult test;

test test_initial_capacity () {
    return pass ();
}

void
test_array() {
    test_suite(TEST_ROOT, "block");
    test_case("block", "test", test_initial_capacity);
}

int main() {
    


    struct Block * block = block_make(NULL, NULL, 0);
    struct Block * blockB = block_make(block, NULL, 0);
    block_debug(block, stdout);
    block_debug(blockB, stdout);

    test_array();
    return test_run();
}
