#include "check_coordinates.h"

int checkCoordinates(int x, int y , int height, int width){
	if (x>height || y>width || x<0 || y<0)
		return 0;
	return 1;
}
