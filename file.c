#include "file.h"

const char secondMemFolder[] = "./secondary memory/" ; 
const char metaDataFolder[] = "./meta data/" ; 
char fullPath[40] ;
char fullPath2[40] ;

BlocContiguousStructure bufferContiguousStruct ;
BlocLinkedStructure bufferLinkedStruct ;


void createFile(  char *fileName) {
    
    int recordsNumber ;
    char organizationMode ;

    MetaData metaData ;

    //printf("enter file name : ");
    //fgets(metaData.fileName , sizeof(metaData.fileName) , stdin) ;
      
      //  metaData.fileName[strcspn(metaData.fileName, "\n")] = '\0'; // Remove newline
        
        strcpy(metaData.fileName , fileName) ;


    do
    {
        printf("enter total products number : ");
        scanf("%d" , &metaData.totalNumberProducts);        
    } while (metaData.totalNumberProducts < 1 || metaData.totalNumberProducts > MAX_PRODUCTS_NUMBER  );
    

    do
    {
    printf("enter records number (blockage factor) : ");
    scanf("%d" , &metaData.recordsNumber) ;
    } while (metaData.recordsNumber < 1 || metaData.recordsNumber > MAX_SIZE_RECORDS_NUMBER || metaData.recordsNumber > metaData.totalNumberProducts);
    

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
    getchar() ;
 
 
 /*     printf("you entered : \n");
    printf(" file name : %s \n" , metaData.fileName);
    printf(" records number : %d \n" , metaData.recordsNumber);
    printf(" global organization mode linked or contiguous (l/c): %c \n" , metaData.globalOrganizationMode) ;
    printf(" intern organization mode sorted or non (s/n): %c \n" , metaData.internOrganizationMode) ;
 */
    // ?????????????????????????????????????????????????????????????????????????????????

    metaData.firstBlocAddress=0 ;
    
            int totalNumBlocs = metaData.totalNumberProducts / metaData.recordsNumber ;
        totalNumBlocs += (metaData.totalNumberProducts % metaData.recordsNumber == 0 ) ? 0 : 1 ;
        metaData.blocsNumber = totalNumBlocs ;

    chargeFile(metaData.fileName , metaData) ;
    
}


void chargeFile( char *fileName  , MetaData metaData) {
    
    strcpy(fullPath , secondMemFolder) ;
    strcat(fullPath , fileName) ;
    
    FILE *ptr = fopen(fullPath , "wb") ;
        if (ptr == NULL) {
            printf("couldn't open the file named : %s \n" , fullPath) ;
            return ;
        }

    createFileBasedOnMetaDataContiguousStructure(ptr , metaData) ;



    fclose(ptr) ;

    ptr = NULL ;
    
    strcpy(fullPath , metaDataFolder) ;
    strcat(fullPath , fileName) ;
    
     ptr = fopen(fullPath , "wb") ;

        if (ptr == NULL) {
            printf("couldn't open the file  : %s \n" , fullPath) ;
            return ;
        }

        fwrite(&metaData , sizeof(metaData) , 1 , ptr) ;

    fclose(ptr) ;
}




void createFileBasedOnMetaDataContiguousStructure(FILE *ptr, MetaData metadata) {
     
    rewind(ptr) ;



    FILE *product = fopen((metadata.internOrganizationMode == 's') ? "./important files/products" : "./important files/products(shuffled)" , "rb+");
    if (product == NULL)
    {
        printf("can't open products file \n");
        return ;
    }   

        // printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    



        BlocContiguousStructure buffer ;

        
 
        int j = 0 , i = 0 ; 
        while ( i < metadata.totalNumberProducts)
    {

        int totalNumBlocs = metadata.totalNumberProducts / metadata.recordsNumber ;
        totalNumBlocs += (metadata.totalNumberProducts % metadata.recordsNumber == 0 ) ? 0 : 1 ;
        // printf("total num blocs : %d\n" , totalNumBlocs);
        if (j < totalNumBlocs-1)
        {
            buffer.nbBloc = metadata.recordsNumber ;
            buffer.product = malloc(sizeof(Product)*buffer.nbBloc) ;
            }
        else if (j == totalNumBlocs-1)
        {
            buffer.nbBloc = metadata.totalNumberProducts%metadata.recordsNumber ;
            buffer.product = malloc(sizeof(Product) * (buffer.nbBloc)) ;
        }
        


        printf("************************** bloc number %d ********************\n", j + 1);
            int k = 0 ;
        while (k<metadata.recordsNumber && i < metadata.totalNumberProducts)
        {
            
            fread(&(buffer.product[k]) , sizeof(Product) , 1 , product) ;
           printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                    buffer.product[k].id , buffer.product[k].name   ,buffer.product[k].cost ,buffer.product[k].deletedLogically  ) ;
            
            ++k  ;++i ; 
        }
            //buffer.nbBloc = k ;
            fwrite(&(buffer.nbBloc) , sizeof(buffer.nbBloc) , 1 , ptr);
            fwrite((buffer.product) , sizeof(Product) , buffer.nbBloc , ptr);
        printf("(after charging ) buffer.nbBloc = %d \n", buffer.nbBloc);
            free(buffer.product) ;
        
        ++j;
    }

    fclose(product) ;
    
}


