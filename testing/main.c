#include "../file.h"
#include <time.h>

// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************


/* 
void createFileLinkedStructureBasedOnMetaData(MetaData metadata) {
     
    char temp[25] ;
    strcpy(temp , "./") ;
    strcat(temp , metadata.fileName) ;

    FILE *ptr = fopen(temp , "wb+");
    
        if (ptr==NULL)
    {
        printf("can't create file Name %s" , temp) ;
        return;
    } 

    FILE *product = fopen("products" , "rb+");
    if (product == NULL)
    {
        printf("can't open products file \n");
        return ;
    }   

        // printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    



        BlocLinkedStructure buffer ;

        
 
        int j = 0 , i = 0 ; 
        while ( i < metadata.totalNumberProducts)
    {

        int totalNumBlocs = metadata.totalNumberProducts / metadata.recordsNumber ;
        totalNumBlocs += (metadata.totalNumberProducts % metadata.recordsNumber == 0 ) ? 0 : 1 ;
        // printf("total num blocs : %d\n" , totalNumBlocs);
        if (j < totalNumBlocs-1)
        {
            buffer.nbBloc = metadata.recordsNumber ;
            buffer.next = j + 1 ;
            buffer.product = malloc(sizeof(Product)*buffer.nbBloc) ;
            }
        else if (j == totalNumBlocs-1)
        {
            buffer.next = -1 ;
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
             fwrite(&(buffer.next) , sizeof(buffer.next) , 1 , ptr);
            fwrite((buffer.product) , sizeof(Product) , buffer.nbBloc , ptr);
        printf("(after charging ) buffer.nbBloc = %d \n", buffer.nbBloc);
            free(buffer.product) ;
        
        ++j;
    }
    
    
}

 */


