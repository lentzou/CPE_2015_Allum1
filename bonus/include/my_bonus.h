/*
** my.h for  in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Thu Jul 14 16:21:53 2016 florian lentz
** Last update Tue Jul 19 22:05:02 2016 florian lentz
*/

#ifndef MY_BONUS_H_
# define MY_BONUS_H_

# define LINE 4
# define MATCHES 7

void		my_putchar(char c);
int		my_strlen(char *str);
void		my_putstr(char *str);
void		my_putnbr(int nb);
int		my_getnbr(char *str);
char		*get_next_line(const int fd);
void		print_allum(int tab, int space);
void		init_tab(int *tab);
int		player_loose(void);
int		player1_loose(void);
int		player2_loose(void);
void		player_turn(int *line, int *matches, int *tab, int i);
void		player1_turn(int *line, int *matches, int *tab, int i);
void		player2_turn(int *line, int *matches, int *tab, int i);
int		main(void);
void		check_error_line(int *line, int *tab);
void		check_error_matches(int *line, int *matches, int *tab);
void		check_error_tab(int *line, int *matches, int *tab);
void		check_line_ai(int *line, int *tab);
void		check_matches_ai(int *line, int *matches, int *tab);
int		ai_loose(void);
void		ai_turn(int *line, int *matches, int *tab, int i);
void		check_choice(int *recept);
void		check_player_turn(int *line, int *matches, int *tab);
void		check_player1_turn(int *line, int *matches, int *tab);
void		check_player2_turn(int *line, int *matches, int *tab);
int		player_vs_player(int *line, int *matches, int *tab);
int		player_vs_ai(int *line, int *matches, int *tab);

#endif /* MY_BONUS_H_ */
