#include <stdio.h>
#include <stdlib.h>

typedef struct Bloc {
    int length;
    int *arr;
} Bloc;

void fill(FILE *ptr) {
    Bloc buffer;

    buffer.length = 4;
    buffer.arr = malloc(sizeof(int) * buffer.length);

    buffer.arr[0] = 1;
    buffer.arr[1] = 2;
    buffer.arr[2] = 3;
    buffer.arr[3] = 4;

    // Write the length first
    fwrite(&buffer.length, sizeof(buffer.length), 1, ptr);
    // Write the array contents
    fwrite(buffer.arr, sizeof(int), buffer.length, ptr);

    free(buffer.arr); // Free the allocated memory
}

void show(FILE *ptr) {
    Bloc buffer;

    // Read the length first
    fread(&buffer.length, sizeof(buffer.length), 1, ptr);
    buffer.arr = malloc(sizeof(int) * buffer.length);

    // Read the array contents
    fread(buffer.arr, sizeof(int), buffer.length, ptr);

    for (int i = 0; i < buffer.length; i++) {
        printf(" %d ", buffer.arr[i]);
    }
    printf("\n");

    free(buffer.arr); // Free the allocated memory
}

int main() {
    FILE *ptr = fopen("math", "wb+"); // Open file in write/read mode
    if (ptr == NULL) {
        printf("Can't open the file\n");
        return 1;
    }

    fill(ptr);

    rewind(ptr); // Reset the file pointer to the beginning

    show(ptr);

    fclose(ptr);
    return 0;
}