void displayFileContent(char *fileName) {
     
    //  setFullPathtoSecondMemFolder(fileName) ;
    //  setFullPathtoMetadataFolder(fileName) ;
     

    strcpy(fullPath , secondMemFolder);
    strcat(fullPath , fileName) ;

    strcpy(fullPath2 , metaDataFolder);
    strcat(fullPath2 , fileName) ;

     FILE *ptr = fopen(fullPath , "rb+");
    if (ptr == NULL)
    {
        printf("couldn't open %s\n" , fullPath) ;
        return ;
    }
     FILE *temp = fopen(fullPath2 , "rb+");
    if (temp == NULL)
    {
        printf("couldn't open %s metadata\n" , fullPath2) ;
        return ;
    }
    
     MetaData metadata ;
    fread(&metadata , sizeof(metadata) , 1 , temp) ;

    fclose(temp) ;
     
     
     
     
     
        rewind(ptr) ;
        system("clear");
        printf("*****************************************************************************\n");

        printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    
        BlocContiguousStructure buffer ;
        
        int j = 0 ; 
        int i = 0 ;


        while ( i < metadata.totalNumberProducts  )
    {
        int totalNumBlocs = metadata.totalNumberProducts / metadata.recordsNumber ;
        totalNumBlocs += (metadata.totalNumberProducts % metadata.recordsNumber == 0 ) ? 0 : 1 ;
        if (j < totalNumBlocs-1)
        {
            buffer.nbBloc = metadata.recordsNumber ;
            buffer.product = malloc(sizeof(Product)*buffer.nbBloc) ;
            }
        else if (j == totalNumBlocs-1)
        {
            buffer.nbBloc = metadata.totalNumberProducts%metadata.recordsNumber ;
            buffer.product = malloc(sizeof(Product) * (buffer.nbBloc)) ;
        }
   
   
   
   
        printf("************************** bloc number %d ********************\n", j + 1);
            int k = 0 ;
            fread(&(buffer.nbBloc) , sizeof(buffer.nbBloc) , 1 , ptr) ;
            int result = fread((buffer.product) , sizeof(Product) , metadata.recordsNumber , ptr) ;


            while (k<metadata.recordsNumber && i < metadata.totalNumberProducts)
        {
            
            printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                         buffer.product[k].id , buffer.product[k].name   ,buffer.product[k].cost ,buffer.product[k].deletedLogically  ) ;
          
            ++k  ;++i ; 
        
        }
        printf("after charging buffer.nbBloc =%d \n", buffer.nbBloc);
        free(buffer.product) ;
        ++j ;
    }

        printf("********************************\n");
        fseek(ptr , 0 , SEEK_END) ;
        int length =  ftell(ptr)/sizeof(Product) ;
        printf("lenght = %d \n" ,length ) ;  

        printf("*****************************************************************************\n");

}





