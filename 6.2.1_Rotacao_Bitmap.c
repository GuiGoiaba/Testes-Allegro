#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main(void)
{
	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	int imageWidth = 20;
	int imageHeight = 20;

	float degree = 0;
	
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
	al_init_image_addon();

	image = al_load_bitmap("eba.jpeg");

	imageWidth = al_get_bitmap_width(image);
	imageHeight = al_get_bitmap_height(image);

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
			case ALLEGRO_KEY_LEFT:
				degree -= 10;
				if(degree <= 0)
					degree = 360;
				break;
			case ALLEGRO_KEY_RIGHT:
				degree += 10;
				if(degree >= 360)
					degree = 0;
				break;
			}
		}

		al_draw_rotated_bitmap(image, imageWidth / 2, imageHeight / 2, width / 2, height / 2, degree * 3.14159 / 180, 0);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}