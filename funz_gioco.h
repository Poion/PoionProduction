#include <allegro5/allegro.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <fstream>
#include <iostream>
#ifndef _funz_gioco_h
#define _funz_gioco_h

enum MYKEYS {
        KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

struct personaggio {
        ALLEGRO_BITMAP *bouncer = NULL;
        float bouncer_x;
        float bouncer_y;
        int BOUNCER_SIZE = 32;

};

struct strumenti {
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        ALLEGRO_TIMER *timer = NULL;
        bool redraw = true;
        bool doexit = false;
        bool key[4] = { false, false, false, false };
        int SCREEN_W = 0;
        int SCREEN_H = 0;
        int controllo = 0;
        int schermata = 0;
        int selez_menu = 0;
};
void gestione_tasti(ALLEGRO_EVENT &ev, personaggio &pg, strumenti &tool);
void gestione_tasti_menu(ALLEGRO_EVENT &ev, strumenti &tool);
void initz(strumenti &tool, personaggio &pg, float FPS);
void start(strumenti &tool, personaggio &pg);
void sudoku(strumenti tool, personaggio pg);
#endif
