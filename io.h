#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/** outb:
  * send the given data to the given IO port. Defined in io.s
  *
  * @param port The IO port we send data to
  * @param data The data sent to IO port
 */

void outb(unsigned short port, unsigned char data);

#endif