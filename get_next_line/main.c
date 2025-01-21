#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    char* fileName = "file.txt";

    int fd = open(fileName, O_RDONLY);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("line: %s\n", line);
        free(line);
    }
    // printf("\nLine: --> %s <--\n", line);
	free(line);
	close(fd);
    return(0);
}
