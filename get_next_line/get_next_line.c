// our buffer is gonna be an array of pointers to different positions in files. A kind of Hashmap.

// 1. read chunk from a file
// 2. update the ptr ?
// 3. check for new line ?

// *clear the buffer[FD] when done/error

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define FD_LIMIT 1024
#define CHUNK_SIZE 8

// Static array to store pointers to data for each FD
static char *buffer[FD_LIMIT + 1];

// returns ptr just before line break if \n found, prev ptr if no \n was found
// char *eol_ptr(char *buffer){
// 	int i = 0;
// 	while(buffer[i]){
// 		int j = i+1;
// 		if(j <= CHUNK_SIZE && buffer[j] == '\n'){
// 			return(buffer[i]);
// 		}
// 		i++;
// 	}
// 	return(buffer);
// }

void append_line(char **dest, const char *src) {
	if (!src) return;

	size_t dest_len = *dest ? strlen(*dest) : 0;
	size_t src_len = strlen(src);
	char *new_line = malloc(dest_len + src_len + 1);

	if (*dest) {
		strcpy(new_line, *dest);
		free(*dest);
	} else {
		new_line[0] = '\0'; // init if dest was NULL
	}

	strcat(new_line, src);
	*dest = new_line;
}

int ft_strlen(char *str) {
	int i = 0;
	while (str[i]) {
		i++;
	}
	return i;
}

void ft_strcpy(char *dest, char *src) {
	int i = 0;
	while (src[i]) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

// int eof_check(char *buffer) {
// 	int i = 0;
// 	while (buffer[i]) {
// 		int j = i + 1;
// 		if (j <= CHUNK_SIZE && buffer[j] == '\n') {
// 			while (j <= CHUNK_SIZE) {
// 				buffer[j] = '\0';
// 				j++;
// 			}
// 			return 1;
// 		}
// 		i++;
// 	}
// 	return 0;
// }



// issue:
// no starting point for the next call for the same buffer
// we need to split the buffer into two parts:
// - one part that we return (before the new line)
// - one part that we keep in buffer (after the new line)

//issue:
// no new line encountered -> bug

char *get_next_line(int fd) {	
	if (fd < 0 || fd >= FD_LIMIT) {
		fprintf(stderr, "FD out of range\n");
		return NULL;
	}
	while (1) {
		// init if not initialized
		if (!buffer[fd]) {
			buffer[fd] = (char *)malloc((CHUNK_SIZE + 1) * sizeof(char));
		} else {
			// Reallocate the buffer to fit the new chunk
			int sizeof_buffer = ft_strlen(buffer[fd]);
			char *temp_buffer = (char *)malloc((sizeof_buffer + CHUNK_SIZE + 1) * sizeof(char));
			ft_strcpy(temp_buffer, buffer[fd]);
			free(buffer[fd]);
			buffer[fd] = temp_buffer;
		}
		int offset = ft_strlen(buffer[fd]);
		int bytes_read = read(fd, buffer[fd] + offset, CHUNK_SIZE);
		// err
		if (bytes_read < 0) {
			return NULL; 
		}
		buffer[fd][bytes_read] = '\0';
		
		// check for new line
		if (eof_check(buffer[fd])) {
			return buffer[fd];
		}

		if (bytes_read == 0) {
			if (buffer[fd][0] == '\0') {
				free(buffer[fd]);
				return NULL;
			}
		}
		
		return buffer[fd];
	}
}
