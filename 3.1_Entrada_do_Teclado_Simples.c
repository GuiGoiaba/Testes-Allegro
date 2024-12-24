#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(void)
{
	int largura = 720;
	int altura = 480;
	
	bool completo = false;
	int pos_x = largura / 2;
	int pos_y = altura / 2;

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_EVENT_QUEUE *evento = NULL;

	if(!al_init())
		return -1;

	janela = al_create_display(largura, altura);

	if(!janela)
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();		//para aceitar a entrada do teclado

	evento = al_create_event_queue();

	al_register_event_source(evento, al_get_keyboard_event_source());

	while(!completo)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(evento, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					pos_y -= 10;
					break;
				case ALLEGRO_KEY_DOWN:
					pos_y += 10;
					break;
				case ALLEGRO_KEY_RIGHT:
					pos_x += 10;
					break;
				case ALLEGRO_KEY_LEFT:
					pos_x -= 10;
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				completo = true;
		}

		al_draw_filled_rectangle(pos_x, pos_y, pos_x + 30, pos_y + 30, al_map_rgb(255,0,255));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_event_queue(evento);
	al_destroy_display(janela);						//destroy our janela object

	return 0;
}