
#include <unistd.h>

int ft_strcmp(char *s1,char *s2)
{
	/*sub: riproduce il funzionamento della funzione strcmp della libreria base di C*/

	// 1. dichiarazione di variabile e inizializzazione
	int i;

	i = 0;
	// 2. cuore della funzione: compara le stringhe s1 ed s2 e restituisce la differenza tra due due
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
