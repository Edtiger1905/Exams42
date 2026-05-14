#define _GNU_SOURCE

#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

size_t ft_strlen(char *s)
{
    size_t i = 0;

    if(!s)
        return i;
    while (s[i] != '\0')
        i++;
    return (i);
}
char *ft_strjoin(char *s1, char *s2)
{
    size_t size1 = ft_strlen(s1);
    size_t size2 = ft_strlen(s2);

    char *tmp = malloc(size1 + size2 + 1);

    if(!tmp)
        return (NULL);

    memmove(tmp, s1, size1);
    memmove(&tmp[size1], s2, size2);

    tmp[size1 + size2] = '\0';

    return (tmp);

}
int ft_strncmp(char *s1,char *s2, size_t n)
{
    int i = 0;

    while(s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

void filter(char *s1, char *s2)
{
    int i = 0;
    size_t size2 = ft_strlen(s2);

    while(s1[i] != '\0')
    {
        if(ft_strncmp(&s1[i], s2, size2) == 0)
        {
            int j = 0;

            while(j < size2)
            {
                write(1, "*", 1);
                i++;
                j++;
            }
        }
        else
        {
            write(1, &s1[i], 1);
            i++;
        }
    }
}

int main(int ac, char **av)
{
    ssize_t bytes = 0;

    char *r = NULL;
    char *tmp = NULL;
    char *s = av[1];
    char buf[BUFFER_SIZE + 1] = "";

    if(ac != 2 || !s)
        return (1);

    while((bytes = read(0, buf, BUFFER_SIZE)) > 0)
    {
        buf[BUFFER_SIZE] = '\0';
        tmp = ft_strjoin(r, buf);
        free(r);
        r = tmp;
    }
    
    if(bytes < 0)
        return (free(r), 1);
    
        if(!r)
        return (0);
    
        filter(r, s);

    return (free(r), 0);
}