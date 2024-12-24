#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(void)
{
	//variables
	int width = 640;
	int height = 480;
	bool done = false;
	int imageRad = 20;
	
	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_BITMAP *image = NULL;

	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_primitives_addon();

	image = al_create_bitmap(imageRad * 2, imageRad * 2);

	al_set_target_bitmap(image);

	al_clear_to_color(al_map_rgb(127, 127, 127));

	al_draw_filled_rectangle(imageRad, imageRad - 9, imageRad + 10, imageRad - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(imageRad, imageRad + 9, imageRad + 10, imageRad + 7, al_map_rgb(255, 0, 0));

	al_draw_filled_triangle(imageRad - 12, imageRad - 17, imageRad + 12, imageRad, imageRad - 12, imageRad + 17, al_map_rgb(0, 255, 0));
	al_draw_filled_rectangle(imageRad - 12, imageRad - 2, imageRad + 15, imageRad + 2, al_map_rgb(0, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		al_draw_bitmap(image, width / 2, height / 2, 0);
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}