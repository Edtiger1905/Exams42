/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a 
.

If the number of arguments is not 2, the program displays 
.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
 */

 void inter(char *s1, char *s2)
{
        int i;
        int j;

        i = 0;
        j = 0;

        while(s1[i] != '\0' || s2[j] != '\0')
        {
                if(s2[j] == s1[i])
                {       
                        write(1, &s1[i], 1);
                        i++;    
                        j = 0;
                }
                else if(s1[i] == '\0')
                {
                        i++;
                }
                else 
                        j++;    
        }
}

int main(int ac,char **av)
{       
        char *s1;
        char *s2;

        s1 = av[1];
        s2 = av[2];

        if(ac != 3)
                write(1, "\n", 1);
        else
        {               
                inter(s1, s2);
        }
        return(0);
}
/* da mettere apposto */