#include <stdio.h>
#include <allegro5/allegro.h>
#include "list.h"
#include "dynobject.h"

static void update();
void draw();
static void loadContent();
int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	dynObjectList *objList = new dynObjectList();

	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	display = al_create_display(640, 480);

	if(!display) {
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}


	bool gameEnd = false;
	double currentTime = al_get_time();
	loadContent();

	al_set_target_backbuffer(display);
	al_clear_to_color(al_map_rgb(0,255,0));
	al_flip_display();

    while (!gameEnd) {

	    update();
	    draw();
	    al_rest(.01 - (al_get_time() - currentTime));

    }

    al_destroy_display(display);
    return 0;
}

static void update() {

	//update stuff here

}

void draw() {

	//draw stuff here
	al_flip_display();

}

static void loadContent() {

	//load content here

}