#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <time.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


int main() {
    srand(time(NULL));
    SDL_Init(0) ;

    SDL_Window *window = SDL_CreateWindow("haha" ,  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH , WINDOW_HEIGHT , 0) ;
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
    

    SDL_Rect rect  ;
    rect.h = 50 ;
    rect.w = 50 ;
    rect.x = 100 ;
    rect.y = 100 ;


    bool running = true ;
    SDL_Event event ;


    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false ;
                break;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                    running=false ;
                    break;


                }

            }
        }

        SDL_SetRenderDrawColor(renderer , 0,0,0,255) ;
        SDL_RenderClear(renderer);

        // start
        // SDL_RenderDrawRect(renderer , &rect) ;
        SDL_Color color ;
        color.a = 255 ;
        color.r = rand()% 255  + 1;
        color.g = rand()% 255  + 1 ;
        color.b = rand()% 255  + 1 ;
        SDL_SetRenderDrawColor(renderer , color.r ,color.g,color.b,255) ;
        SDL_RenderFillRect(renderer , &rect) ;

        // end

        SDL_RenderPresent(renderer) ;

        SDL_Delay(200) ;

    }



    SDL_DestroyRenderer(renderer) ;
    SDL_DestroyWindow(window) ;



    return 0 ;
}