void writeProducts() {
    FILE *ptr = fopen("products" , "wb+") ;
    if (ptr == NULL)
    {
        printf("couldn't open products file !\n");
        return;
    }
    Product products[100] = {
        {1, 0, "Laptop", 999.99}, {2, 0, "Smartphone", 799.99},
        {3, 0, "Tablet", 499.99}, {4, 0, "Headphones", 199.99},
        {5, 0, "Smartwatch", 299.99}, {6, 0, "Gaming Mouse", 59.99},
        {7, 0, "Keyboard", 89.99}, {8, 0, "Monitor", 249.99},
        {9, 0, "Printer", 149.99}, {10, 0, "Desk Lamp", 39.99},
        {11, 0, "Router", 129.99}, {12, 0, "External HDD", 79.99},
        {13, 0, "Flash Drive", 19.99}, {14, 0, "Webcam", 99.99},
        {15, 0, "Portable Speaker", 149.99}, {16, 0, "Drone", 499.99},
        {17, 0, "Camera", 699.99}, {18, 0, "Projector", 999.99},
        {19, 0, "Graphics Card", 399.99}, {20, 0, "CPU", 249.99},
        {21, 0, "Motherboard", 199.99}, {22, 0, "RAM", 129.99},
        {23, 0, "SSD", 99.99}, {24, 0, "Power Supply", 89.99},
        {25, 0, "PC Case", 69.99}, {26, 0, "VR Headset", 599.99},
        {27, 0, "Smart Thermostat", 149.99}, {28, 0, "Electric Scooter", 349.99},
        {29, 0, "Fitness Tracker", 89.99}, {30, 0, "Electric Toothbrush", 59.99},
        {31, 0, "Hair Dryer", 39.99}, {32, 0, "Blender", 79.99},
        {33, 0, "Microwave", 149.99}, {34, 0, "Toaster", 49.99},
        {35, 0, "Coffee Maker", 99.99}, {36, 0, "Air Purifier", 199.99},
        {37, 0, "Vacuum Cleaner", 249.99}, {38, 0, "Ceiling Fan", 129.99},
        {39, 0, "Washing Machine", 499.99}, {40, 0, "Refrigerator", 999.99},
        {41, 0, "Dishwasher", 799.99}, {42, 0, "Oven", 899.99},
        {43, 0, "Air Conditioner", 1199.99}, {44, 0, "Space Heater", 59.99},
        {45, 0, "Electric Grill", 149.99}, {46, 0, "Stand Mixer", 299.99},
        {47, 0, "Rice Cooker", 69.99}, {48, 0, "Pressure Cooker", 129.99},
        {49, 0, "Slow Cooker", 89.99}, {50, 0, "Electric Kettle", 49.99},
        {51, 0, "Juicer", 159.99}, {52, 0, "Food Processor", 199.99},
        {53, 0, "Electric Shaver", 79.99}, {54, 0, "E-Book Reader", 139.99},
        {55, 0, "Bluetooth Earbuds", 149.99}, {56, 0, "Noise-Canceling Headphones", 249.99},
        {57, 0, "Smart Light Bulb", 29.99}, {58, 0, "WiFi Extender", 59.99},
        {59, 0, "Dash Cam", 99.99}, {60, 0, "Smart Doorbell", 199.99},
        {61, 0, "Security Camera", 249.99}, {62, 0, "Smart Plug", 24.99},
        {63, 0, "Electric Skateboard", 399.99}, {64, 0, "Hoverboard", 299.99},
        {65, 0, "Portable Air Compressor", 59.99}, {66, 0, "Cordless Drill", 89.99},
        {67, 0, "Laser Measure", 49.99}, {68, 0, "Digital Multimeter", 39.99},
        {69, 0, "Electric Screwdriver", 29.99}, {70, 0, "Stud Finder", 19.99},
        {71, 0, "Socket Set", 99.99}, {72, 0, "Toolbox", 59.99},
        {73, 0, "Work Light", 39.99}, {74, 0, "Electric Chainsaw", 149.99},
        {75, 0, "Lawn Mower", 499.99}, {76, 0, "Leaf Blower", 149.99},
        {77, 0, "Pressure Washer", 299.99}, {78, 0, "Garden Hose", 29.99},
        {79, 0, "Solar Panel", 999.99}, {80, 0, "Battery Charger", 49.99},
        {81, 0, "Car Vacuum", 59.99}, {82, 0, "Jump Starter", 119.99},
        {83, 0, "Tire Inflator", 39.99}, {84, 0, "Car Cover", 79.99},
        {85, 0, "Roof Rack", 199.99}, {86, 0, "Camping Tent", 249.99},
        {87, 0, "Sleeping Bag", 89.99}, {88, 0, "Hiking Backpack", 119.99},
        {89, 0, "Portable Cooler", 159.99}, {90, 0, "Outdoor Grill", 399.99},
        {91, 0, "Fishing Rod", 49.99}, {92, 0, "Binoculars", 99.99},
        {93, 0, "Kayak", 499.99}, {94, 0, "Paddleboard", 599.99},
        {95, 0, "Electric Bike", 999.99}, {96, 0, "Treadmill", 1299.99},
        {97, 0, "Elliptical", 999.99}, {98, 0, "Dumbbell Set", 199.99},
        {99, 0, "Yoga Mat", 29.99}, {100, 0, "Resistance Bands", 19.99}
    };

    /* for (int i = 0; i < 100; i++)
    {
        printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d\n",
               products[i].id, products[i].name, products[i].cost, products[i].deletedLogically);
    }
 */
        fwrite(products  , sizeof(Product)*100 , 1 , ptr) ;


    
//        printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d\n",
//               products[i].id, products[i].name, products[i].cost, products[i].deletedLogically);
  
  
  
    





}



