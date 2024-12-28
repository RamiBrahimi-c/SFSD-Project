#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_FILENAME 20
#define MAX_SIZE_BLOCS_NUMBER 40
#define MAX_SIZE_RECORDS_NUMBER 20


#if defined(_WIN32)
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <errno.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif






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
    Product product[MAX_SIZE_RECORDS_NUMBER] ; 
}BlocContiguousStructure;


typedef struct BlocLinkedStructure 
{
    int nbBloc ;
    Product product[MAX_SIZE_RECORDS_NUMBER] ; 
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



const char secondMemFolder[] = "./secondary memory/" ; 
const char metaDataFolder[] = "./meta data/" ; 
char fullPath[40] ;
char fullPath2[40] ;

BlocContiguousStructure bufferContiguousStruct ;
BlocLinkedStructure bufferLinkedStruct ;


void createFile() ;
void renameFile(const char * ,const char *) ;
void deleteFile(const char *) ;
void chargeFile(const char *  ,const MetaData) ;
void searchRecord(const char *,const int , int *) ;
void insertRecord(const char * ) ;

void defregmentate() ;

void deleteRecordLogically(const char * , int ) ;

void deleteRecordPhysicallyLinkedStructure(FILE* ,  MetaData * , int ) ;


void searchRecordLinkedStructure(FILE * , const int , int * , MetaData) ;

void searchRecordContiguousStructure(FILE * , const int , int * , MetaData) ;

void insertRecordContiguousStructure(FILE * , MetaData * , Product) ;
void insertRecordLinkedStructure(FILE * , MetaData * , Product ) ;

// additional 

int insertSorted(Product [], int , Product , int ) ;

void setFullPathtoSecondMemFolder(char * ) ;
void setFullPathtoMetadataFolder(char * ) ;

int calculateFileLength(FILE *) ;
void checkifCharUppercase(char *c) ;
