#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_INPUT_BUFFER_SIZE 10001

int ft_strncmp(char *s1, char *s2, int n)
{
    int i;

    i = 0;
    while(i < n && s1[i] == s2[i])
        i++;
    return (i == n);
}
