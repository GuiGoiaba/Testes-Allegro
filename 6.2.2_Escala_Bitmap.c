#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main(void)
{
	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	int imageWidth = 0;
	int imageHeight = 0;

	int x = 0;
	int y = 0;

	float scale = 2;
	
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

	x = width / 2 - imageWidth / 2;
	y = height / 2 - imageHeight / 2;

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
			case ALLEGRO_KEY_UP:
				scale += .5f;
				break;
			case ALLEGRO_KEY_DOWN:
				scale -= .5f;
				break;
			case ALLEGRO_KEY_LEFT:
				
				break;
			case ALLEGRO_KEY_RIGHT:
				
				break;
			}
		}

		al_draw_scaled_bitmap(image, 0, 0, imageWidth, imageHeight, x, y, imageWidth * scale, imageHeight * scale, 0);


		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}