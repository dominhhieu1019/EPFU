#include "check_valid_move.h"

int checkValidMove(int x1, int y1, int x2, int y2){
	if ((fabs(x2-x1) == fabs(y2-y1)) ||
	     (fabs(y2-y1) == 2 && x2 == x1))
		return 1;
	return 0;
}
