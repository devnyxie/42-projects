#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ft_strdup.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t s_size = 0;
    // s length
    while (s[s_size])
        s_size++;

    // return an empty string if start is more or equal to s_size.
    if (start >= s_size)
        return ft_strdup("");

    // if start+len >= s_size, then it won't be able to
    // copy any characters. Therefore we will adjust the len to available size.
    if (start + len > s_size)
        len = s_size - start;

    char *str = (char *)malloc((len + 1) * sizeof(char));
    if (!str) return NULL;

    unsigned int str_i = 0;
    unsigned int s_i = start;

    while(s[s_i]) {
        str[str_i] = s[s_i];
        str_i++;
        s_i++;
    }
    str[str_i] = '\0';

    return str;
}




int main(void)
{
    char *s = "Hello, world!";
    char *substr = ft_substr(s, 7, 5);

    if (substr)
    {
        printf("Substring: %s\n", substr);
        free(substr);
    }
    else
    {
        printf("Allocation failed.\n");
    }

    char *s1 = "Hello";
    char *substr1 = ft_substr(s1, 7, 5);

    if (substr1)
    {
        printf("Substring: %s\n", substr1);
        free(substr1);
    }
    else
    {
        printf("Allocation failed.\n");
    }

    char *s2 = "Hello";
    char *substr2 = ft_substr(s2, 3, 3);

    if (substr2)
    {
        printf("Substring: %s\n", substr2);
        free(substr2);
    }
    else
    {
        printf("Allocation failed.\n");
    }

    return 0;
}