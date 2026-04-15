#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

char *ft_strdup(const char *str)
{
    int i;
    char *s1;

    i = 0;
    if(str == NULL)
        return (NULL);
    s1 = malloc(sizeof(char) * (strlen(str) + 1));
    if(s1 == NULL)
        return (NULL);
    while(str[i])
    {
        s1[i] = str[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}
char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    char        line[70000];
    static int  b_read;
    static int  b_pos;
    int         i;

    i = 0;
    if(fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    while(1)
    {
        if(b_pos >= b_read)
        {
            b_read = read(fd, buffer, BUFFER_SIZE);
            b_pos = 0;
            if(b_read <= 0)
                break ;
        }
        line[i++] = buffer[b_pos++];
        if(buffer[b_pos - 1] == '\n')
            break ;
    }
    line[i] = '\0';
    if(i == 0)
        return (NULL);
    return (ft_strdup(line));
}
int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    line = NULL;

    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}