void printMetadata(char *fileName) {
    strcpy(fullPath2 , metaDataFolder) ;
    strcat(fullPath2 , fileName) ;

    FILE *ptr = fopen(fullPath2 , "rb+");
    if (ptr==NULL)
    {
        printf("can't open %s \n" , fullPath2) ;
        return;
    }

    MetaData metadata ;
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;

        char *reset = "\033[0m";     // Reset (default color)
    char *black = "\033[1;30m";  // Black
    char *red = "\033[1;31m";    // Red
    char *green = "\033[1;32m";  // Green
    char *yellow = "\033[1;33m"; // Yellow
    char *blue = "\033[1;34m";   // Blue
    char *purple = "\033[1;35m"; // Purple
    char *cyan = "\033[1;36m";   // Cyan
    char *white = "\033[1;37m";  // White

    printf("**********************************************************************\n" ) ;
    printf("**********************%s Meta Data%s *************************************\n" , cyan , reset) ;
    printf("**********************************************************************\n") ;

    printf("%sfile name :%s %s%s%s\n",blue , reset ,red ,     metadata.fileName , reset  ) ;

    printf("%sfirst bloc address :%s %s%d%s\n" , blue , reset , red ,    metadata.firstBlocAddress , reset);
    if (metadata.globalOrganizationMode=='c')
    {
        
        printf( "%sintern organization mode :%s %scontiguous%s\n",blue , reset,yellow , reset) ;
    }
    else
    {
        printf( "%sintern organization mode :%s %slinked%s\n",blue , reset,purple , reset) ;
    }
    if (metadata.internOrganizationMode=='s')
    {
        
        printf( "%sintern organization mode :%s %ssorted%s\n" , blue , reset,green , reset) ;
    }
    else
    {
        printf( "%sintern organization mode :%s %snot sorted%s\n" , blue , reset,red , reset) ;
    }
    printf("%sblocs number  :%s %s%d%s\n" , blue , reset,red ,     metadata.blocsNumber , reset  ) ;
    printf("%srecords number (blockage factor) :%s %s%d%s\n" , blue , reset,red ,     metadata.recordsNumber , reset  );
    printf("%stotal number of blocs :%s %s%d%s\n", blue , reset ,red         ,metadata.totalNumberProducts  , reset);

    printf("**********************************************************************\n") ;
    
}







int renameFile( char *old_Name, char *new_Name) {

    strcpy(fullPath , secondMemFolder) ;
    strcat(fullPath , old_Name) ;

    strcpy(fullPath2 , secondMemFolder) ;
    strcat(fullPath2 , new_Name) ;

    // printf("old name : %s\nnew name : %s \n" , fullPath , fullPath2);

    if (rename(fullPath , fullPath2)  == 0) {
        printf("File renamed successfully\n");
        return 1 ;
    } else {
        if (errno == ENOENT) {
            printf("Error: File '%s' does not exist\n", old_Name);
        } else if (errno == EACCES) {
            printf("Error: Permission denied\n");
        } else {
            perror("Error renaming file");
        }
        return -1 ;
    }

}

void renameFileMetaData( char *old_Name , char *new_Name) {

    strcpy(fullPath , metaDataFolder) ;
    strcat(fullPath , old_Name) ;

    strcpy(fullPath2 , metaDataFolder) ;
    strcat(fullPath2 , new_Name) ;

    // printf("old name : %s\nnew name : %s \n" , fullPath , fullPath2);

    if (rename(fullPath , fullPath2)  == 0) {
        printf("File renamed successfully\n");
    } else {
        if (errno == ENOENT) {
            printf("Error: File '%s' does not exist\n", old_Name);
        } else if (errno == EACCES) {
            printf("Error: Permission denied\n");
        } else {
            perror("Error renaming file");
        }
    }

}

int deleteFile( char *fileName) {
    strcpy(fullPath , secondMemFolder) ;
    strcat(fullPath , fileName) ;
     

       if (remove(fullPath) == 0) {
        printf("File deleted successfully\n");
        return 1 ;
    } else {
        if (errno == ENOENT) {
            printf("Error: File '%s' does not exist\n", fileName);
        } else if (errno == EACCES) {
            printf("Error: Permission denied\n");
        } else {
            perror("Error deleting file");
        }
            return -1 ;
    }
    
}
int deleteFileMetaData( char *metadata)  {
    strcpy(fullPath2 , metaDataFolder) ;
    strcat(fullPath2 , metadata) ;
     

       if (remove(fullPath2) == 0) {
        printf("File deleted successfully\n");
        return 1 ;
    } else {
        if (errno == ENOENT) {
            printf("Error: File '%s' does not exist\n", metadata);
        } else if (errno == EACCES) {
            printf("Error: Permission denied\n");
        } else {
            perror("Error deleting file");
        }
            return -1 ;
    }
    
}


