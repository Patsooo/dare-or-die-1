#include "hero1.h"

hero inithero ()
{
	hero hr;
	hr.heroimg = IMG_Load("Aliza1.png");
        hr.heropos.x=0;
        hr.heropos.y=0;
	return hr;
}
void afficherhero(hero hr,SDL_Surface *screen)
{
	SDL_BlitSurface(hr.heroimg,NULL,screen,&hr.heropos);
	SDL_Flip(screen);
}

