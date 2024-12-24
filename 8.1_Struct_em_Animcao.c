#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct sprite
{
	float x;
	float y;
	float velX;
	float velY;
	int dirX;
	int dirY;

	int maxFrame;
	int curFrame;
	int frameCount;
	int frameDelay;
	int frameWidth;
	int frameHeight;
	int animationColumns;
	int animationDirection;

	ALLEGRO_BITMAP *image;
} Sprite;

int main(void)
{
	//variables
	int width = 640;
	int height = 480;
	bool done = false;

	Sprite dragon;

	dragon.x = width / 2;
	dragon.y = height / 2;
	dragon.velX = 5;
	dragon.dirX = -1;
	dragon.dirY = 1;

	dragon.maxFrame = 8;
	dragon.curFrame = 0;
	dragon.frameCount = 0;
	dragon.frameDelay = 5;
	dragon.frameWidth = 128;
	dragon.frameHeight = 128;
	dragon.animationColumns = 8;
	dragon.animationDirection = 1;

	//allegro variable
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer;
	ALLEGRO_BITMAP *image;
	
	//program init
	if(!al_init())										//initialize Allegro
		return -1;

	display = al_create_display(width, height);			//create our display object

	if(!display)										//test display object
		return -1;

	//addon init
	al_install_keyboard();
	al_init_image_addon();

	image = al_load_bitmap("sprite_sheet_demo.bmp");
	al_convert_mask_to_alpha(image, al_map_rgb(106, 76, 48));

	dragon.image = image;
	
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);

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
				dragon.animationDirection = 1;
				dragon.dirX = -1;
				break;
			case ALLEGRO_KEY_RIGHT:
				dragon.animationDirection = -1;
				dragon.dirX = 1;
				break;
			case ALLEGRO_KEY_UP:
				
				break;
			case ALLEGRO_KEY_DOWN:
				
				break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			if(++dragon.frameCount >= dragon.frameDelay)
			{
				dragon.curFrame += dragon.animationDirection;
				if(dragon.curFrame >= dragon.maxFrame)
					dragon.curFrame = 0;
				else if(dragon.curFrame <= 0)
					dragon.curFrame = dragon.maxFrame - 1;
				

				dragon.frameCount = 0;
			}

			dragon.x += dragon.velX * dragon.dirX;

			if(dragon.x <= 0 - dragon.frameWidth)
				dragon.x = width;
		}
		
		al_draw_bitmap_region(dragon.image, dragon.curFrame * dragon.frameWidth, 0, dragon.frameWidth, dragon.frameHeight, dragon.x, dragon.y, 0);
						
		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	al_destroy_bitmap(image);
	al_destroy_event_queue(event_queue);
	al_destroy_display(display);						//destroy our display object

	return 0;
}