// not tested

void searchRecord( char *fileName, int id , int *result) {
    
    strcpy(fullPath2 , metaDataFolder) ;
    strcpy(fullPath2 , fileName) ;



    FILE *ptr = fopen(fullPath2 , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open %s \n" , fullPath2) ;
        return ;
    }
    
    MetaData metadata ;
    
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;

    fclose(ptr) ;

    setFullPathtoSecondMemFolder(fileName) ;

    ptr = fopen(fullPath , "rb+") ;

    (metadata.globalOrganizationMode == 'c') ? searchRecordContiguousStructure(ptr , id , result , metadata) : searchRecordLinkedStructure(ptr , id , result , metadata) ;

    fclose(ptr) ;
}

// not tested
void searchRecordContiguousStructure(FILE *ptr ,  int id, int *result , MetaData metadata) {

    rewind(ptr) ;
    fseek(ptr , 0 , SEEK_END) ;
    int length = ftell(ptr) / sizeof(BlocContiguousStructure) ;
    rewind(ptr) ;

    int k = metadata.recordsNumber ;

    result[0]=-1 ;
    result[1]=-1 ;

    if (metadata.internOrganizationMode == 's') { // binary search
        int left , right  , mid  ; 
        
            fseek(ptr , metadata.firstBlocAddress * sizeof(bufferContiguousStruct) , SEEK_SET) ;
        for (int i = metadata.firstBlocAddress; i < length; i++)
        {
            fread(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ;
            left = 0 ;
            right = bufferContiguousStruct.nbBloc ;
            while (left <= right)
            {
                mid =  left + (right - left) / 2 ;
                if(bufferContiguousStruct.product[mid].id == id) {
                    result[0] = i ;
                    result[0] = mid ;
                    return ;
                } else if (bufferContiguousStruct.product[mid].id > id) {
                    right = mid - 1 ;
                } else {
                    left = mid + 1 ;
                }
            }
            
        }
        
        
    } else { // linear search
            fseek(ptr , metadata.firstBlocAddress * sizeof(bufferContiguousStruct) , SEEK_SET) ;
        for (int i = metadata.firstBlocAddress; i < length; i++)
        {
            fread(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ;
            int j =0 ;
            while (j < bufferContiguousStruct.nbBloc)
            {
                if (bufferContiguousStruct.product[j].id == id)
                {
                    result[0] = i ;
                    result[1] = j ;
                    return ;
                }
                ++j ;
            }
            
            
        }
        

    }

}

// not tested
void searchRecordLinkedStructure(FILE *ptr ,  int id, int *result , MetaData metadata) {
    
    rewind(ptr) ;
    fseek(ptr , 0 , SEEK_END) ;
    int length = ftell(ptr) / sizeof(BlocLinkedStructure) ;
    rewind(ptr) ;

    int k = metadata.recordsNumber ;

    result[0]=-1 ;
    result[1]=-1 ;

    if (metadata.internOrganizationMode == 's') { // binary search on both record level  && linear search on record level 
        int left , right  , mid  ; 
        
        int i = metadata.firstBlocAddress ;
        while (i < length && i != -1)
        {
            fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fread(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ;
            left = 0 ;
            right = bufferLinkedStruct.nbBloc ;
            while (left <= right)
            {
                mid =  left + (right - left) / 2 ;
                if(bufferLinkedStruct.product[mid].id == id) {
                    result[0] = i ;
                    result[0] = mid ;
                    return ;
                } else if (bufferLinkedStruct.product[mid].id > id) {
                    right = mid - 1 ;
                } else {
                    left = mid + 1 ;
                }
            }
            i = bufferLinkedStruct.next ;
        }
        
        
    } else { // linear search on both bloc && record level 
        int i = metadata.firstBlocAddress ;
        while (i < length && i != -1) // ???????????????????????????????
        {
            fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fread(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ;
            
            int j =0 ;
            while (j < bufferLinkedStruct.nbBloc)
            {
                if (bufferLinkedStruct.product[j].id == id)
                {
                    result[0] = i ;
                    result[1] = j ;
                    return ;
                }
                ++j ;
            }    
            i = bufferLinkedStruct.next ;        
        }
        
        

        

    }

}


void insertRecord( char *fileName ) {
    strcpy(fullPath2 , metaDataFolder) ;
    strcat(fullPath2 , fileName) ;



    FILE *ptr = fopen(fullPath2 , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open %s \n" , fullPath2) ;
        return ;
    }
    
    MetaData metadata ;
    
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;

    fclose(ptr) ;

    setFullPathtoSecondMemFolder(fileName) ;

    ptr = fopen(fullPath , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open file on path : %s \n" , fullPath) ;
        return ;
    }
    
    // ?????????????????????
    Product product ;
    product.cost = 2 ;
    product.deletedLogically = 0 ;
    product.id = rand() % 500 + 101 ;
    
    strcpy(product.name , "testing");

    (metadata.globalOrganizationMode == 'c') ?  insertRecordContigiousStructure2(ptr ,  &metadata , product ) : insertRecordLinkedStructure(ptr ,  &metadata , product) ;

    fclose(ptr) ;    
}

// ???????????????????????????? update the metadata file ?????????????????????????????
void insertRecordContiguousStructure(FILE *ptr, MetaData *metadata , Product product) {


    rewind(ptr) ;
    fseek(ptr , 0 , SEEK_END) ;
    int length = ftell(ptr) / sizeof(BlocContiguousStructure) ;
    rewind(ptr) ;

    int k = metadata->recordsNumber ;


        int i = metadata->firstBlocAddress ;
         k = length ;

    fseek(ptr , k * sizeof(bufferContiguousStruct) , SEEK_SET) ;
    fread(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ;

    if (metadata->internOrganizationMode == 's') { // insert in right position 
        if (bufferContiguousStruct.nbBloc >= metadata->recordsNumber)
        {

            // last bloc is full go to next one 
            bufferContiguousStruct.nbBloc=1 ;
            // bufferContiguousStruct.product = malloc(sizeof(bufferContiguousStruct) * metadata->recordsNumber) ;
            bufferContiguousStruct.product[0].cost=product.cost ;
            bufferContiguousStruct.product[0].deletedLogically=0 ;
            bufferContiguousStruct.product[0].id=product.id ;
            strcpy(bufferContiguousStruct.product[0].name , product.name) ;



            fseek(ptr , k * sizeof(bufferContiguousStruct) , SEEK_SET) ;
            fwrite(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ; 
            
        }
        else
        {
            bufferContiguousStruct.nbBloc = insertSorted(bufferContiguousStruct.product , bufferContiguousStruct.nbBloc , product , MAX_SIZE_RECORDS_NUMBER);

        }
        
        
        
    } else { // not sorted 

        if (bufferContiguousStruct.nbBloc >= metadata->recordsNumber)
        {
            // last bloc is full go to next one 
            bufferContiguousStruct.nbBloc=1 ;
            // bufferContiguousStruct.product = malloc(sizeof(bufferContiguousStruct) * metadata->recordsNumber) ;
            bufferContiguousStruct.product[0].cost=product.cost ;
            bufferContiguousStruct.product[0].deletedLogically=0 ;
            bufferContiguousStruct.product[0].id=product.id ;
            strcpy(bufferContiguousStruct.product[0].name , product.name) ;

            ++k ;
            fseek(ptr , k * sizeof(bufferContiguousStruct) , SEEK_SET) ;
            fwrite(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ; 


        }
        else
        {
            int j = bufferContiguousStruct.nbBloc ;
            bufferContiguousStruct.product[j].cost = product.cost ;
            bufferContiguousStruct.product[j].deletedLogically = 0 ;
            bufferContiguousStruct.product[j].id = product.id ;
            strcpy(bufferContiguousStruct.product[j].name , product.name);

            bufferContiguousStruct.nbBloc++ ;
            fseek(ptr , k * sizeof(bufferContiguousStruct) , SEEK_SET) ;
            fwrite(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr) ;            
        }

    }


            



}

int insertRecordContigiousStructure2(FILE *ptr , MetaData *metadata , Product product) {
         rewind(ptr) ;

    BlocContiguousStructure buffer ;

        buffer.product = malloc(sizeof(Product)*3 );


        int t =metadata->blocsNumber-1;
        fseek(ptr , sizeof(buffer.nbBloc) * t  ,SEEK_SET  ) ;
        fseek(ptr , sizeof(Product) * 3 * t,SEEK_CUR  ) ;
        fread(&buffer.nbBloc , sizeof(buffer.nbBloc) , 1 , ptr) ;
        fread(buffer.product , sizeof(Product) , 3 , ptr) ;




        int index = buffer.nbBloc ;
        buffer.product[index].cost =     product.cost  ;
        buffer.product[index].deletedLogically =  product.deletedLogically ;
        buffer.product[index].id =  product.id ;
        strcpy(buffer.product[index].name , product.name) ;

        buffer.nbBloc++  ;



        printf("********************adding this ****************************\n%d\n", buffer.nbBloc);

        for (int i = 0; i < buffer.nbBloc; i++)
        {
                printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                            buffer.product[i].id , buffer.product[i].name   ,buffer.product[i].cost ,buffer.product[i].deletedLogically  ) ;

        }
        printf("************************************************************************\n");

        rewind(ptr) ;
        fseek(ptr , sizeof(buffer.nbBloc) * t  ,SEEK_SET  ) ;
        fseek(ptr , sizeof(Product) * 3 * t,SEEK_CUR  ) ;
        fwrite(&buffer.nbBloc , sizeof(buffer.nbBloc) , 1 , ptr) ;
        fwrite(buffer.product , sizeof(Product) , buffer.nbBloc , ptr) ;

        metadata->totalNumberProducts++ ;
        
        setFullPathtoMetadataFolder(metadata->fileName) ;
        FILE *temp = fopen(fullPath2 , "wb+") ;
        if (temp == NULL)
        {
            printf("can't open %s \n" , fullPath2) ;
            return -1;
        }
        fwrite(metadata , sizeof(MetaData) , 1 , temp) ;

        fclose(temp) ;

}


void deleteRecordLogically( char *fileName , int id) {
    strcpy(fullPath2 , metaDataFolder) ;
    strcpy(fullPath2 , fileName) ;



    FILE *ptr = fopen(fullPath2 , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open %s \n" , fullPath2) ;
        return ;
    }
    
    MetaData metadata ;
    
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;

    fclose(ptr) ;

    setFullPathtoSecondMemFolder(fileName) ;

    ptr = fopen(fullPath , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open file on path : %s \n" , fullPath) ;
        return ;
    }
    

    rewind(ptr) ;

    int result[2] = {-1 , -1} ;
    searchRecord(fileName , id , result) ;
    if (result[0]==-1 || result[1]==-1) {
        printf("doesn't exist\n") ;
        return ;
    }
    int i = result[0] , j = result[1] ;

    if (metadata.globalOrganizationMode == 'c') {
        fseek(ptr , i * sizeof(bufferContiguousStruct) , SEEK_SET) ;
        fread(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr ) ;

        bufferContiguousStruct.product[j].deletedLogically = 1 ;
    } else {
        fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
        fread(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr ) ;

        bufferLinkedStruct.product[j].deletedLogically = 1 ;

    }
    fclose(ptr) ;    

}

void deleteRecordPhysically( char *fileName ,int id ) {
    strcpy(fullPath2 , metaDataFolder) ;
    strcpy(fullPath2 , fileName) ;



    FILE *ptr = fopen(fullPath2 , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open %s \n" , fullPath2) ;
        return ;
    }
    
    MetaData metadata ;
    
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;

    fclose(ptr) ;

    setFullPathtoSecondMemFolder(fileName) ;

    ptr = fopen(fullPath , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open file on path : %s \n" , fullPath) ;
        return ;
    }
    

    rewind(ptr) ;

    int result[2] = {-1 , -1} ;
    searchRecord(fileName , id , result) ;
    if (result[0]==-1 || result[1]==-1) {
        printf("doesn't exist\n") ;
        return ;
    }
    int i = result[0] , j = result[1] ;


    if (metadata.globalOrganizationMode == 'c') {
        fseek(ptr , i * sizeof(bufferContiguousStruct) , SEEK_SET) ;
        fread(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr ) ;

        bufferContiguousStruct.nbBloc = deleteRecordfromArray(bufferContiguousStruct.product , bufferContiguousStruct.nbBloc , id) ;
        fseek(ptr , i * sizeof(bufferContiguousStruct) , SEEK_SET) ;
        fwrite(&bufferContiguousStruct , sizeof(bufferContiguousStruct) , 1 , ptr ) ;

    } else {
        fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
        fread(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr ) ;

        bufferLinkedStruct.nbBloc =  deleteRecordfromArray(bufferLinkedStruct.product , bufferLinkedStruct.nbBloc , id) ;
        fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
        fwrite(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr ) ;

    }
    fclose(ptr) ;    

}


// ???????????????????????????? update the metadata file ?????????????????????????????
void insertRecordLinkedStructure(FILE *ptr , MetaData *metadata  , Product product) {
    rewind(ptr) ;
    fseek(ptr , 0 , SEEK_END) ;
    int length = ftell(ptr) / sizeof(BlocLinkedStructure) ;
    rewind(ptr) ;

    int k = metadata->recordsNumber ;

        int i = metadata->firstBlocAddress ;
         k = -1 ;
        while (i < metadata->blocsNumber && i != -1){
            fread(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ;
            k= i ;
            i = bufferLinkedStruct.next ;
        }
        i = k ;
            


    if (metadata->internOrganizationMode == 's') { //  
        if (bufferLinkedStruct.nbBloc >= metadata->recordsNumber)
        {

            // last bloc is full go to next one 
            BlocLinkedStructure bufferLinkedStruct2 ;
            bufferLinkedStruct2.nbBloc=1 ;
            bufferLinkedStruct2.next=-1 ;
            // bufferLinkedStruct2.product = malloc(sizeof(bufferLinkedStruct2) * metadata->recordsNumber) ;
            bufferLinkedStruct2.product[0].cost=product.cost ;
            bufferLinkedStruct2.product[0].deletedLogically=0 ;
            bufferLinkedStruct2.product[0].id=product.id ;
            strcpy(bufferLinkedStruct2.product[0].name , product.name) ;

            int newPos = i+1 ;
            bufferLinkedStruct.next = newPos ;

            fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fwrite(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ; 
            fseek(ptr , newPos * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fwrite(&bufferLinkedStruct2 , sizeof(bufferLinkedStruct2) , 1 , ptr) ; 
            
        }
        else
        {
            bufferLinkedStruct.nbBloc = insertSorted(bufferLinkedStruct.product , bufferLinkedStruct.nbBloc , product , MAX_SIZE_RECORDS_NUMBER);

        }
        
        

    } else { // insertion in non sorted linked struct file 
    
        if (bufferLinkedStruct.nbBloc >= metadata->recordsNumber)
        {
            // last bloc is full go to next one 
            BlocLinkedStructure bufferLinkedStruct2 ;
            bufferLinkedStruct2.nbBloc=1 ;
            bufferLinkedStruct2.next=-1 ;
            // bufferLinkedStruct2.product = malloc(sizeof(bufferLinkedStruct2) * metadata->recordsNumber) ;
            bufferLinkedStruct2.product[0].cost=product.cost ;
            bufferLinkedStruct2.product[0].deletedLogically=0 ;
            bufferLinkedStruct2.product[0].id=product.id ;
            strcpy(bufferLinkedStruct2.product[0].name , product.name) ;

            int newPos = i+1 ;
            bufferLinkedStruct.next = newPos ;

            fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fwrite(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ; 
            fseek(ptr , newPos * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fwrite(&bufferLinkedStruct2 , sizeof(bufferLinkedStruct2) , 1 , ptr) ; 


        }
        else
        {
            
            int j = bufferLinkedStruct.nbBloc ;
            bufferLinkedStruct.product[j].cost = product.cost ;
            bufferLinkedStruct.product[j].deletedLogically = 0 ;
            bufferLinkedStruct.product[j].id = product.id ;
            strcpy(bufferLinkedStruct.product[j].name , product.name);

            bufferLinkedStruct.nbBloc++ ;
            fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
            fwrite(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ;
            
        }
        

    }

}




int insertSorted(Product arr[], int n, Product key, int capacity)
{
    // Cannot insert more elements if n is already
    // more than or equal to capacity
    if (n >= capacity)
        return n;

    int i;
    for (i = n - 1; (i >= 0 && arr[i].id > key.id); i--) {
        arr[i + 1].cost = arr[i].cost;
        arr[i + 1].deletedLogically = arr[i].deletedLogically;
        arr[i + 1].id = arr[i].id;
        strcpy(arr[i + 1].name ,arr[i].name );

    }
        arr[i + 1].cost = key.cost;
        arr[i + 1].deletedLogically = key.deletedLogically;
        arr[i + 1].id = key.id;
        strcpy(arr[i + 1].name ,key.name );


    return (n + 1);
}





int deleteRecordfromArray(Product *arr , int length ,int key) {
    int i , j ;

    for ( i = 0; i < length; i++)
        if (arr[i].id==key)
            break;
    
    if ( i >= length )
    return length ;

    for ( j = i ; j < length-1 ; ++j) {
        arr[j].cost=arr[j+1].cost ;
        arr[j].deletedLogically=arr[j+1].deletedLogically ;
        arr[j].id=arr[j+1].id ;
        strcpy(arr[j].name , arr[j+1].name) ;
    }

    return --length ;
}



/* 
void insertRecordLinkedStructureinNewBloc() {
    BlocLinkedStructure bufferLinkedStruct2 ;
    bufferLinkedStruct2.nbBloc=1 ;
    bufferLinkedStruct2.next=-1 ;
            // bufferLinkedStruct2.product = malloc(sizeof(bufferLinkedStruct2) * metadata->recordsNumber) ;
    bufferLinkedStruct2.product[0].cost=product.cost ;
    bufferLinkedStruct2.product[0].deletedLogically=0 ;
    bufferLinkedStruct2.product[0].id=product.id ;
    strcpy(bufferLinkedStruct2.product[0].name , product.name) ;

    int newPos = i+1 ;
    bufferLinkedStruct.next = newPos ;

    fseek(ptr , i * sizeof(bufferLinkedStruct) , SEEK_SET) ;
        fwrite(&bufferLinkedStruct , sizeof(bufferLinkedStruct) , 1 , ptr) ; 
        fseek(ptr , newPos * sizeof(bufferLinkedStruct) , SEEK_SET) ;
        fwrite(&bufferLinkedStruct2 , sizeof(bufferLinkedStruct2) , 1 , ptr) ; 

}

 */


void cleanString(char string[]) {
    string[strlen(string)-1]= ( string[strlen(string)-1] == '\n' )? '\0' : string[strlen(string)-1] ; 

}





void printErrorMessage(char *string , COLORS color) {
        char *RESET = "\033[0m";     // Reset (default color)
    char *black = "\033[1;30m";  // Black
    char *red = "\033[1;31m";    // Red
    char *green = "\033[1;32m";  // Green
    char *yellow = "\033[1;33m"; // Yellow
    char *blue = "\033[1;34m";   // Blue
    char *purple = "\033[1;35m"; // Purple
    char *cyan = "\033[1;36m";   // Cyan
    char *white = "\033[1;37m";  // White


    switch (color)
    {
    case RED:
        printf("%s%s%s\n" , red , string , RESET) ;
        
        break;
    case BLACK:
        printf("%s%s%s\n" , black , string , RESET) ;
        
        break;
    case GREEN:
        printf("%s%s%s\n" , green , string , RESET) ;
        
        break;
    case PURPLE:
        printf("%s%s%s\n" , purple , string , RESET) ;
        
        break;
    case CYAN:
        printf("%s%s%s\n" , cyan , string , RESET) ;
        
        break;
    case WHITE:
        printf("%s%s%s\n" , white , string , RESET) ;
        
        break;
    case BLUE:
        printf("%s%s%s\n" , blue , string , RESET) ;
        
        break;
    case YELLOW:
        printf("%s%s%s\n" , yellow , string , RESET) ;
        
        break;

    default:
        break;
    }



}

void create() ;


int calculateFileLength(FILE *ptr) ;


void checkifCharUppercase(char *c) {
    *c = (*c >= 65 && *c <= 90) ? (*c)+32 : *c ;
}


void setFullPathtoSecondMemFolder(char *fileName) {

    strcpy(fullPath , secondMemFolder) ;
    strcat(fullPath , fileName) ;
}

void setFullPathtoMetadataFolder(char *fileName) {

    strcpy(fullPath2 , metaDataFolder) ;
    strcat(fullPath2 , fileName) ;
}

