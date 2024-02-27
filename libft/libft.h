/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaporte <mlaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:22:20 by mlaporte          #+#    #+#             */
/*   Updated: 2024/01/30 12:45:00 by mlaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INT_MAX 2147483647
# ifndef BUFFER_SIZE	
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	int				content;
	int				cost;
	int				above_median;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_lstsize(t_list *lst);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);
char		*ft_strtrim(char *s1, char *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_lstadd_front(t_list **lst, t_list *new);
t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(int));
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(int));
void		ft_lstiter(t_list *lst, void (*f)(int));
int			ft_printf(const char *str, ...);
int			ft_printc(va_list ap);
int			ft_printstr(va_list ap);
int			ft_printptr(va_list ap);
int			ft_printhexamin(va_list ap);
int			ft_printhexamaj(va_list ap);
int			ft_printint(va_list ap);
int			ft_printuns(va_list ap);
int			ft_printpercent(va_list ap);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(unsigned int nbr);
int			ft_putnbr_base(long long unsigned int nbr, char *base);
size_t		check_format(const char *str);
size_t		printf_format(const char *str, va_list ap);
char		*get_line(char *res);
char		*get_res(char *str);
char		*get_txt(int fd, char *res);
char		*get_next_line(int fd);
void		*free_tab(char **tab);

#endif
