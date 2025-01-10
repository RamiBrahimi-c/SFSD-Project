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
        
        allocationTable->files[allocationTable->length].num = allocationTable->length +1;
        allocationTable->files[allocationTable->length].used = 1 ;
        allocationTable->length++ ;
        
    }
    else
    {
        allocationTable->files[allocationTable->length].num = 0 ;
        allocationTable->files[allocationTable->length].used = 0 ;
        allocationTable->length-- ;
        
        
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

