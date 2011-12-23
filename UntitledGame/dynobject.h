#ifndef ADD_H
#define ADD_H

public class dynObject {
	
public:
	int id;

	dynObject();
	dynObject(int X,int Y,int DEPTH,ALLEGRO_BITMAP *BITMAP);
	void move(int x2, int y2);
	void draw();
	void setBitmap(ALLEGRO_BITMAP *bitmap2);
	bool collisionObject(dynObject obj, bool precise);
	bool collisionPoint(int x2, int y2, bool precise);

private:
	int x, y, depth, width, height;
	static int nextID;
	ALLEGRO_BITMAP *bitmap;

};

int dynObject::nextID = 0;

dynObject::dynObject() {

	x = 0;
	y = 0;
	depth = 0;
	bitmap = al_create_bitmap(16, 16);
	width = 16;
	height = 16;
	id = nextID;
	nextID++;

}

dynObject::dynObject(int X,int Y,int DEPTH,ALLEGRO_BITMAP *BITMAP) {

	x = X;
	y = Y;
	depth = DEPTH;
	bitmap = al_clone_bitmap(BITMAP);
	width = al_get_bitmap_width(BITMAP);
	height = al_get_bitmap_height(BITMAP);
	id = nextID;
	nextID++;

}

void dynObject::move(int x2, int y2) {

	x = x2;
	y = y2;

}

void dynObject::draw() {

	al_draw_bitmap(bitmap, x, y, NULL);

}

void dynObject::setBitmap(ALLEGRO_BITMAP *bitmap2) {

	bitmap = al_clone_bitmap(bitmap2);

}

bool dynObject::collisionObject(dynObject obj, bool precise) {

		if (x < obj.x + obj.width && x + width > obj.x && y < obj.y + obj.height && y + height > obj.y) {

			if (!precise)
				return true;
			else {
	
				al_lock_bitmap(bitmap,ALLEGRO_PIXEL_FORMAT_ANY,ALLEGRO_LOCK_READONLY);
				al_lock_bitmap(obj.bitmap,ALLEGRO_PIXEL_FORMAT_ANY,ALLEGRO_LOCK_READONLY);
				unsigned char *r, *g, *b, *a;
				for(int x1 = 0; x1 < width; x1++) {
	
					for(int y1 = 0; y1 < height; y1++) {
	
						al_unmap_rgba(al_get_pixel(bitmap, x1, y1),r,g,b,a);
						if (a != 0) {
	
							for(int x2 = 0; x2 < obj.width; x2++) {
	
								for(int y2 = 0; y2 < obj.height; y2++) {
	
									al_unmap_rgba(al_get_pixel(obj.bitmap, x1, y1),r,g,b,a);
									if (a != 0) {
	
										if (x + x1 == obj.x + x2 && y + y1 == obj.y + y2) {
	
											return(true);
	
										}
	
									}
	
								}
	
							}
	
						}
	
					}
	
				}
				
			}

		}
		return false;

}

#endif