/*
** my.h for  in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Thu Jul 14 16:21:53 2016 florian lentz
** Last update Thu Jul 21 17:59:42 2016 florian lentz
*/

#ifndef MY_H_
# define MY_H_

# define LINE 4
# define MATCHES 7

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);
void		my_putnbr(int nb);
int		my_getnbr(char *str);
char		*get_next_line(const int fd);
int		main(void);
void		init_tab(int *tab);
void		print_allum(int tab, int space);
int		check_player_turn(int *line, int *matches, int *tab);
int		check_error_line(int *line, int *tab);
int		check_error_m2(int *line, int *matches, int *tab, char *str);
int		check_error_matches(int *line, int *matches, int *tab);
int		check_error_tab(int *line, int *matches, int *tab);
int		player_turn(int *line, int *matches, int *tab, int i);
int		player_loose(void);
void		check_line_ai(int *line, int *tab);
void		check_matches_ai(int *line, int *matches, int *tab);
void		ai_turn(int *line, int *matches, int *tab, int i);
int		ai_loose(void);

#endif /* !MY_H_ */