void swap2Products(Product *product1 , Product *product2) {
    Product temp ;
    
    temp.cost = product1->cost ;
    temp.deletedLogically = product1->deletedLogically ;
    temp.id = product1->id ;
    strcpy(temp.name , product1->name) ;

    product1->cost = product2->cost ;
    product1->deletedLogically = product2->deletedLogically ;
    product1->id = product2->id ;
    strcpy(product1->name , product2->name) ;
    
    product2->cost = temp.cost ;
    product2->deletedLogically = temp.deletedLogically ;
    product2->id = temp.id ;
    strcpy(product2->name , temp.name) ;

}

void shuffleProducts(Product arr[] , int length) {

    int totalTimes = 200 ;

    int i = 0 ;
    int firstIndex , secondIndex ;

    while (i < totalTimes)
    {
        firstIndex = rand() % length ;
        secondIndex = rand() % length ;

        swap2Products(arr + firstIndex , arr + secondIndex ) ;

        ++i ;
    }
     


}


void readProducts(char mode) {

    char *fileName = (mode == 's') ? "products" : "products(shuffled)" ;

    FILE *ptr = fopen(fileName , "rb+") ;
    if (ptr == NULL)
    {
        printf("couldn't open products file !\n");
        return;
    }
    

    Product products[100] ;

    
//        printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d\n",
//               products[i].id, products[i].name, products[i].cost, products[i].deletedLogically);
  
  
  
    
        fread(products  , sizeof(Product)*100 , 1 , ptr) ;


    for (int i = 0; i < 100; i++)
    {
        printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d\n",
               products[i].id, products[i].name, products[i].cost, products[i].deletedLogically);
  
  
  
    }
    
    fseek(ptr , 0 , SEEK_END) ;
    int length =  ftell(ptr)/sizeof(Product) ;
    printf("lenght = %d \n" ,length ) ;  


/* 
        shuffleProducts(products , 100) ;
    int cont ;
        printf("continue ? : ");
        scanf("%d" , &cont);
        if (!cont)
            return;
        
        

    FILE *ptr2 = fopen("products(shuffled)" , "wb+") ;
        if (ptr2==NULL)
    {
        printf("can't open products(shuffled) file !\n");
        return;
    }
    


     fwrite(products  , sizeof(Product)*100 , 1 , ptr2) ; */

}



void createFileBasedOnMetaData(MetaData metadata) {
     
    char temp[25] ;
    strcpy(temp , "./") ;
    strcat(temp , metadata.fileName) ;

    FILE *ptr = fopen(temp , "wb+");
    
        if (ptr==NULL)
    {
        printf("can't create file Name %s" , temp) ;
        return;
    } 

    FILE *product = fopen("products" , "rb+");
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
            // fwrite(&(buffer.nbBloc) , sizeof(buffer.nbBloc) , 1 , ptr);
            fwrite((buffer.product) , sizeof(Product) , buffer.nbBloc , ptr);
        printf("(after charging ) buffer.nbBloc = %d \n", buffer.nbBloc);
            free(buffer.product) ;
        
        ++j;
    }
    
    
}


/* void displayFileContent(FILE *ptr,MetaData metadata) {


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

        printf("**********************************************************************\n");

}
 */





