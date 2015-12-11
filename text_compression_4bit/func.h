#ifndef _FUNC_H
#define _FUNC_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int open_file(char *);
char* master_create(int);
int code_length(char *);
int compressed(int ,char *,int);
char find_code(char ,char *);
int decompress(int fd,char *master_str);
#endif
