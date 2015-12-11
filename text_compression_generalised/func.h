#ifndef _FUNC_H
#define _FUNC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

#define UNIQUE_LEN 256

int open_file(char *);
char *master_create(int fd,int *unique_count);
int code_length(int num_unique);
char *create_code(char *master_arr,int num_unique);
char *create_decode(char *master_arr,int num_unique);
int compressed(int ,char *,char *,int);
char find_code(char ,char *);
int decompress(int fd,char *master_arr,char *code_arr,char *decode_arr,int code_len,int num_unique);

#endif
