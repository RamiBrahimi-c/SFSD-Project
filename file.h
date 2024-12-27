#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_SIZE_FILENAME 20

typedef struct 
{
    int id ;
    int deletedLogically ;
    char name[MAX_SIZE_FILENAME] ;
    double cost ;
}Product;


typedef struct 
{
    int nbBloc ;
    Product product[] ; 
}BlocContiguousStructure;


typedef struct BlocLinkedStructure 
{
    int nbBloc ;
    Product *product ; 
    int next ;
}BlocLinkedStructure;

typedef struct 
{
    char fileName[MAX_SIZE_FILENAME] ;
    int blocsNumber ;
    int recordsNumber ;
    int firstBlocAddress ;
    char globalOrganizationMode ;
    char internOrganizationMode ;
}MetaData;



void createFile() ;
void renameFile(const char * ,const char *) ;
void deleteFile(const char *) ;
void chargeFile(const char *  ,const MetaData) ;
void searchRecord(const char *,const int ) ;
void insertRecord(const char * ) ;
void defregmentate() ;

// additional 

void checkifCharUppercase(char *c) {
    *c = (*c >= 65 && *c <= 90) ? (*c)+32 : *c ;
}
