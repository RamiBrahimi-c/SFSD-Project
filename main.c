
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>
#include <time.h>
#include "file.h"
#include "secondMem.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



void renderText(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font  , char *result) {
  SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
    int x = 100 , y=20 ;
    SDL_Color textColor = {255,0,0,255} ;
    textSurface = TTF_RenderText_Solid(font, result, textColor);
    if (textSurface == NULL) {
                printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
                printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                return;
    }


            // Free the text surface
    SDL_FreeSurface(textSurface);


        // Only render the text if the texture was successfully created

            int textWidth = 0, textHeight = 0;
            SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
            SDL_Rect textRect = {x,y, textWidth, textHeight}; // Dynamic size based on text


                SDL_RenderFillRect(renderer, &textRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);    
}

void displayMenu(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font ) {
  SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
    int x = 20 , y=100 ;
    char *menu = "Menu : " ;
    SDL_Color textColor = {0,0,255,255} ;
    textSurface = TTF_RenderText_Solid(font, menu, textColor);
    if (textSurface == NULL) {
                printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
                printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                return;
    }


            // Free the text surface
    SDL_FreeSurface(textSurface);


        // Only render the text if the texture was successfully created

            int textWidth = 0, textHeight = 0;
            SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
            SDL_Rect textRect = {x,y, textWidth, textHeight}; // Dynamic size based on text


                SDL_RenderFillRect(renderer, &textRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);    

}

void displayOption(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font , char *menu ,int posX ,int posY) {
SDL_SetRenderDrawColor(renderer , 255,255,255,255) ;
    SDL_Rect border ;
    border.w = WINDOW_WIDTH - 40 ;
    border.h = WINDOW_HEIGHT - 150 ;
    border.x = 10 ; 
    border.y = 90 ;
    SDL_RenderDrawRect(renderer , &border) ;
SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;


    SDL_Color textColor = {0,255,0,255} ;
    textSurface = TTF_RenderText_Solid(font, menu, textColor);
    if (textSurface == NULL) {
                printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
                printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                return;
    }


            // Free the text surface
    SDL_FreeSurface(textSurface);


        // Only render the text if the texture was successfully created

            int textWidth = 0, textHeight = 0;
            SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
            SDL_Rect textRect = {posX,posY, textWidth, textHeight}; // Dynamic size based on text


                SDL_RenderFillRect(renderer, &textRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);    

}

void displayOptions(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font  ) {
  SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
    int posX = 50 , posY = 150 ;
    char *option1 = "[i] : Inisilize the Secondary Memory ." ;
    char *option2 = "[c] : create file and charge it in secondary memory ." ;
    char *option3 = "[s] : show the state of secondary memory ." ;
    char *option4 = "[a] : add record ." ;
    char *option5= "[d] : delete record (logically or physically) ." ;
  //  char *option6 = "[] : defragmenate a file." ;
    char *option7 = "[f] : delete file  ." ;
    char *option8 = "[r] : rename file  ." ;
    char *option9 = "[c] : compactage of secondary memory ." ;
    char *option10 = "[e] : empty the secondary memory  ." ;
    char *option11 = "[q] : quit the program ." ;

    int offset = 19 ;
    displayOption(renderer,textTexture, textSurface, font , option1 , posX , posY) ;
    displayOption(renderer,textTexture, textSurface, font , option2 , posX , posY + offset) ;
    displayOption(renderer,textTexture, textSurface, font , option3 , posX , posY + 2*offset) ;
    displayOption(renderer,textTexture, textSurface, font , option4 , posX , posY + 3* offset ) ;
    displayOption(renderer,textTexture, textSurface, font , option5 , posX , posY + 4 * offset) ;
  //  displayOption(renderer,textTexture, textSurface, font , option6 , posX , posY + 5 * offset ) ;
    displayOption(renderer,textTexture, textSurface, font , option7 , posX , posY + 6 * offset ) ;
    displayOption(renderer,textTexture, textSurface, font , option8 , posX , posY + 7 * offset) ;
    displayOption(renderer,textTexture, textSurface, font , option9 , posX , posY + 8 * offset ) ;
    displayOption(renderer,textTexture, textSurface, font , option10 , posX , posY + 9 * offset) ;
    displayOption(renderer,textTexture, textSurface, font , option11 , posX , posY + 10 * offset) ;
/*
 */}