int insertRecordTest(FILE *ptr , MetaData *metadata , Product product) {
       BlocContiguousStructure buffer ;
        
        int j = 0 ; 
        int i = 0 ;


        while ( j < metadata->blocsNumber  )
    {
        
        int totalNumBlocs = metadata->blocsNumber ;
        if (j < totalNumBlocs-1)
        {
            buffer.nbBloc = metadata->recordsNumber ;
            buffer.product = malloc(sizeof(Product)*buffer.nbBloc) ;
            }
        else if (j == totalNumBlocs-1)
        {
            buffer.nbBloc = metadata->totalNumberProducts%metadata->recordsNumber ;
            buffer.product = malloc(sizeof(Product) * (buffer.nbBloc)) ;
        }
   
   
   
   
        printf("************************** bloc number %d ********************\n", j + 1);
            int k = 0 ;
            fread(&(buffer.nbBloc) , sizeof(buffer.nbBloc) , 1 , ptr) ;
            int result = fread((buffer.product) , sizeof(Product) , metadata->recordsNumber , ptr) ;

        if (buffer.nbBloc < metadata->recordsNumber)
        {
            int u = buffer.nbBloc ;
            /*
            while (u<buffer.nbBloc)
            {
                if (buffer.product[u].deletedLogically != 0)
                    break;
                else 
                ++u ;
            }
            u = (u < buffer.nbBloc) ? u : --u  ;*/
            buffer.product[u].cost = product.cost ;
            buffer.product[u].deletedLogically = product.deletedLogically ;
            buffer.product[u].id = product.id ;
            strcpy(buffer.product[u].name , product.name );

            buffer.nbBloc++ ;

            fseek(ptr , -sizeof(Product) , SEEK_CUR ) ;
            fseek(ptr , -sizeof(buffer.nbBloc) , SEEK_CUR ) ;
            fwrite(&buffer.nbBloc, sizeof(buffer.nbBloc) , 1 , ptr ) ;
            fwrite(buffer.product, sizeof(Product) , buffer.nbBloc , ptr ) ;

            return 1 ;
        }
        
        free(buffer.product) ;
        ++j ;
    }
}




void displayFile(FILE *ptr , MetaData metadata) {
    rewind(ptr);
     
     
     
     
     
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
           // fread(&(buffer.nbBloc) , sizeof(buffer.nbBloc) , 1 , ptr) ;
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

void displayFileLinkedStruct(FILE *ptr , MetaData metadata) {
     rewind(ptr);
     
     
     
     
     
        printf("*****************************************************************************\n");

        printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    
        BlocLinkedStructure buffer ;
        
        int j = 0 ; 
        int i = 0 ;
        int index = 0 ;

        while ( i < metadata.totalNumberProducts  && index != -1)
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
            fseek(ptr , sizeof(buffer.next) * index, SEEK_SET) ;
            fseek(ptr , sizeof(Product)*metadata.recordsNumber * index, SEEK_CUR) ;
            fread(&(buffer.next) , sizeof(buffer.next) , 1 , ptr) ;
            int result = fread((buffer.product) , sizeof(Product) , metadata.recordsNumber , ptr) ;
            index = buffer.next ;
            printf("%d\n" , buffer.next) ;

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



int insertRecordTest2(FILE *ptr , MetaData *metadata , Product product) {

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
}



int main() {
    srand(time(0)) ;

    int i ;

    char sentence[100] ;










//    writeProducts() ;    
    // readProducts() ;


    MetaData metadata = {"file2"};
    metadata.totalNumberProducts = 11 ;
    metadata.recordsNumber = 3 ;
    metadata.blocsNumber = 4 ;
    metadata.globalOrganizationMode = 'c' ;
    metadata.internOrganizationMode = 'n' ;


    FILE *ptr = fopen("file2" , "rb+") ;
    if (ptr == NULL)
    {
        printf("can't open test file \n");
        return 1 ;
    }

        Product product ;

        product.cost = 5000 ;
        product.id = 1000 ;
        product.deletedLogically=0 ;
        strcpy(product.name , "we are cooked") ;


    // createFileBasedOnMetaData(metadata) ;

        // createFileLinkedStructureBasedOnMetaData(metadata) ;

        displayFileLinkedStruct(ptr , metadata) ;

        int index ;
        BlocLinkedStructure buffer ;
        fseek(ptr , sizeof(buffer.next) * index , SEEK_SET) ;



    //    displayFile(ptr , metadata) ;

/*  

    insertRecordTest2(ptr , &metadata , product) ;

    displayFile(ptr , metadata) ;
 */



/* 
    

    rewind(ptr) ;
    metadata.totalNumberProducts++ ;
    displayFile(ptr , metadata) ;
 */
    

   return 0 ;
}