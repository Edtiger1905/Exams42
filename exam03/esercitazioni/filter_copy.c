#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    char *str = malloc(strlen(s1) + 2);

    if(!str)
        return (NULL);
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = s2[0];
    str[i + 1] = '\0';
    free(s1);
    return (str);
}

int main(int ac, char **av)
{
    int i = 0, j, len;
    char *str, buf[1];

    if(ac != 2)
        return (1);
    str = malloc(1);
    str[0] = '\0';
    len = strlen(av[1]);
    while(read(0, buf, 1));
        str = ft_strjoin(str,buf);
    
}