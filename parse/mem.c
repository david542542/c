#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_mem_block(size_t bytes)
{
    char *mem_block = malloc(bytes);
    if (!mem_block) {
        perror("Looks like there was an error");
        exit(EXIT_FAILURE);
    }

    // write a one-byte char value at address0
    *mem_block = 'a';

    // write a four-byte integer value starting at the 4th byte (index 3) or the memory block
    /* int *mem_block_for_int = (int*) mem_block; */
    /* *(int*)(mem_block_for_int + 1) = 4444; */

    *(int*)(mem_block+4) = 4444;    // can cast a pointer to a different type to write to --> notice the form is * (ptr type) (memory) = (value) --> *(long*) ptr=19929299191L;

    return mem_block;

}

int static_store = 30;
const char* string_literal = "String Literal";
int main(void)
{
    int auto_store=40;
    char auto_string[] = "Auto char array";
    int *pi = malloc(sizeof(int));
    *pi = 35;
    char* pcl = malloc(strlen("Dynamic String")+1);
    strcpy(pcl, "Dynamic String");

    printf("Static duration external linkage: %10d at %p\n", static_store, &static_store);
    printf("Auto   duration no linkage        %10d at %p\n", auto_store, &auto_store);
    printf("String literal (static)           %10d at %p\n", 0,&string_literal);    // takes up the memory location right after the static store -- globals in a very similar memory location
    return 0;


    size_t k;   // 8 bytes here
    printf("%lu\n", sizeof k);
    char* mem_block;
    for (int i=0; i < 10; i++)
        mem_block = get_mem_block(1000000LLU);
    /* if (!mem_block) return 1; */
    /* printf("mem_block starts at: %p. Char value @0: %c. Int value @3: %d\n", mem_block, *mem_block, *(int*) (mem_block+4)); */
    /* free(mem_block); */
    /* free(mem_block); */
    /* free(mem_block); */
    /* printf("mem_block starts at: %p. Char value @0: %c. Int value @3: %d\n", mem_block, *mem_block, *(int*) (mem_block+4)); */
    return 0;
}


