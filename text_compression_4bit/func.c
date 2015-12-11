#include"func.h"

int open_file(char *fname)
{
	int fd;	
	if(fname==NULL)
	{
		perror("bad file name");
		exit(-1);
	}
	fd = open(fname,O_RDONLY);
	if(fd<0)
	{
		perror("error in opning file");
		exit(-1);
	}
	printf("file opened fd=%d\n",fd);
	return fd;
}

char* master_create(int fd)
{
	char *master_str;
	char ch = 0;
	int i,flag=0,len;
	i = 0;
	master_str = malloc(1);
	read(fd,&ch,1);
	master_str[i] = ch;
	master_str[1]='\0';
	while(read(fd,&ch,1)&&ch!=10)
	{
		flag = 1;
		for(i=0;i<strlen(master_str);i++)
		{
			if(ch == master_str[i])
			{
				flag = 0; 
				break;
			}
		}
		if(flag == 1)
		{
			master_str = realloc(master_str,strlen(master_str)+1);
			master_str[strlen(master_str)]=ch;
			master_str[strlen(master_str)+1]='\0';
		}
	
	}
	return master_str;
}

int code_length(char *str)
{
	int len = 0;
	int num;
	int shift= 0;
	if(str==NULL)
	{
		perror("invalid code string");
		exit(-1);
	
	}
	len = strlen(str);
	num = 1;
	shift = 1;
	while(shift<32)
	{
		if(num > len)
		{
			break;
		}
                num = num << shift;
		shift++;
	}
	return shift;
}

int compressed(int fd,char *master_str,int code_len)
{
	int fd2,n=0;
	char ch[2],ch1,ch2;
	lseek(fd,0,SEEK_SET);
	fd2 = open("compressed",O_CREAT|O_WRONLY|O_TRUNC);
	if(fd2 < 0)
	{
		perror("eorror in opening file \n");
		exit(-1);
	}
	printf("before while\n");
	while(n = read(fd,ch,2))
	{
		if(n==2)
		{
			ch1 = find_code(ch[0],master_str);
			ch2 = find_code(ch[1],master_str);
			//printf("%4X %4X \n",ch1,ch2);
			ch1 = ((0x0F&ch1)<<4)+(0x0F & ch2);
			printf("ch=%X \n",ch1);
		}
		if(n==1)
		{
			ch1 = find_code(ch[0],master_str);
			printf("%4X \n",ch1);
		}
		/*write in compressed file*/
		write(fd2,&ch1,1);
	}
	return fd2;
}

/*function decompress data in file descriptor fd based on master array str
 *return a file descriptor containing decompressed text.
 */
int decompress(int fd,char *master_str)
{
	int fd2 = 0;
	int n;
	char code;
	char c;
	char c2;
	fd2 = open("decompressed",O_CREAT|O_RDWR,0666);
	if(fd2 < 0)
	{
		perror("eorror in opening file \n");
		exit(EXIT_FAILURE);
	}
	while(n = read(fd,&c,sizeof(c)))
	{
		c2 = (c >> 4) & 0x0F;
		code = master_str[c2];
		write(fd2,&code,sizeof(char));
		printf("%c",code);

		c2 = c & 0x0F;
		code = master_str[c2];
		write(fd2,&code,sizeof(char));
		printf("%c",code);
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

