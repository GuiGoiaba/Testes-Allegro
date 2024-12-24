#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main(void)
{
	int width = 640;
	int height = 480;

	bool done = false;
	int count = 0;

	int FPS = 60;
	
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *font18 = al_create_builtin_font();

	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		count++;

		al_draw_textf(font18, al_map_rgb(255, 255, 255), width / 2, height / 2, ALLEGRO_ALIGN_CENTRE,
			"Frames: %i", count);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);						//destroy our display object

	return 0;
}