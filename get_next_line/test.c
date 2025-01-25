#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"

void test_stdin(void);
void test_empty_file(void);
void test_single_line(void);
void test_multiple_lines(void);
void test_invalid_fd(void);

int main(void) {
    printf("Running tests for get_next_line...\n\n");
    
    test_empty_file();
    test_single_line();
    test_multiple_lines();
    test_invalid_fd();
    
    printf("\nAll tests completed.\n");
    return 0;
}

void test_empty_file(void) {
    printf("Test: Empty file\n");
    int fd = open("empty.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    close(fd);
    
    fd = open("empty.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    if (line == NULL)
        printf("✓ Empty file test passed\n");
    else
        printf("✗ Empty file test failed\n");
    
    close(fd);
    free(line);
}

void test_single_line(void) {
    printf("\nTest: Single line file\n");
    int fd = open("single.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, "Hello World\n", 12);
    close(fd);
    
    fd = open("single.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    if (line && strcmp(line, "Hello World\n") == 0)
        printf("✓ Single line test passed\n");
    else
        printf("✗ Single line test failed\n");
    
    close(fd);
    free(line);
}

void test_multiple_lines(void) {
    printf("\nTest: Multiple lines file\n");
    int fd = open("multiple.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    write(fd, "Line 1\nLine 2\nLine 3\n", 20);
    close(fd);
    
    fd = open("multiple.txt", O_RDONLY);
    char *line;
    int count = 0;
    
    while ((line = get_next_line(fd)) != NULL) {
        count++;
        free(line);
    }
    
    if (count == 3)
        printf("✓ Multiple lines test passed\n");
    else
        printf("✗ Multiple lines test failed\n");
    
    close(fd);
}

void test_invalid_fd(void) {
    printf("\nTest: Invalid file descriptor\n");
    char *line = get_next_line(-1);
    
    if (line == NULL)
        printf("✓ Invalid fd test passed\n");
    else
        printf("✗ Invalid fd test failed\n");
    
    free(line);
}