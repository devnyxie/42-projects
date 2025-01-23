#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>

int main(void) {
    int fd;
    char *line;
    int line_count = 0;

    // Open the file
    fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read lines until get_next_line returns 0 or -1
    while ((line = get_next_line(fd)) != NULL) {
        printf("\n=== Line %d: %s ===\n\n", ++line_count, line);
        free(line);
    }
    
    // Close the file
    close(fd);

    printf("\nTotal lines read: %d\n", line_count);

    return 0;
}