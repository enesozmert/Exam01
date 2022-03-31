#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 1
#endif

void *myfree(void *str);
char *get_next_line(int fd);

#endif