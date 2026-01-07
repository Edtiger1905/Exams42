/* sub:
Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a 
.

If the number of arguments is not 2, the program displays 
.
*/

#include <unistd.h>

void inter(char *s1, char *s2)
{
/* i usato per scorrere s1,j usato per scorrere s2,l usato per
controllare se il carattere e' già apparso prima. */
        int i;
        int j;
		int l;

        i = 0;
        l = 0;
/* confronta i caratteri di s1 con quelli di s2 */
        while(s1[i] != '\0') 
	{
		j = 0;
		while(s2[j] != '\0')
		{
/* controlla due cose: */
        	if(s1[i] == s2[j])
        	{       
				l = 0;
/* controlla se il carattere non e' già apparso prima in s1 */
				while(s1[l] != s1[i])
					l++;
				if(l == i)
				{
					l = 0;
/* controlla se il carattere non e' già apparso prima in s2 */
					while(s2[l] != s2[j])
						l++;
					if(l == j)
/* se passa entrambi i controlli stampa il carattere */
						write(1, &s1[i], 1);
       			}
			}
			j++;
        	}
		i++;
	}
}

int main(int ac,char **av)
{       
        char *s1;
        char *s2;

        s1 = av[1];
        s2 = av[2];

        if(ac == 3)
                inter(s1, s2);
        write(1, "\n", 1);
	return(0);
}