void displaySecondaryMem(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font  ,TTF_Font* font3 , AllocationTable allocationTable ) {
  SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
    int x = 200 , y=20 ;
    char *title = "Secondary Memory" ;
    SDL_Color textColor = {255,0,0,255} ;
    textSurface = TTF_RenderText_Solid(font, title, textColor);
    if (textSurface == NULL) {
                printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
                printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                return;
    }


            // Free the text surface
    SDL_FreeSurface(textSurface);


        // Only render the text if the texture was successfully created

            int textWidth = 0, textHeight = 0;
            SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
            SDL_Rect textRect = {x,y, textWidth, textHeight}; // Dynamic size based on text


                SDL_RenderFillRect(renderer, &textRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);      


        int offset = 50 ;
        char string[20] ;
        for (int i = 0; i < MAX_FILES; i++)
        {

            
            SDL_Rect rect ;
            rect.h=100 ;
            rect.w=80 ;
            rect.x=i*rect.w+offset ;
            rect.y=100 ;
            

            if (allocationTable.files[i].used)
            {
                SDL_SetRenderDrawColor(renderer , 0,255,0,255) ;
                SDL_RenderFillRect(renderer , &rect) ;
            }
            else
            {
                SDL_SetRenderDrawColor(renderer , 255,0,0,255) ;
                SDL_RenderFillRect(renderer , &rect) ;
            }
            

            // SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
            int x = rect.x+30 , y=rect.y  ;
            
                sprintf(string , "file %d" , i) ;
            SDL_Color textColor = {255,255,255,255} ;
            textSurface = TTF_RenderText_Solid(font3, string, textColor);
            if (textSurface == NULL) {
                        printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                        return;
            }
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (textTexture == NULL) {
                        printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                        return;
            }


                    // Free the text surface
            SDL_FreeSurface(textSurface);


                // Only render the text if the texture was successfully created

                    int textWidth = 0, textHeight = 0;
                    SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
                    SDL_Rect textRect = {x,y, textWidth, textHeight}; // Dynamic size based on text


                        SDL_RenderFillRect(renderer, &textRect);
                    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);      


        }
        
}




void returntoMainMenu(SDL_Renderer *renderer ,    SDL_Texture* textTexture ,SDL_Surface* textSurface , TTF_Font* font , char *text ) {
    SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
    int posX=WINDOW_WIDTH/2-WINDOW_WIDTH/4 , posY=WINDOW_HEIGHT-40 ;

    SDL_Color textColor = {0,255,0,255} ;
    textSurface = TTF_RenderText_Solid(font, text, textColor);
    if (textSurface == NULL) {
                printf("Unable to createtextSurface! SDL_Error: %s\n", SDL_GetError());
                return;
    }
    textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    if (textTexture == NULL) {
                printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
                return;
    }


            // Free the text surface
    SDL_FreeSurface(textSurface);


        // Only render the text if the texture was successfully created

            int textWidth = 0, textHeight = 0;
            SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);
            SDL_Rect textRect = {posX,posY, textWidth, textHeight}; // Dynamic size based on text


                SDL_RenderFillRect(renderer, &textRect);
            SDL_RenderCopy(renderer, textTexture, NULL, &textRect);    


}







