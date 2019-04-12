#ifndef HERO1_H
#define HERO1_H

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct 
{
	SDL_Surface *heroimg ;
	SDL_Rect  heropos;
}hero; 

hero inithero ();
void afficherhero(hero hr,SDL_Surface *screen);



#endif
