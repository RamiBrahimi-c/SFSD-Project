#include "secondMem.h"



    

void discInisilize(AllocationTable *allocationTable ) {
    int n , m ;
 /*    do
    {
        printf("enter the total number of blocs : (must be strictly higher than 0 and less then %d) : " , MAX_SIZE_BLOCS_NUMBER) ;
        scanf("%d" , &n) ;
    } while (n<1 || n>MAX_SIZE_BLOCS_NUMBER);
    
    do
    {
        printf("enter the total number of blocs : (must be strictly higher than 0 and less then %d) : " , MAX_SIZE_RECORDS_NUMBER) ;
        scanf("%d" , &m) ;
    } while (m<1 || m>MAX_SIZE_RECORDS_NUMBER);
    
    getchar(); */
    // allocationTable->blockageFactor = 0 ;
    allocationTable->totalNumberOfBlocs = MAX_FILES ;
    allocationTable->totalNumberOfUsedBlocs = 0 ;
    allocationTable->length=0 ;
    for (int i = 0; i < MAX_FILES; i++)
    {
        allocationTable->files[i].used=0 ;
        allocationTable->files[i].num = i ;
        strcpy(allocationTable->files[i].fileName , "null") ;
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



void updateAllocationTable(AllocationTable *allocationTable , int mode  , char *fileName) {
    if (mode==1)
    {
        
        allocationTable->files[allocationTable->length].used = 1 ;
        strcpy(allocationTable->files[allocationTable->length].fileName , fileName) ;
        allocationTable->length++ ;
        allocationTable->totalNumberOfUsedBlocs++ ;
    }
    else
    {

        int index = isTherethisFile(*allocationTable, fileName) ;
        if(index == -1)
            return ;


        allocationTable->files[index].used = 0 ;
     
        strcpy(allocationTable->files[index].fileName , "NULL") ;

        allocationTable->length-- ;
        allocationTable->totalNumberOfUsedBlocs-- ;
        
    }
}

void printAllocationTable(AllocationTable allocationTable) {
        char *RESET = "\033[0m";     // Reset (default color)
    char *black = "\033[1;30m";  // Black
    char *red = "\033[1;31m";    // Red
    char *green = "\033[1;32m";  // Green
    char *yellow = "\033[1;33m"; // Yellow
    char *blue = "\033[1;34m";   // Blue
    char *purple = "\033[1;35m"; // Purple
    char *cyan = "\033[1;36m";   // Cyan
    char *white = "\033[1;37m";  // White


    printf("***************************************************************\n") ;
    printf("************************%s Allocation Table %s*********************\n" , green , RESET ) ;
    printf("***************************************************************\n") ;
        printf("total number of blocs :\t%d  \n", allocationTable.totalNumberOfBlocs);
        printf("total number of used blocs :\t%d  \n", allocationTable.totalNumberOfUsedBlocs);
        // printf("blocage factor : %d  \n", allocationTable.blockageFactor);
        printf("length :\t%d \n" , allocationTable.length) ;
        printf("-------------------------------------------------------------\n") ;
        printf("file number\tfile name   \t (used or no)\n") ;
        printf("-------------------------------------------------------------\n") ;
        for (int j = 0; j < 7; j++)
        {
            printf("%d\t\t %s  \t\t %s  \n" , allocationTable.files[j].num , (allocationTable.files[j].used>0) ? allocationTable.files[j].fileName :"null"  , (allocationTable.files[j].used == 1) ?  "used" : "not used");
        }
        printf("-------------------------------------------------------------\n") ;

    printf("***************************************************************\n") ;

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
    for(int i=0 ; i < 7 ; ++i){
        allocationTable->files[i].used=0 ;
        strcpy( allocationTable->files[i].fileName, "null");
    }
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





int isTherethisFile(AllocationTable allocationTable, char fileName[MAX_SIZE_FILENAME]) {
    for (int i = 0; i < allocationTable.length; i++)
        if (strcmp(fileName , allocationTable.files[i].fileName) ==0)
            return i ;
        
    return -1 ;
    
}











#if 0


 int main() {

    AllocationTable allocationTable ;

     
 
    readAllocationTable(&allocationTable) ;

    allocationTable.length = 4 ;
    allocationTable.files[0].used = 1 ;
    strcpy(allocationTable.files[0].fileName , "rami") ;

    allocationTable.files[1].used = 1 ;
    strcpy(allocationTable.files[1].fileName , "sara") ;

    allocationTable.files[2].used = 1 ;
    strcpy(allocationTable.files[2].fileName , "assinet") ;

    allocationTable.files[3].used = 1 ;
    strcpy(allocationTable.files[3].fileName , "israa") ;


    printAllocationTable(allocationTable) ;
    int r ;
       printf("%s    %d \n" ,(r =  isTherethisFile( allocationTable, "sara"  ) > -1) ? "yes" : "no" ,r ) ;
    
    
    return 0;



/* 
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
 */ 
    return 0 ;
}   

#endif