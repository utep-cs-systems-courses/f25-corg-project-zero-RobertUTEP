#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_5x7(char c)
{
  c -= 0x20;
  for (char col = 0; col < 5; col++) {
    for (char row = 0; row < 7; row++) {
      unsigned short rowBits = font_5x7[c][col];
      unsigned short colMask = 1 << (6-row); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}

void print_char_8x12(char c) {
  unsigned int code = (unsigned char)c;
  if (code < 0x20 || code > 0x7E) code = 0x20;   // clamp to printable
  code -= 0x20;
  for (int row = 0; row < 12; row++) {
    unsigned char bits = font_8x12[code][row]; // 8 bits = 8 columns
    for (int col = 7; col >= 0; col--) {
      putchar((bits & (1u << col)) ? '*' : ' ');
    }
    putchar('\n');
  }
  putchar('\n');
}
