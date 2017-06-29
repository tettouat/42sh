/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelola <aelola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 06:11:14 by aelola            #+#    #+#             */
/*   Updated: 2014/01/17 06:11:15 by aelola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

void	ft_error(int code, char *str);
size_t	ft_strlen(const char *s);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *s1, const char *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	**ft_tablcpy(char **tabl);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strnclr(char *str, int n);
void	ft_puterror(char const *s);
void	*ft_realloc(void *ptr, size_t size);
char	**ft_strsplit(char const *s, char c);
void	ft_bzero(void *s, size_t n);

#endif
