add_library(
    array
    array.c
    hash_table.c
)

add_library(
    blockchain
    block.c
    blockchain.c
    node.c
)

add_executable(
    node
    main.c
)

target_link_libraries(
    node
    blockchain
    crypto
    array
)
