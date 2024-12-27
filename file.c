#include "file.h"

int main() {

    createFile() ;

    return 0 ;
}

void createFile() {
    
    char fileName[MAX_SIZE_FILENAME] ;
    int recordsNumber ;
    char organizationMode ;

    MetaData metaData ;

    printf("enter file name : ");
    fgets(metaData.fileName , sizeof(metaData.fileName) , stdin) ;
        metaData.fileName[strcspn(metaData.fileName, "\n")] = '\0'; // Remove newline

    printf("enter records number : ");
    scanf("%d" , &metaData.recordsNumber) ;
    do {
        printf("enter global organization mode linked or contiguous (l/c): ") ;
        scanf(" %c" , &metaData.globalOrganizationMode) ;
         checkifCharUppercase(&metaData.globalOrganizationMode) ;
    } while (metaData.globalOrganizationMode != 'l' && metaData.globalOrganizationMode != 'c') ;
    do {
        printf("enter intern organization mode sorted or non (s/n): ") ;
        scanf(" %c" , &metaData.internOrganizationMode) ;
         checkifCharUppercase(&metaData.internOrganizationMode) ;
    } while (metaData.internOrganizationMode != 's' && metaData.internOrganizationMode != 'n') ;

/*     printf("you entered : \n");
    printf(" file name : %s \n" , metaData.fileName);
    printf(" records number : %d \n" , metaData.recordsNumber);
    printf(" global organization mode linked or contiguous (l/c): %c \n" , metaData.globalOrganizationMode) ;
    printf(" intern organization mode sorted or non (s/n): %c \n" , metaData.internOrganizationMode) ;
 */
    // ?????????????????????????????????????????????????????????????????????????????????
    metaData.firstBlocAddress ;
    metaData.recordsNumber ;

    chargeFile(fileName , metaData) ;
}
void chargeFile(const char *fileName  ,const MetaData metaData) {
    FILE *ptr = fopen(fileName , "wb") ;
        if (ptr == NULL) {
            printf("couldn't open the file named : %d \n" , fileName) ;
            return ;
        }
    fclose(ptr) ;

    ptr = NULL ;
}


void renameFile(const char * ,const char *) ;
void deleteFile(const char *) ;
void searchRecord(const char *,const int ) ;
void insertRecord(const char * ) ;
void defregmentate() ;
