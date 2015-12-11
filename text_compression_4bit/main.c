#include"func.h"

int main(int argc,char* argv[])
{
	int fd,fd2;
	char *str = NULL;
	int code_len = 0;
	if(argc < 2)
	{
		perror("incorrect number of arguments:./mdc [filename]");
		exit(EXIT_FAILURE);
	}
	
	fd = open_file(argv[1]);
	
	str = master_create(fd);
	printf("str =%s\n",str);
	
	code_len = code_length(str);
	printf("code_len=%d\n",code_len);

	fd2 = compressed(fd,str,code_len);
	close(fd);
	close(fd2);
	
	fd = open("compressed",O_RDONLY);
	if(fd < 0)
	{
		perror("error in opening compressed file\n");
		exit(EXIT_FAILURE);
	}
	
	fd2 = decompress(fd,str);
	close(fd);
	close(fd2);
}
