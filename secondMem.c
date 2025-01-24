#include "secondMem.h"



    

void discInisilize(AllocationTable *allocationTable ) {
    int n , m ;
    do
    {
        printf("enter the total number of blocs : (must be strictly higher than 0 and less then %d) : " , MAX_SIZE_BLOCS_NUMBER) ;
        scanf("%d" , &n) ;
    } while (n<1 || n>MAX_SIZE_BLOCS_NUMBER);
    
    do
    {
        printf("enter the total number of blocs : (must be strictly higher than 0 and less then %d) : " , MAX_SIZE_RECORDS_NUMBER) ;
        scanf("%d" , &m) ;
    } while (m<1 || m>MAX_SIZE_RECORDS_NUMBER);
    
    getchar();
    allocationTable->blockageFactor = m ;
    allocationTable->totalNumberOfBlocs = n ;
    allocationTable->totalNumberOfUsedBlocs=0 ;
    allocationTable->length=0 ;
    for (int i = 0; i < MAX_FILES; i++)
    {
        allocationTable->files[i].used=0 ;
    }
    
    const char *dirname = "secondary memory";

    if (MKDIR(dirname) == 0) {
        printf("Directory created successfully\n");
    } else {
        perror("Error creating directory");
    }
    const char *dirname2 = "meta data";

    if (MKDIR(dirname2) == 0) {
        printf("Directory created successfully\n");
    } else {
        perror("Error creating directory");
    }
    
}



void updateAllocationTable(AllocationTable *allocationTable , int mode ) {
    if (mode==1)
    {
        
        allocationTable->files[allocationTable->length].used = 1 ;
        allocationTable->length++ ;
        allocationTable->totalNumberOfUsedBlocs++ ;
        
    }
    else
    {

        allocationTable->files[allocationTable->length-1].used = 0 ;
        allocationTable->length-- ;
        allocationTable->totalNumberOfUsedBlocs-- ;
        
    }
}

void printAllocationTable(AllocationTable allocationTable) {

        printf("total number of blocs %d  \n", allocationTable.totalNumberOfBlocs);
        printf("total number of used blocs %d  \n", allocationTable.totalNumberOfUsedBlocs);
        printf("blocage factor : %d  \n", allocationTable.blockageFactor);
        printf("length : %d \n" , allocationTable.length) ;
        for (int j = 0; j < 7; j++)
        {
            printf("file number : %d \t %s \n" , allocationTable.files[j].num , allocationTable.files[j].used == 1 ?  "used" : "not used");
        }


}


void compactage() ;

void emptySecondaryMemory() {
    const char *path = "./secondary memory"; 

    if (remove_directory_contents(path) == 0) {
        printf("Contents of %s removed successfully.\n", path);
    } else {
        fprintf(stderr, "Failed to remove contents of %s.\n", path);
    }

    const char *path2 = "./meta data"; 

    if (remove_directory_contents(path2) == 0) {
        printf("Contents of %s removed successfully.\n", path);
    } else {
        fprintf(stderr, "Failed to remove contents of %s.\n", path);
    }

}

void stockageSpaceManagement() ;

void readAllocationTable(AllocationTable *allocationTable) {
    FILE *ptr = fopen("allocation table/metadata" , "rb+") ;
    if (ptr==NULL)
    {
        printf("can't open allocation table/metadata" ) ;
        return;
    }    
    fread(allocationTable , sizeof(*allocationTable) , 1 , ptr) ;

}

void writeAllocationTable(AllocationTable allocationTable) {
    FILE *ptr = fopen("allocation table/metadata" , "wb+") ;
    if (ptr==NULL)
    {
        printf("can't open allocation table/metadata" ) ;
        return;
    }
    fwrite(&allocationTable , sizeof(allocationTable) , 1 , ptr) ;
    
}


void formatAllocationTable(AllocationTable *allocationTable) {
    allocationTable->totalNumberOfUsedBlocs = 0 ;
    allocationTable->length = 0 ;
    for(int i=0 ; i < 7 ; ++i)
        allocationTable->files[i].used=0 ;
}

int remove_directory_contents(const char *path) {
#ifdef _WIN32
    // Use PowerShell or Command Prompt commands for Windows
    char command[1024];
    snprintf(command, sizeof(command), "rmdir /S /Q \"%s\"", path);
#else
    // Use shell commands for Linux
    char command[1024];
    snprintf(command, sizeof(command), "rm -rf \"%s\"/*", path);
#endif
    return system(command);
}
/* 
 int main() {

    AllocationTable allocationTable ;

    allocationTable.blockageFactor =5;
    allocationTable.files[0].num ;
    allocationTable.files[0].used ;
    allocationTable.length=0 ;
    allocationTable.totalNumberOfBlocs=7 ;
    allocationTable.totalNumberOfUsedBlocs=0 ;

    for (int i = 0; i < 7; i++)
    {
        allocationTable.files[i].num=i+1 ;
        allocationTable.files[i].used=0 ;
    }

    printf("***************** before updating ********************\n");
    

    updateAllocationTable(&allocationTable , 1) ;
    updateAllocationTable(&allocationTable , 1) ;
    updateAllocationTable(&allocationTable , 1) ;
    
   printAllocationTable(allocationTable) ;
    printf("***************** after updating *********************\n");


    updateAllocationTable(&allocationTable , 0) ;

   printAllocationTable(allocationTable) ;


 
    //chargeAllocationTable(allocationTable) ;
    AllocationTable al ;
    readAllocationTable(&al) ;

    printAllocationTable(al) ;
 
    return 0 ;
}  */