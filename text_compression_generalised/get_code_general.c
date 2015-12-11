/*This code is required for getting code bits from compressed
  byte array.Code length (1 bit,2,bit...) is already known
  also how many codes are present is known.shift will keep
  how many bits are available for shifting.If it decrease
  below code length then a byte is read from compressed
  data and appended in current variable S.S 16 bit var
  holds the bits.Whenever it run out of bits . a byte is
  read and appended in S in such a way that bits left are
  not overwritten.  */
#include<stdio.h>
#include<stdlib.h>

unsigned char mask[] = {0x1,0x3,0x7,0xf,0x1f,0x3f,0x7f,0xff};

int main()
{
	char byte_arr[] = {0xe5,0x39,0x77,0x04};
	int shift = 0;
	int i;
	int code_len = 3;
	int index = 0;
	unsigned short int temp = 0;
	unsigned short int s = 0;
	char code = 0;
	char byte = 0;
	for (i = 0;i < 10;i++) {
		if (shift < code_len) {
			byte = byte_arr[index];
			index++;
			temp = byte <<(8-shift);
			printf("#shift = %u,temp =%x \n",shift,temp);
			shift = 8 + shift;
			s |= temp;
		}
		code = (s >> (16-code_len)) & mask[code_len-1];
		s = s << code_len;
		printf("shift = %d code = %x\n",shift,code);
		shift = shift - code_len;
	}

	
	return 0;
}
