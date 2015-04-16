/*
** client.c for client.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Mar 16 12:24:23 2015 michael besnainou
** Last update Mon Mar 23 00:00:56 2015 michael besnainou
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

int		client(pid_t pid, char *str)
{
  int		i;
  int		a;

  i = 0;
  a = 0;
  while (str[i] != '\0')
    {
      a = 0;
      while (a < str[i])
	{
	  if (kill(pid, SIGUSR1) == -1)
	    return (0);
	  if (usleep(333) == -1)
	    return (0);
	  a = a + 1;
	}
      if (kill(pid, SIGUSR2) == -1)
	return (0);
      i = i + 1;
    }
  my_putstr("Signal sent and well received by the server.\n");
  return (0);
}

void		aff_infos_signal(pid_t pid, char *str)
{
  my_put_nbr(pid);
  my_putstr(" - ");
  my_putstr(str);
  my_putchar('\n');
  client(pid, str);
}

int		ping()
{
  pid_t		pid;
  int		i;

  i = 0;
  pid = getpid();
  while (i != pid)
    {
      if (kill(pid, SIGUSR1) == -1)
	return (0);
      i = i + 1;
    }
  if (kill(pid, SIGUSR2) == -1)
    return (0);
  return (0);
}

int		main(int argc, char **argv)
{
  pid_t		pid;
  char		*str;

  pid = 0;
  if (argc != 3)
    {
      my_putstr("Respect the following model:'./client [SERVERPID] [TEXT]'\n");
      return (2);
    }
  pid = my_getnbr(argv[1]);
  str = argv[2];
  aff_infos_signal(pid, str);
  return (0);
}
