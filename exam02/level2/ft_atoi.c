
#include <unistd.h>

int	ft_atoi(const char *str)
{
	/* 1. dichiarare le variabili: nbr per il numero, sig per il segno del numero, i come indice per str*/
	int nbr;
	int sig;
	int i;
	
	/* 2. inizializzazione delle variabili,tutte a 0 tranne sig perche' dopo tocca moltiplicarle per il numero
	 * convertito e quindi e' giusto stia a 1 */
	nbr = 0;
	sig = 1;
	i = 0;
	/* 3. check dei segni,se il segno e' +,va avanti senza fare niente,se e' negativo assegna a sig il valore
	 * di -1,per poterlo poi moltiplicarlo nel return con il numero convertito */
	if(str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sig = -1;
		i += 1;
	}
	/* 4. cuore della funzione,converte da ascii a numero grazie a dei calcoli,costruisce il numero con il
	 * loop,convertendo il numero.
	 * es col numero 123:
	 * nbr = (0 * 10) + 1 = 1
	 * nbr = (1 * 10) + 2 = 12
	 * nbr = (12 * 10) + 3 = 123 */
	while(str[i] && str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sig);
}
