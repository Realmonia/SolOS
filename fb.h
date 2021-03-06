#ifndef INCLUDE_FB_H
#define INCLUDE_FB_H

/* define behaviors related to frame buffer operation */

/* screen size */
#define MAX_W 80
#define MAX_H 25

/* colors */
#define FB_BLACK 0
#define FB_BLUE 1
#define FB_GREEN 2
#define FB_CYAN 3
#define FB_RED 4
#define FB_MAGENTA 5
#define FB_BROWN 6
#define FB_LIGHT_GREY 7
#define FB_DARK_GREY 8
#define FB_LIGHT_BLUE 9
#define FB_LIGHT_GREEN 10
#define FB_LIGHT_CYAN 11
#define FB_LIGHT_RED 12
#define FB_LIGHT_MAGENTA 13
#define FB_LIGHT_BROWN 14
#define FB_WHITE 15

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND 15

/* packed struct to avoid unexpected change */
struct fb_char {
	unsigned char c; 		// bit 8-15
	unsigned char fg : 4;	// bit 4-7
	unsigned char bg : 4;	// bit 0-3
} __attribute__((packed));

int fb_write(char *buf, unsigned short pos, unsigned char fg, unsigned char bg);

void fb_move_cursor(unsigned short pos);

#endif