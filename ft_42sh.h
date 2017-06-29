/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 12:48:28 by aelola            #+#    #+#             */
/*   Updated: 2014/06/17 15:56:19 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# include <curses.h>
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"

# define TG_BASTARD return(NULL);

char						**g_env;

typedef struct s_read		t_read;
typedef struct s_history	t_history;
typedef struct s_term		t_term;
typedef struct termios		t_termios;
typedef struct s_operator	t_operator;

struct						s_term
{
	char					**path;
	int						i;
	char					*link;
	char					*tmp;
	char					*retrn;
	int						fd;
	int						b;
	char					*search;
	char					*line;
	char					*name_term;
	int						i_path;
	char					*tmp_line;
	char					buff[9999];
};

struct						s_history
{
	t_history				*next;
	t_history				*prev;
	char					*cmd;
	char					*vari;
	char					*value_var;
};

struct						s_operator
{
	int						i;
	int						count;
	char					*cmd;
};

int							ft_42sh(char *line);
int							ft_sh_command(char *line, t_history *history);
int							ft_unsetenv(char *name);
void						ft_sh_setenv(char *line);
void						ft_sh_unsetenv(char *line);
char						*ft_sh_strjoin(char *s1, char *s2, char *bet);
void						ft_promt();
int							ft_pipex(char *str);
char						*ft_strnclr(char *str, int n);
void						*ft_realloc(void *ptr, size_t size);
void						ft_error(int code, char *str);
char						**ft_tablcpy(char **tabl);
int							ft_redirect(char *line, t_history *history);
char						*ft_strnew_path(char *str);
int							ft_point_virgule(char *line,
							char **tabl, t_history *history);
int							ft_exec_cmd(char *line, t_history *history);
int							ft_check_double(char *line, char c);
void						ft_sh_echo(char *line, t_history *history);
void						builtin_exit(char **name);
void						catch_signal(int signal_catch);
void						builtin_cd(char **name);
int							pars_cd(char **name, char **path);
char						*ft_getentry(char *field);
char						*get_full_path(char *newx);
void						change_env(char *path, char *change, int size);
void						cd_home();
void						pwd_previous();
void						ft_setenv(char *line);
void						put_msg(char *msg, char *msg2);
int							ft_findentry(char *field);
void						free_array(char **array);
char						**ft_realloc_free(char **s, char *elem);
int							is_builtin(char **name, char *line,
							t_history *history);
char						**ft_addentry(char *str);
void						ft_setentry(char *field, char *str);
int							ft_strchr_str(char *line, char *str);
int							ft_operator(char *line, t_history *history);
char						*ft_script(char *line);
void						exec_line(char **cmd, char ***envp_c, char *line,
							int catchx);
char						*ft_termcap();
void						ft_builtin_read(char **cmd);
t_read						*ft_creat_read_list();
t_read						*ft_add_read_list(t_read *var, char *name,
							char *value);
char						*ft_history(t_history *history, int b);
t_history					*ft_creat_history();
t_history					*ft_add_history(t_history *history, char *cmd);
t_history					*ft_read(t_history *var, char **cmd);
void						ft_press_other(t_term *st, char buff[]);
t_lst						*ft_press_tab(t_term *st, t_lst *lst);
t_history					*ft_press_up(t_term *st, t_history *history);
t_history					*ft_press_down(t_term *st, t_history *history);
char						*ft_press_enter(t_term *st, t_history *hist,
							t_termios *t);
void						ft_press_other(t_term *st, char buff[]);
void						ft_press_del(t_term *st);
int							ft_is_slash_space(int c);
void						ft_putlist(t_lst *lst);
t_lst						*ft_list(char *dir, t_lst *lst, char *search);
int							set_42sh_mode_echo(int f, t_termios *term,
							char *name_term);
int							set_42sh_mode(int f, t_termios *term, t_term *st);
char						*ft_get_link(char *line);
char						*ft_write_line(char *line, t_lst *lst, int fd);
void						ft_print_all_find(t_lst *lst, char *str, int b);
void						ft_print_line(t_term *st);
void						init_st(t_term *st);
void						ft_start_term(t_term *st, t_termios *term);
char						*ft_termcap(t_history *history);
int							ft_op(char *cmd, t_history *history);
int							ft_long(char *line, int i);
int							ft_many_op(char *line);
int							ft_doucle_pipe(char *cmd);
char						*ft_strsplit_op(char *line, int j, int i);
void						ft_init_chev(int *i, char **c, char ***t, char *l);
short						ft_ctrl_env(void);

#endif
