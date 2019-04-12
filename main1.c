#include <SDL/SDL.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "hero1.c"
#include "hero1.h"

void pause()
{
    int continuer = 1;
    SDL_Event event;


    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

int main()
{ 
	int go=1;
	SDL_Event event;
	SDL_Surface *screen=NULL,*background=NULL; 
SDL_Rect posback;
	hero hr;
    posback.x=0;
posback.y=0;

    SDL_Init(SDL_INIT_VIDEO);
    //screen = SDL_SetVideoMode(800,600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    screen = SDL_SetVideoMode(1600,400, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
     
    hr=inithero ();
background=SDL_LoadBMP("background.bmp");
SDL_BlitSurface(background,NULL,screen,&posback);
    SDL_EnableKeyRepeat(10,10);
    while (go==1)
	{
		SDL_PollEvent(&event);
		{
			switch (event.type)
			{
				case SDL_QUIT:
					go=0;
					break;
                        case SDL_MOUSEMOTION:
                    hr.heropos.x = event.motion.x ;
                    hr.heropos.y = event.motion.y ;
                    break;

				case SDL_KEYDOWN :
					switch(event.key.keysym.sym)
					{	
						case SDLK_RIGHT :
							hr.heropos.x+=5;	
							break;
						case SDLK_LEFT:
							hr.heropos.x-=5;	
							break;
						case SDLK_UP:
							hr.heropos.y-=5;	
							break;
						case SDLK_DOWN:
							hr.heropos.y+=5;	
							break;

					}
				   break;
			}
		}
	
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
SDL_BlitSurface(background,NULL,screen,&posback);
	//SDL_BlitSurface(hr.heroimg,NULL,screen,&hr.heropos);
	afficherhero(hr,screen);
	SDL_Flip(screen);
	//pause();
    }
	SDL_Quit();
	return 0 ;
}