int main() {
    srand(time(NULL));

    AllocationTable allocationTable  ;

    readAllocationTable(&allocationTable) ;
    

    SDL_Init(0) ;
    if (TTF_Init() == -1) {
        printf("TTF_Init: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Files Management System Simulator" ,  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH , WINDOW_HEIGHT , 0) ;
    if (window == NULL)
    {
        printf("can't create window %s \n" , SDL_GetError()) ;
        SDL_DestroyWindow(window) ;
        return -1 ;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window , -1 , 0) ;
    if (renderer == NULL)
    {
        printf("can't create renderer %s \n" , SDL_GetError()) ;
        SDL_DestroyRenderer(renderer) ;
        SDL_DestroyWindow(window) ;
        return -1 ;
    }
   TTF_Font* font = TTF_OpenFont("fonts/bedstead.otf", 24);
    if (font == NULL) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
   TTF_Font* font2 = TTF_OpenFont("fonts/bedstead.otf", 18);
    if (font == NULL) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }
   TTF_Font* font3 = TTF_OpenFont("fonts/LinuxLibertineBold-BYM3.ttf", 16);
    if (font == NULL) {
        printf("Failed to load font! TTF_Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Color textColor = {255, 255, 255, 255}; // White color
    SDL_Texture* textTexture = NULL;
    SDL_Surface* textSurface=NULL;

    char result[] = "Files Management System Simulator";

    int x = 40 , y=70 ;
    char *menu = "[i] : Inisilize the Secondary Memory ." ;


    SDL_Rect rect  ;


    bool running = true ;
    SDL_Event event ;

    int state=0 ;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                writeAllocationTable(allocationTable) ;
                running = false ;
                break;
            }
            else if(event.type == SDL_KEYDOWN && state != 1)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        writeAllocationTable(allocationTable) ;
                        running=false ;
                            break;
                    case SDLK_p : // print allocation table
                       system("clear");
                        printAllocationTable(allocationTable) ;
                            break;                            
                    case SDLK_q: // save allocation table and exit program
                        writeAllocationTable(allocationTable) ;
                        running=false ;
                            break;
                    case SDLK_c: // create file and charge it to allocation table 
                        system("clear");
                        if (allocationTable.length + 1 < MAX_FILES)
                        {
                            char temp_c[MAX_SIZE_FILENAME] ;
                            printf("enter file name : ") ;
                            fgets(temp_c , sizeof(temp_c) , stdin) ;

                            cleanString(temp_c) ;
                            if (isTherethisFile(allocationTable , temp_c)<0) 
                            {
                                createFile(temp_c) ;
                                updateAllocationTable(&allocationTable , 1 , temp_c) ;                        
                            }
                            else
                            {
                                printf("THE FILE ALREADY EXIST\n") ;
                            }
                            

                        } else {
                            printf("THE DISK IS FULL\n") ;
                        }
                        
                            break;
                    case SDLK_i: // inisilize the disk
                        discInisilize(&allocationTable) ;
                        
                            break;
                    case SDLK_s: // switch between the gui 
                        state=(state == 1) ? 0 : 1 ;
                            break;
                    case SDLK_a:
                        system("clear");
                        char temp_a[MAX_SIZE_FILENAME] ;
                        printf("enter file name : ");
                        fgets(temp_a , sizeof(temp_a) , stdin) ;
                        cleanString(temp_a) ;
                        if (isTherethisFile(allocationTable  , temp_a) < 0)
                        {
                            printErrorMessage("THERE IS NOT FILE WITH THIS NAME" , RED) ;
                        }
                        else
                        {
                            insertRecord(temp_a) ;
                            
                        }
                         
                            break;
                    case SDLK_d:
                        system("clear");
                        int i ;
                        printf("0.Logical deletion \t 1.Physical deletion \n") ;
                        scanf("%d" , &i) ;
                        (   i==1) ? deleteRecordPhysically(" " , 0) : deleteRecordLogically(" " , 0) ;

                            break;
                    // valid
                    case SDLK_f:
                        system("clear");
                        char temp_f[20] ;
                        printf("enter file Name : \n") ;
                        fgets(temp_f ,sizeof(temp_f) , stdin ) ;
                        cleanString(temp_f) ;
                         int result = isTherethisFile(allocationTable , temp_f) ;
                         if (result < 0)
                         {
                            printErrorMessage("THIS FILE DOESN'T EXIST" , RED) ;
                         }
                         else
                         {
                            
                            int k = 0 ;
                            ( k = deleteFile(temp_f) > 0 ) ? updateAllocationTable(&allocationTable , 0 , temp_f) : 1 ;
                            if (k>0) deleteFileMetaData(temp_f) ;
                         }
                         
                            break;
                    
                    case SDLK_r:
                        system("clear");
                        char temp[20] , temp2[20];
                        printf("enter file Name : \n") ;
                        fgets(temp ,sizeof(temp) , stdin ) ;
                        cleanString(temp) ;
                         result = isTherethisFile(allocationTable , temp) ; 
                        if (result > -1)
                        {
                            printf("enter new file Name : \n") ;
                            fgets(temp2 ,sizeof(temp2) , stdin ) ;
                            cleanString(temp2) ;
                                    
                            if(renameFile(temp , temp2)>0) renameFileMetaData(temp , temp2) ;
                            strcpy(allocationTable.files[result].fileName , temp2) ;
                        }
                        else
                        {
                            COLORS color = RED ;
                            printErrorMessage("THE FILE DOESN'T EXIST  " , color) ;
                            /* code */
                        }
                        

    

                            break;
                    case SDLK_e:
                        system("clear");
                        emptySecondaryMemory() ;
                        formatAllocationTable(&allocationTable) ;
                            break;
                    case SDLK_j :

                        char temp_j[MAX_SIZE_FILENAME] ;
                        printf("enter file name : ");
                        fgets(temp_j , sizeof(temp_j) , stdin) ;
                        cleanString(temp_j) ;

                        if (isTherethisFile(allocationTable , temp_j)<0)
                        {
                            printErrorMessage("THERE IS NOT FILE WITH THIS NAME" , RED) ;
                        }
                        else
                        {
                            displayFileContent(temp_j) ;
                            
                        }
                        
                            break;                           

                    case SDLK_y:
                            system("clear") ;
                        break;
                    case SDLK_z :
                        char temp_z[MAX_SIZE_FILENAME] ;
                        printf("enter fileName : ");
                        fgets(temp_z , sizeof(temp_z) , stdin) ;
                        cleanString(temp_z) ;
                        if (isTherethisFile(allocationTable , temp_z) < 0)
                        {
                            printErrorMessage("THIS FILE DOESN'T EXIST" , RED) ;
                        }
                        else
                        {
                            printMetadata(temp_z) ;
                        }
                        
                        break;    
                    default :
                        printf("%s\n" , allocationTable.files[2].fileName);
                                break;
                }
                    //system("clear");
            } else if (event.type == SDL_KEYDOWN && state == 1) {
                switch (event.key.keysym.sym)
                {
                case SDLK_s:
                    state = 0 ;
                    break;
                case SDLK_q :
                    running=0 ;
                    break;
                default:
                    break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
        SDL_RenderClear(renderer);

        // start
        // SDL_RenderDrawRect(renderer , &rect) ;

            switch (state)
            {
            case 1:
                displaySecondaryMem(renderer , textTexture , textSurface , font , font3 , allocationTable) ;
                //displayOption(renderer , textTexture , textSurface , font3 , "PRESS [S] TO RETURN TO MAIN MENU" , 200 , WINDOW_HEIGHT-50) ;
                returntoMainMenu(renderer , textTexture , textSurface , font3 ,"PRESS [S] TO RETURN TO MAIN MENU" ) ;
                break;
            default:
                renderText(renderer,textTexture, textSurface, font  , result);
                displayMenu(renderer,textTexture, textSurface, font2) ;
                displayOptions(renderer,textTexture, textSurface, font3 ) ;
                break;
            }
        

        
        // end

        SDL_RenderPresent(renderer) ;

        SDL_Delay(200) ;

    }



    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;



    return 0 ;
}

