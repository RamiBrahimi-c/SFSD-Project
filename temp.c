#include "secondMem.h"
// #include "file.h"


int main() {

    FILE *ptr = fopen("allocation table/metadata" , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open file");
        return 1;
    }
    AllocationTable allocationTable ;

    readAllocationTable(&allocationTable) ;
    updateAllocationTable(&allocationTable , 0) ;
    printAllocationTable(allocationTable) ;


    fclose(ptr) ;
    return 0 ;
}