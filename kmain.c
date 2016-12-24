#include "fb.h"
#include "io.h"

int main() {
	unsigned short cursor;
	/* Display some letter */
	fb_move_cursor(0);

	// orz chuibility
	cursor=fb_write("orz chuibility", 0, FB_WHITE, FB_BLACK);

	/* Display the cursor in new line */
	fb_move_cursor((cursor/80+1)*80);
 
	return 0; 
}