/*
** server.c for server.c in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Mar 16 12:52:08 2015 michael besnainou
** Last update Mon Mar 23 00:04:05 2015 michael besnainou
*/

#include <unistd.h>
#include <signal.h>
#include "my.h"

void		get_signal(int sig)
{
  static int	i;

  if (sig == SIGUSR1)
    i = i + 1;
  else if (sig == SIGUSR2)
    {
      my_putchar(i);
      i = 0;
    }
}

int		main()
{
  pid_t		pid;

  pid = getpid();
  my_putstr("Server's PID is : ");
  my_put_nbr(pid);
  my_putchar('\n');
  signal(SIGUSR1, get_signal);
  signal(SIGUSR2, get_signal);
  while (42)
    if (pause() == 0)
  return (0);
}
