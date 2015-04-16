/*
** my_getnbr.c for getnbr in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Mar 16 12:42:26 2015 michael besnainou
** Last update Mon Mar 16 12:43:12 2015 michael besnainou
*/

int	my_getnbr(char *str)
{
  int	nbr;
  int	i;

  i = -1;
  nbr = 0;
  while (str[++i] != '\0')
    nbr = nbr * 10 + str[i] - 48;
  return (nbr);
}
