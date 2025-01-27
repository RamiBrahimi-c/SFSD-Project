#pragma once 

#include "file.h"



#define MAX_FILES 7

typedef struct 
{
    int num ;
    int used ;
    char fileName[MAX_SIZE_FILENAME] ;
}file;


typedef struct 
{
    int totalNumberOfBlocs ;
   // int blockageFactor ;
    int totalNumberOfUsedBlocs ;
    file files[MAX_FILES] ;
    int length ;
}AllocationTable;



void discInisilize(AllocationTable *allocationTable) ;
void updateAllocationTable(AllocationTable *allocationTable , int mode , char *) ;
void compactage() ;
void emptySecondaryMemory() ;
void stockageSpaceManagement() ;

void formatAllocationTable(AllocationTable *allocationTable) ;


void printAllocationTable(AllocationTable allocationTable) ;

void readAllocationTable(AllocationTable *allocationTable) ;

void writeAllocationTable(AllocationTable allocationTable) ;



int isTherethisFile(AllocationTable , char []) ;






AllocationTable getAllocationTable() ;

int remove_directory_contents(const char *path)  ;