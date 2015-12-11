#include"func.h"

int main(int argc,char* argv[])
{
	int fd,fd2;
	
	char *master_arr = NULL;
	char *code_arr = NULL;
	char *decode_arr = NULL;
	int num_unique = 0;
	int i = 0,code_len = 0;
	if(argc < 2) {
		perror("incorrect number of arguments:./mdc [filename]");
		exit(EXIT_FAILURE);
	}
	
	fd = open_file(argv[1]);
	/*find the unique bytes in the file fd*/
	master_arr = master_create(fd,&num_unique);
	printf("num_unique=%d\n",num_unique);
	
	/*calculate number of bits required to represent each unique byte*/
	code_len = code_length(num_unique);
	printf("code_len=%d\n",code_len);
	
	/*create code for each byte.Due to look up this function is extra.If the array consist 
	  of only unique bytes then this would not be required.In that case the index of each
	  unique byte give its code*/
	code_arr = create_code(master_arr,num_unique);	  
	  
	for (i = 0;i < UNIQUE_LEN;i++) {
		if (master_arr[i] > 0)
			printf("master i = %d,c = %d \n",i,master_arr[i]);
	}  			

	fd2 = compressed(fd,master_arr,code_arr,code_len);
	close(fd);
	close(fd2);
	
	fd = open("compressed",O_CREAT|O_RDONLY);
	if(fd == -1)
	{
		perror("error in opening compressed file\n");
		exit(EXIT_FAILURE);
	}
	
	decode_arr = create_decode(master_arr,num_unique);
	fd2 = decompress(fd,master_arr,code_arr,decode_arr,code_len,num_unique);

	close(fd);
	close(fd2);
	free(master_arr);
	free(code_arr);
	return EXIT_SUCCESS; 
}
