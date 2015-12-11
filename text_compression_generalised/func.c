#include"func.h"

int open_file(char *fname)
{
	int fd;	
	if(fname == NULL) {
		perror("bad file name");
		exit(-1);
	}
	fd = open(fname,O_RDONLY);
	if(fd < 0) {
		perror("error in opning file");
		exit(-1);
	}
	printf("file opened fd=%d\n",fd);
	return fd;
}

char *master_create(int fd,int *unique_count)
{
	char *master_arr = NULL;
	unsigned char ch = 0;
	int n;

	if ( unique_count == NULL) {
		fprintf(stderr , "2nd arg cant be null\n");
		return master_arr;
	}

	master_arr = (char *) malloc(UNIQUE_LEN*sizeof(char));
	if (master_arr == NULL) {
		fprintf(stderr,"error in allocating memory\n");
		exit(EXIT_FAILURE);
	}
	memset(master_arr,0,UNIQUE_LEN*sizeof(char));
	*unique_count = 0;
	while (n = read(fd,&ch,sizeof(ch))) {
		if (master_arr[ch] == 0) {
			(*unique_count)++;
		}
		master_arr[ch]++;
	}
	return master_arr;
}

int code_length(int num_unique)
{
	int num = 0;
	int code_bits = 0;
	if ( num_unique <= 0 || num_unique > 256) {
		fprintf(stderr,"unique characters should be in range [1-256]\n");
		return -1;
	}
	while (code_bits <= 8) {
                num = 1 << code_bits;
		if (num_unique <= num) {
			break;
		}
		code_bits++;
	}
	return code_bits;
}


char *create_code(char *master_arr,int num_unique)
{
	int i = 0;
	int code = 0;
	char *code_arr = NULL;
	if (master_arr == NULL) {
		fprintf(stderr,"master_array cant be null\n");
		return code_arr;
	}


	code_arr = (char *)malloc(UNIQUE_LEN*sizeof(char));
	if (code_arr == NULL) {
		fprintf(stderr,"error in allocating memory\n");
		exit(EXIT_FAILURE);
	}
	memset(code_arr,0,UNIQUE_LEN*sizeof(char));
	for (i = 0;i < UNIQUE_LEN; i++) {
		if (*(master_arr+i) > 0) {
			*(code_arr+i) = code;
			code++;
		}
	}
	return code_arr;
}

char *create_decode(char *master_arr,int num_unique)
{
	char *decode_arr;
	int code = 0;
	int i = 0;
	decode_arr = (char *)malloc(num_unique*sizeof(char));
	if (decode_arr == NULL) {
		perror("error in creating decode_arr\n");
		exit(EXIT_FAILURE);
	}

	memset(decode_arr,0,num_unique*sizeof(char));
	for (i = 0;i < UNIQUE_LEN; i++) {
		if (*(master_arr+i) > 0) {
			*(decode_arr+code) = i;
			code++;
		}
	}
	return decode_arr;
}

int compressed(int fd,char *master_arr,char *code_arr,int code_len)
{
	int fd2,n=0;
	unsigned char c1 = 0;
	unsigned char ch = 0;
	int shift = 0;
	unsigned char code; 
	lseek(fd,0,SEEK_SET);
	fd2 = open("compressed",O_CREAT|O_RDWR,0666);
	if (fd2 == -1) {
		perror("error in opening file");
		exit(EXIT_FAILURE);
	}
	printf("compression started\n");
	shift = 8 - code_len;	
	/*while (n = read(fd,&ch,sizeof(unsigned char))) {
		code = *(code_arr+ch);
		c1 = c1 | (code << shift);
		printf("shift = %d c1= %X code=%d\n",shift,c1 & 0xFF,*(code_arr+ch));
		if(shift < code_len) {
			printf(" c1= %X ,code =%d,shift = %d\n ",c1 ,code,shift);
			c1 = c1 | (code >> (code_len - shift));
			printf("code written= %X\n ",c1 & 0xFF);
			write(fd2,&c1,sizeof(char));
			c1 = code << (8-(code_len - shift));
			shift = 8 - (code_len - shift );
			printf("#shift = %d c = %X \n",shift,c1&0xFF);
		} else if (shift == 0) {
			printf("shift 0, code written=%X\n",c1);
			write(fd2,&c1,sizeof(char));
			c1 = 0;
			shift = 8 - code_len;
		} else
			shift = shift - code_len;

	}*/
	unsigned short s1
	shift = 0;
	while (n = read(fd,&ch,sizeof(unsigned char))) {
		code = *(code_arr+ch);
		s1 |= code << (16 - (code_len+shift));
		if ((shift+code_len) > 8) {
			c1 = s1 & 0xFF;
			write(fd2,&c1,sizeof(char));
			8+(shift+code_len)-8
			
		}
		shift = shift + code_len;
	}	
	return fd2;
}

/*function decompress data in file descriptor fd based on master array str
 *return a file descriptor containing decompressed text.
 */
int decompress(int fd,char *master_arr,char *code_arr,char *decode_arr,int code_len,int num_unique)
{
	static unsigned char mask[] = {0x1,0x3,0x7,0xf,0x1f,0x3f,0x7f,0xff};
	int fd2 = 0;
	int n;
	char code;
	char c;
	char c2;
	int shift = 0;
        int i,ret;
        /*int code_len = 3;*/
        int index = 0;
        unsigned short int temp = 0;
        unsigned short int s = 0;
        char byte = 0;
	char read_flag = 1;
	int decode_arr_len = mask[(code_len - 1)]+1;
	printf("decode_arr_len = %d \n",decode_arr_len);
	
	for(i = 0;i < num_unique; i++)
	{
		printf("d[i]=%d\n",decode_arr[i]);	
	}
	
	fd2 = open("decompressed",O_CREAT|O_RDWR,0666);
	if(fd2 < 0)
	{
		perror("error in opening file \n");
		exit(EXIT_FAILURE);
	}
	/*while(n = read(fd,&c,sizeof(c)))
	{
		printf("n=%d ",n);
		c2 = (c >> 4) & 0x0F;
		code = master_str[c2];
		write(fd2,&code,sizeof(char));
		printf("%c",code);

		c2 = c & 0x0F;
		code = master_str[c2];
		write(fd2,&code,sizeof(char));
		printf("%c",code);
	}*/

        for (;read_flag;) {
                if (shift < code_len) {
			ret = read(fd,&byte,sizeof(char));
			if (ret == -1) {
				perror("error in reading");
				exit(EXIT_FAILURE);
			} else if( ret == 0 ) {
				read_flag = 0;
			}
                        /*byte = byte_arr[index];*/
                        index++;
                        temp = byte <<(8-shift);
                        printf("shift = %u,temp =%x \n",shift,temp);
                        shift = 8 + shift;
                        s |= temp;
                }
                code = (s >> (16-code_len)) & mask[code_len-1];
                s = s << code_len;
		c = decode_arr[code];	
		write(fd2,&c,sizeof(char));
                printf("shift = %d code = %x c=%d\n",shift,code,c);
                shift = shift - code_len;
        }

	return fd2;
}

char find_code(char ch,char *master_str)
{
	char code;
	int i = 0;
	printf("\n ch = %c \n",ch);
	while(*(master_str+i)!=0)
	{
		if(*(master_str+i)==ch)
		{
			code = i;
			break;
		}
		i++;
	}
	
	return code; 
}

