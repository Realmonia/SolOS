#include "io.h"
#include "fb.h"


/* the address of the start of the frame buffer */
struct fb_char* fb = (struct fb_char*) 0x000B8000;

/** fb_move_cursor:
 * Moves the cursor of the framebuffer to the given position
 *
 * @param pos The new position of the cursor
 */

void fb_move_cursor(unsigned short pos){
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

/** fb_write:
 * Writes a string with length len and the given foreground and background
 * to position identified by row and column in the framebuffer.
 *
 * @param buf string we want to print
 * @param len length of the string
 * @param row col The location in the framebuffer
 * @param c The character
 * @param fg The foreground color
 * @param bg The background color
 */
int fb_write(char *buf, unsigned short pos, unsigned char fg, unsigned char bg){
	unsigned short i=0;
	while (buf[i]) {
		fb[pos] =(struct fb_char) {buf[i], fg, bg};
		fb_move_cursor(++pos);
		++i;
	}
	return pos;
}
