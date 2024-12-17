#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

enum Tecla {cima, baixo, esquerda, direita};

int main(){
    int altura = 640;
    int largura = 480;
    int pos_y = altura/2;
    int pos_x = largura/2;
    bool looping_finalizou = false;
    bool teclas[4] = {false, false, false, false};
    ALLEGRO_DISPLAY* Janela = NULL;
    ALLEGRO_EVENT_QUEUE *Evento = NULL;

    if(!al_init())
    {
        return -1;
    }

    Janela = al_create_display(altura, largura);
    if(!Janela)
    {
        return -2;
    }

    al_init_primitives_addon();
    al_install_keyboard();

    Evento = al_create_event_queue();

    al_register_event_source(Evento, al_get_keyboard_event_source());
    al_register_event_source(Evento, al_get_display_event_source(Janela));

    while(!looping_finalizou)
    {
        ALLEGRO_EVENT Dentro_do_looping;
        al_wait_for_event(Evento, &Dentro_do_looping);
        if(Dentro_do_looping.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch(Dentro_do_looping.keyboard.keycode)
            {
                case ALLEGRO_KEY_UP:
                    teclas[cima] = true;
                    break;
                case ALLEGRO_KEY_DOWN:
                    teclas[baixo] = true;
                    break;
                case ALLEGRO_KEY_LEFT:
                    teclas[esquerda] = true;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    teclas[direita] = true;
                    break;
            }
        }
        else if(Dentro_do_looping.type == ALLEGRO_EVENT_KEY_UP)
        {
            if(Dentro_do_looping.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
            {
                looping_finalizou = true;
            }
        }
        else if(Dentro_do_looping.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            looping_finalizou = true;
        }
        al_draw_filled_rectangle(pos_x, pos_y, pos_x + 10, pos_y + 30, al_map_rgb(255, 255, 255));
        al_flip_display();
        al_clear_to_color(al_map_rgb(0,0,0));
    }

    al_destroy_display(Janela);
    return 0;
}