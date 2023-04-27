/* this file gets replaced with our own driver when we grade your submission.
 * So do what you want here but realize it won't persist when we grade it.
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "aes128e.h"

#define CLOCK(x) (x >> 8 | (x ^ (x >> 7) ^ (x >> 6) ^ (x >> 2)) << 24)
void rnd(unsigned char *b, int len) {
	static uint32_t s = 0xFEEDFACE;
	for(int i=0; i<len; i++, s=CLOCK(s)) b[i] = (unsigned char)s;
}

int main() {
	unsigned char plaintext[] = {
		0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,
		0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34 };

	unsigned char key[] = {
		0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,
		0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c };
		
	unsigned char ciphertext[] = {
		0x39,0x25,0x84,0x1d,0x02,0xdc,0x09,0xfb,
		0xdc,0x11,0x85,0x97,0x19,0x6a,0x0b,0x32,
		0x13,0xb7,0x17,0x43,0xff,0xe0,0xe8,0x8e,
		0x97,0xe4,0xc5,0x0c,0x1c,0x1b,0xfb,0x62,
		0x72,0x79,0x4b,0x19,0x93,0xaa,0x17,0xd0,
		0xc0,0x65,0x4a,0x53,0xe7,0xb8,0x34,0xb9,
		0x11,0x1d,0xc3,0x83,0xf9,0xa2,0x10,0x7e,
		0x94,0xd4,0x09,0x1d,0x89,0x2b,0x3b,0x09,
		0x15,0x24,0x2c,0x07,0xbb,0x3e,0x39,0x58,
		0x17,0xcd,0xcb,0x02,0x4c,0xdf,0xa6,0x95,
		0x57,0x9c,0xae,0x3b,0xac,0xcc,0x85,0xe9,
		0x8f,0x7c,0x6b,0x85,0x9a,0x31,0x22,0xe6,
		0x8a,0x29,0x35,0xd5,0x66,0x4f,0xf5,0x34,
		0x07,0xaa,0xc8,0x42,0xd8,0xae,0x65,0x62,
		0xad,0x16,0x8e,0x4b,0x3e,0xca,0x89,0x9e,
		0x60,0xc1,0x5c,0x28,0xa0,0x06,0x87,0x08,
		0x5e,0xe5,0x9b,0xda,0x16,0x4e,0xd1,0x66,
		0xd8,0xb2,0x35,0x34,0x0d,0x83,0x96,0xe0,
		0x52,0xa8,0x98,0x62,0x6a,0xec,0xa4,0x2d,
		0xee,0x5b,0x5a,0x4e,0x16,0x5d,0xba,0xcf };

	unsigned char c[16];

	for(int i=0; i<10; i++) {
		if (i>0) {rnd(plaintext,16); rnd(key,16);}
		
		aes128e(c, plaintext, key);		
		printf("%s%d\n", !memcmp(c, ciphertext + 16*i, 16 ) ? "PASS" : "FAIL", i);
		
	}

	return 0;
}

