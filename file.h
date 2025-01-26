#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE_FILENAME 20
#define MAX_SIZE_BLOCS_NUMBER 40
#define MAX_SIZE_RECORDS_NUMBER 20
#define MAX_PRODUCTS_NUMBER 100
#define MAX_SIZE_PRODUCT_NAME 30

#if defined(_WIN32)
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir)
#else
    #include <sys/stat.h>
    #include <errno.h>
    #define MKDIR(dir) mkdir(dir, 0755)
#endif



enum COLORS {
    BLACK , 
    RED ,
    GREEN ,
    YELLOW ,
    BLUE ,
    PURPLE ,
    CYAN ,
    WHITE
};
    typedef enum COLORS COLORS ;



typedef struct 
{
    int id ;
    int deletedLogically ;
    char name[MAX_SIZE_PRODUCT_NAME] ;
    double cost ;
}Product;


typedef struct 
{
    int nbBloc ;
    // Product product[MAX_SIZE_RECORDS_NUMBER] ; 
    Product *product ; 
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
    int totalNumberProducts ;
    char globalOrganizationMode ;
    char internOrganizationMode ;
}MetaData;





void createFile(  char [MAX_SIZE_FILENAME]) ;

int renameFile( char * , char *) ;
void renameFileMetaData( char * , char *) ;

int deleteFile( char *) ;
int deleteFileMetaData( char *) ;

void chargeFile( char *  , MetaData) ;
void searchRecord( char *, int , int *) ;
void insertRecord( char * ) ;

void defregmentate() ;

void deleteRecordLogically( char * , int ) ;

void deleteRecordPhysically( char * ,int  )  ;

void deleteRecordPhysicallyLinkedStructure(FILE* ,  MetaData * , int ) ;


void searchRecordLinkedStructure(FILE * ,  int , int * , MetaData) ;

void searchRecordContiguousStructure(FILE * ,  int , int * , MetaData) ;

void insertRecordContiguousStructure(FILE * , MetaData * , Product) ;

int insertRecordContigiousStructure2(FILE *ptr , MetaData *metadata , Product product) ;

void insertRecordLinkedStructure(FILE * , MetaData * , Product ) ;



void createFileBasedOnMetaDataContiguousStructure(FILE *,MetaData ) ;

void displayFileContent(char * ) ;


void cleanString(char []) ;

void printMetadata(char *) ;




void printErrorMessage(char *, COLORS ) ;
        

// additional 

int insertSorted(Product [], int , Product , int ) ;

void setFullPathtoSecondMemFolder(char * ) ;
void setFullPathtoMetadataFolder(char * ) ;

int calculateFileLength(FILE *) ;
void checkifCharUppercase(char *c) ;
int deleteRecordfromArray(Product * , int  ,int ) ;