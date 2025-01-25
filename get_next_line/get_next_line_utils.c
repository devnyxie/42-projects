#include "get_next_line.h"


char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    return (NULL);
}


size_t ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    if (!s)
        return (0);
    while (s[len])
        len++;
    return (len);
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d;
    const unsigned char *s;

    if (!dest && !src)
        return (NULL);

    d = (unsigned char *)dest;
    s = (const unsigned char *)src;

    if (d < s)
    {
        while (n--)
            *d++ = *s++;
    }
    else if (d > s)
    {
        d += n - 1;
        s += n - 1;
        while (n--)
            *d-- = *s--;
    }

    return (dest);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;
    size_t             i;

    if (!dest && !src)
        return (NULL);
    d = (unsigned char *)dest;
    s = (const unsigned char *)src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dest);
}