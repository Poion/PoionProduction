#include "funz_gioco.h"

void initz(strumenti &tool,personaggio &pg, float FPS){
        ALLEGRO_DISPLAY_MODE disp_data; //serve per mettere modalita' fullscreen e per
                                        //prendere larghezza/altezza dello schermo

        if(!al_init()) {
                tool.controllo = -1;
                return;
        }

        if(!al_init_image_addon()) {
                tool.controllo = -1;
                return;
        }

        if(!al_install_keyboard()) {
                tool.controllo = -1;
                return;
        }

        tool.timer = al_create_timer(1.0 / FPS);

        if(!tool.timer) {
                tool.controllo = -1;
                return;
        }

        al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);
        al_set_new_display_flags(ALLEGRO_FULLSCREEN);
        tool.SCREEN_W = disp_data.width;
        tool.SCREEN_H = disp_data.height;
        tool.display = al_create_display(disp_data.width, disp_data.height);

        if(!tool.display) {
                std::cout << "al_create_display non funziona" << '\n';
                tool.controllo = -1;
                return;
        }

        pg.bouncer_x = tool.SCREEN_W / 2.0 - pg.BOUNCER_SIZE / 2.0;
        pg.bouncer_y = tool.SCREEN_H / 2.0 - pg.BOUNCER_SIZE / 2.0;
        pg.bouncer = al_load_bitmap("cat.png");
        if(!pg.bouncer) {
                tool.controllo = -1;
                std::cout << "dios" << '\n';
                al_destroy_display(tool.display);
                al_destroy_timer(tool.timer);
                return;
        }

        tool.menu[0] = al_load_bitmap("img//1.png");
        tool.menu[1] = al_load_bitmap("img//2.png");
        tool.menu[2] = al_load_bitmap("img//3.png");
        tool.menu[3] = al_load_bitmap("img//4.png");
        for (int i = 0; i <= 3; i++) {
                if(!tool.menu[i]) {
                        tool.controllo = -1;
                        std::cout << i << '\n';
                        for (int b = 0; i <= b; b++) {
                                al_destroy_bitmap(tool.menu[b]);
                        }
                        al_destroy_bitmap(pg.bouncer);
                        al_destroy_display(tool.display);
                        al_destroy_timer(tool.timer);
                        return;
                }
        }

        al_set_target_bitmap(al_get_backbuffer(tool.display));

        tool.event_queue = al_create_event_queue();

        if(!tool.event_queue) {
                tool.controllo = -1;
                for (int i = 0; 3 <= i; i++) {
                        al_destroy_bitmap(tool.menu[i]);
                }
                al_destroy_bitmap(pg.bouncer);
                al_destroy_display(tool.display);
                al_destroy_timer(tool.timer);
                return;
        }

        al_register_event_source(tool.event_queue, al_get_display_event_source(tool.display));

        al_register_event_source(tool.event_queue, al_get_timer_event_source(tool.timer));

        al_register_event_source(tool.event_queue, al_get_keyboard_event_source());

        al_clear_to_color(al_map_rgb(0,0,0));

        al_flip_display();

        al_start_timer(tool.timer);
}
void start(strumenti &tool, personaggio &pg) {

        ALLEGRO_EVENT ev;
        al_wait_for_event(tool.event_queue, &ev);
        //gestione_tasti(ev,pg,tool);
        gestione_tasti_menu(ev,tool);
        if(tool.redraw && al_is_event_queue_empty(tool.event_queue)) {
                tool.redraw = false;

                al_clear_to_color(al_map_rgb(0,0,0));

                al_draw_bitmap(tool.menu[0], 100, 100, 0);
                al_draw_bitmap(tool.menu[1], 100, 200, 0);
                al_draw_bitmap(tool.menu[2], 100, 300, 0);
                al_draw_bitmap(tool.menu[3], 100, 400, 0);
                if (tool.selez_menu == 0)
                        al_draw_scaled_bitmap(pg.bouncer, 0, 0, al_get_bitmap_width(pg.bouncer), al_get_bitmap_height(pg.bouncer),pg.bouncer_x, pg.bouncer_y,al_get_display_width(tool.display)/10, al_get_display_height(tool.display)/10, 0);
                if (tool.selez_menu == 1)
                        al_draw_scaled_bitmap(pg.bouncer, 0, 0, al_get_bitmap_width(pg.bouncer), al_get_bitmap_height(pg.bouncer),pg.bouncer_x, pg.bouncer_y+100,al_get_display_width(tool.display)/10, al_get_display_height(tool.display)/10, 0);
                if (tool.selez_menu == 2)
                        al_draw_scaled_bitmap(pg.bouncer, 0, 0, al_get_bitmap_width(pg.bouncer), al_get_bitmap_height(pg.bouncer),pg.bouncer_x, pg.bouncer_y+200,al_get_display_width(tool.display)/10, al_get_display_height(tool.display)/10, 0);
                al_flip_display();

        }
        return;
}
void sudoku(strumenti tool,personaggio pg) {
        al_destroy_bitmap(pg.bouncer);
        al_destroy_timer(tool.timer);
        al_destroy_display(tool.display);
        al_destroy_event_queue(tool.event_queue);
        for (int i = 0; 3 <= i; i++) {
                al_destroy_bitmap(tool.menu[i]);
        }
}
