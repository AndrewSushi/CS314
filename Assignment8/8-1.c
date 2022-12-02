#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 2

struct Line {
    unsigned char data[BLOCK_SIZE]; // 2-byte blocks
    unsigned int tag; // Assume tag is at most 32 bits
    unsigned char valid; // valid bit
};

struct Cache {
    struct Line *lines;
    int numLines;
};

unsigned int getOffset(unsigned int address) {
    return address & 0x1; // 2-byte blocks, so 1 offset bit
}

unsigned int getSet(unsigned int address) {
    return (address >> 1) & 0x7; // 2-byte blocks; 8 sets so 3 set bits
}

unsigned int getTag(unsigned int address) {
    return address >> 4; // total of 4 bits for offset and set
}

struct Cache* mallocCache(int numLines) {
    // TODO - malloc a pointer to a struct Cache, malloc a pointer to an array
    // of struct Line instances (array length is numLines). Also initialize
    // valid to 0 for each struct Line. Return the struct Cache pointer.
    struct Cache *c = (struct Cache *)malloc(sizeof(struct Cache));
    c->numLines = numLines;
    struct Line *l = (struct Line *)malloc(sizeof(struct Line) * numLines);
    c->lines = l;
    for(int i = 0; i < numLines; i++){
        c->lines[i].valid = 0;
    }
    return c;
}

void freeCache(struct Cache *cache) {
    free(cache->lines);
    free(cache);
}

void printLine(struct Line *line, unsigned int set) {
    unsigned char *data = line->data;
    printf("set: %x - tag: %x - valid: %u - data: %.2x %.2x\n",
    set, line->tag, line->valid, data[0], data[1]);
}

void printCache(struct Cache *cache) {
    // TODO - print all valid lines in the cache.
    for(int i = 0; i < cache->numLines; i++){
        struct Line *line = &cache->lines[i];
        if(line->valid){
            printLine(line, i);
        }
    }
}

void readValue(struct Cache *cache, unsigned int address) {
    // TODO - check the cache for a cached byte at the specified address.
    // If found, indicate a hit and print the byte. If not found, indicate
    // a miss due to either an invalid line (cold miss) or a tag mismatch
    // (conflict miss).
    unsigned int s = getSet(address);
    unsigned int t = getTag(address);
    struct Line *line = &cache->lines[s];
    printf("Looking for set: %d - tag: %d\n", s, t);
    if (line->valid && line->tag == t) {
        unsigned char *data = line->data;
        printf("Found set: ");
        printLine(line, s);
        printf("hit!\n");
    }else{
        printf("no valid line found - miss!\n");
    }
}

void writeValue(struct Cache *cache, unsigned int address, unsigned char *newData) {
    unsigned int s = getSet(address);
    unsigned int t = getTag(address);
    struct Line *line = &cache->lines[s];
    if (line->valid && line->tag != t) {
        unsigned char *data = line->data;
        printf("evicting line - ");
        printLine(line, s);
    }
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        line->data[i] = newData[i];
    }
    line->tag = t;
    line->valid = 1;
    
    printf("wrote set: ");
    printLine(line, s);
}

unsigned int readUnsignedIntFromHex() {
    char buffer[10];
    char *p = NULL;
    unsigned int n;
    while (1) {
        fgets(buffer, sizeof(buffer), stdin);
        n = strtoul(buffer, &p, 16);
        if (buffer != p) {
            break;
        }
        printf("Invalid input - try again: ");
    }
    return n;
}

int main() {
    struct Cache *cache = mallocCache(8);

    char buffer[10];
    char c;
    do {
        printf("Enter 'r' for read, 'w' for write, 'p' to print, 'q' to quit: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        c = buffer[0];
        if (c == 'r') {
            printf("Enter 32-bit unsigned hex address: ");
            unsigned int a = readUnsignedIntFromHex();
            readValue(cache, a);
        } else if (c == 'w') {
            printf("Enter 32-bit unsigned hex address: ");
            unsigned int a = readUnsignedIntFromHex();
            
            printf("Enter 32-bit unsigned hex value: ");
            unsigned int v = readUnsignedIntFromHex();
            unsigned char *data = (unsigned char *)&v;
            writeValue(cache, a, data);
        } else if (c == 'p') {
            printCache(cache);
        }
    } while (c != 'q');

    freeCache(cache);
}