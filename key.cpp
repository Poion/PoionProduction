#include "funz_gioco.h"
int i = 0;
void gestione_tasti(ALLEGRO_EVENT &ev, personaggio &pg, strumenti &tool) {
        if(ev.type == ALLEGRO_EVENT_TIMER) {
                if(tool.key[KEY_UP] && pg.bouncer_y >= 4.0) {
                        pg.bouncer_y -= 4.0;
                }

                if(tool.key[KEY_DOWN] && pg.bouncer_y <= tool.SCREEN_H - pg.BOUNCER_SIZE - 4.0) {
                        pg.bouncer_y += 4.0;
                }

                if(tool.key[KEY_LEFT] && pg.bouncer_x >= 4.0) {
                        pg.bouncer_x -= 4.0;
                }

                if(tool.key[KEY_RIGHT] && pg.bouncer_x <= tool.SCREEN_W - pg.BOUNCER_SIZE - 4.0) {
                        pg.bouncer_x += 4.0;
                }

                tool.redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                std::cout << "dio2" << '\n';
                return;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                        tool.key[KEY_UP] = true;
                        break;

                case ALLEGRO_KEY_DOWN:
                        tool.key[KEY_DOWN] = true;
                        break;

                case ALLEGRO_KEY_LEFT:
                        tool.key[KEY_LEFT] = true;
                        break;

                case ALLEGRO_KEY_RIGHT:
                        tool.key[KEY_RIGHT] = true;
                        break;
                }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                        tool.key[KEY_UP] = false;
                        break;

                case ALLEGRO_KEY_DOWN:
                        tool.key[KEY_DOWN] = false;
                        break;

                case ALLEGRO_KEY_LEFT:
                        tool.key[KEY_LEFT] = false;
                        break;

                case ALLEGRO_KEY_RIGHT:
                        tool.key[KEY_RIGHT] = false;
                        break;

                case ALLEGRO_KEY_ESCAPE:
                        std::cout << "dio1" << '\n';
                        tool.doexit = true;
                        break;
                }
        }
}
void gestione_tasti_menu(ALLEGRO_EVENT &ev, strumenti &tool) {

        if(ev.type == ALLEGRO_EVENT_TIMER) {
                if (i == 8) {


                        if(tool.key[KEY_UP]) {
                                tool.selez_menu--;
                                //std::cout << tool.selez_menu << '\n';
                        }

                        if(tool.key[KEY_DOWN]) {
                                tool.selez_menu++;
                                //std::cout << tool.selez_menu << '\n';
                        }

                        if(tool.key[KEY_LEFT]) {

                        }

                        if(tool.key[KEY_RIGHT]) {

                        }
                        i = 0;
                }
                i++;
                tool.redraw = true;
        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                std::cout << "dio2" << '\n';
                return;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
                switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                        tool.key[KEY_UP] = true;
                        //tool.selez_menu--;
                        std::cout << tool.selez_menu << '\n';
                        break;

                case ALLEGRO_KEY_DOWN:
                        tool.key[KEY_DOWN] = true;
                        //tool.selez_menu++;
                        std::cout << tool.selez_menu << '\n';
                        break;

                case ALLEGRO_KEY_LEFT:
                        tool.key[KEY_LEFT] = true;
                        break;

                case ALLEGRO_KEY_RIGHT:
                        tool.key[KEY_RIGHT] = true;
                        break;
                }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
                switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_UP:
                        tool.key[KEY_UP] = false;
                        break;

                case ALLEGRO_KEY_DOWN:
                        tool.key[KEY_DOWN] = false;
                        break;

                case ALLEGRO_KEY_LEFT:
                        tool.key[KEY_LEFT] = false;
                        break;

                case ALLEGRO_KEY_RIGHT:
                        tool.key[KEY_RIGHT] = false;
                        break;

                case ALLEGRO_KEY_ESCAPE:
                        std::cout << "dio1" << '\n';
                        tool.doexit = true;
                        break;
                }
        }
        if (tool.selez_menu == 3) {
                tool.selez_menu = 0;
        }
        else if(tool.selez_menu == -1 ) {
                tool.selez_menu = 2;
        }


}
