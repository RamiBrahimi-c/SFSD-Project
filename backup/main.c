#include "../file.h"


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

        printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    
        BlocContiguousStructure buffer ;
        int j = 0 ; int y = 0 ;
        int i = 0 ;
    while ( i < metadata.totalNumberProducts)
    {
        printf("************************** bloc number %d ********************\n", y++);
            int k = 0 ;
        while (k<metadata.recordsNumber && i < metadata.totalNumberProducts)
        {
            fread(&(buffer.product[k]) , sizeof(buffer.product[k]) , 1 , product) ;
            
           printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                         buffer.product[k].id , buffer.product[k].name   ,buffer.product[k].cost ,buffer.product[k].deletedLogically  ) ;
            // printf("i=%d\tj=%d\tk=%d\n" , i , j , k) ;
            ++k  ;++i ; ++j;
        }
        buffer.nbBloc = k ;
            fwrite(&(buffer) , sizeof(buffer) , 1 , ptr);
        printf("after charging k=%d \n", buffer.nbBloc);
    }
    
    
}




// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************
// ***************************************************************************************************



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

        printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    
        BlocLinkedStructure buffer ;
        int j = 1 ; int y = 0 ;
        int i = 0 ;
    while ( i < metadata.totalNumberProducts)
    {
        printf("************************** bloc number %d ********************\n", y++);
            int k = 0 ;
        while (k<metadata.recordsNumber && i < metadata.totalNumberProducts)
        {
            fread(&(buffer.product[k]) , sizeof(buffer.product[k]) , 1 , product) ;
            
           printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                         buffer.product[k].id , buffer.product[k].name   ,buffer.product[k].cost ,buffer.product[k].deletedLogically  ) ;
            // printf("i=%d\tj=%d\tk=%d\n" , i , j , k) ;
            ++k  ;++i ;
        }
        buffer.nbBloc = k ;
        buffer.next = j++ ;
            fwrite(&(buffer) , sizeof(buffer) , 1 , ptr);
        printf("after charging k=%d \n", buffer.nbBloc);
    }
    
    
}




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

void readProducts() {

    FILE *ptr = fopen("products" , "rb+") ;
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

}



void displayFileContent(MetaData metadata) {
        char temp[25] ;
    strcpy(temp , "./") ;
    strcat(temp , metadata.fileName) ;

    FILE *ptr = fopen(temp , "rb+");
    
        if (ptr==NULL)
    {
        printf("can't create file Name %s" , temp) ;
        return;
    } 


        printf("total number = %d blockage factor = %d \n" , metadata.totalNumberProducts , metadata.recordsNumber) ;
    
    
        BlocContiguousStructure buffer ;
        int j = 0 ; int y = 0 ;
        int i = 0 ;
        while ( i < metadata.totalNumberProducts)
    {
        printf("************************** bloc number %d ********************\n", y++);
            int k = 0 ;
            fread(&(buffer) , sizeof(buffer) , 1 , ptr) ;
            while (k<metadata.recordsNumber && i < metadata.totalNumberProducts)
        {
            
            printf("Product ID: %d, Name: %s, Cost: %.2f, Deleted: %d  \n" , 
                         buffer.product[k].id , buffer.product[k].name   ,buffer.product[k].cost ,buffer.product[k].deletedLogically  ) ;
            printf("i=%d\tj=%d\tk=%d\n" , i , j , k) ;
            ++k  ;++i ; ++j;
        }
        buffer.nbBloc = k ;
        printf("after charging k=%d \n", buffer.nbBloc);
    }

        fseek(ptr , 0 , SEEK_END) ;
        int length =  ftell(ptr)/sizeof(Product) ;
        printf("lenght = %d \n" ,length ) ;  


}


int main() {


    int i ;

    char sentence[100] ;


//    writeProducts() ;    
    // readProducts() ;


    MetaData metadata = {"testing"};
    metadata.totalNumberProducts = 11 ;
    metadata.recordsNumber = 3 ;
    displayFileContent(metadata) ;
  //  createFileBasedOnMetaData(metadata) ;
    // writeProducts() ;
    // readProducts() ;

/* 


    FILE *ptr = fopen("../meta data/test" , "rb+") ;
    if (ptr==NULL)
    {
        printf("can't open meta data file\n");
        return 1;
    }
    MetaData metadata ;
    fread(&metadata , sizeof(metadata) , 1 , ptr) ;
    fseek(ptr , 0 , SEEK_END) ;
    printf("size : %d\n" , ftell(ptr)/sizeof(metadata) ) ;
    printf("blocs number  filename  first bloc number  global organization mode  intern organization mode  records number\n");
    printf("%d\t%s\t%d\t%c\t%c\t%d\n" , metadata.blocsNumber , metadata.fileName , metadata.firstBlocAddress , metadata.globalOrganizationMode , metadata.internOrganizationMode , metadata.recordsNumber ) ;
 */ 
/* 
    printf("enter number : ");
    scanf("%d" , &i) ;
    getchar() ;

    printf("enter sentence : ");
    fgets(sentence , sizeof(sentence) , stdin) ;
    sentence[strlen(sentence)-1]= sentence[strlen(sentence)-1]=='\n' ? '\0' : sentence[strlen(sentence)-1] ;

    printf("you entered %d and %s \n" , i , sentence) ;
 */
    return 0 ;
}