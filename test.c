// #include "file.h"

#include <stdio.h>

#include <string.h>
#include <errno.h>


#if defined(_WIN32)
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <sys/types.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif


void calculateLength(FILE *ptr) {
    rewind(ptr);
    fseek(ptr , 0 , SEEK_END ) ;
    int length = ftell(ptr) / sizeof(int) ;
    printf("length : %d \n" , length) ;

}



void add(int a , int b ) {
    printf("%d+%d=%d\n", a , b , a+b) ;
}

void sub(int a , int b ) {
    printf("%d-%d=%d\n", a , b , a-b) ;
}


#include <stdlib.h>

int main() {
    FILE *ptr = fopen("haha" , "rb+") ;

    int arr[10]  , length = sizeof(arr)/sizeof(arr[0]) ;
#if 1
    int *ptri ;
    printf("size : %ld length %d \n" , sizeof(arr) , length) ;

    printf("size : %ld length %d \n" , sizeof(ptri) , length) ;
    ptri = malloc(sizeof(int)*length);
   // fwrite(arr , sizeof(arr) , 1 , ptr ) ; 
    printf("size : %ld length %d \n" , sizeof(ptri) , length) ;
    fread(arr , sizeof(arr) , 1 , ptr) ;

    printf("size : %ld length %d \n" , sizeof(ptri) , length) ;
    for (int i = 0; i < 4; i++)
    {
        printf(" %d " , arr[i]) ;
    }printf("\n") ;
 #else  
    fwrite(arr , sizeof(arr) , 1 , ptr) ;
 #endif   

    fclose(ptr);



    return 0;
}


/*
    const char *dirname = "my_directory";

    if (MKDIR(dirname) == 0) {
        printf("Directory created successfully\n");
    } else {
        perror("Error creating directory");
    }

*/





/*     #if defined(_WIN32) || defined(_WIN64)
        printf("Running on Windows\n");
    #elif defined(__linux__)
        printf("Running on Linux\n");
    #elif defined(__APPLE__) && defined(__MACH__)
        printf("Running on macOS\n");
    #elif defined(__unix__)
        printf("Running on Unix\n");
    #else
        printf("Unknown operating system\n");
    #endif
 */