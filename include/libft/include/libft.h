/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperez-b <gperez-b@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:27:24 by gperez-b          #+#    #+#             */
/*   Updated: 2024/02/28 20:28:46 by gperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *nptr);

double		ft_atoidb(const char *str);

long int	ft_long_atoi(const char *nptr);

void		ft_bzero(void *s, size_t n);

void		*ft_calloc(size_t nmemb, size_t size);

int			ft_isalnum(int argument);

int			ft_isalpha(int argument);

int			ft_isascii(int argument);

int			ft_isdigit(int argument);

int			ft_isdigit_plusminus(int argument);

int			ft_isdigit_plusminusdot(int argument);

int			ft_isprint(int argument);

char		*ft_itoa(int argument);

void		ft_lstadd_back(t_list **lst, t_list *new);

void		ft_lstadd_front(t_list **lst, t_list *new);

void		ft_lstdelone(t_list *lst, void (*del)(void*));

void		ft_lstclear(t_list **lst, void (*del)(void*));

void		ft_lstiter(t_list *lst, void (*f)(void*));

t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));

t_list		*ft_lstnew(void *content);

int			ft_lstsize(t_list *lst);

void		*ft_memchr(const void *s, int c, size_t n);

void		*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_memcmp(const void *s1, const void *s2, size_t n);

void		*ft_memmove(void *dest, const void *src, size_t n);

void		*ft_memset(void *s, int c, size_t n);

void		ft_putchar_fd(char c, int fd);

void		ft_putendl_fd(char *s, int fd);

void		ft_putnbr_fd(int n, int fd);

void		ft_putstr_fd(char *s, int fd);

void		ft_sort_int(int *arr, int len);

char		**ft_split(const char *s, char c);

char		*ft_strchr(const char *s, int c);

char		*ft_strdup(const char *s);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));

char		*ft_strjoin(const char *s1, const char *s2);

size_t		ft_strlen(const char *s);

size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);

size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int			ft_strncmp(const char *s1, const char *s2, size_t n);

char		*ft_strnstr(const char *big, const char *little, size_t len);

char		*ft_strtrim(const char *s1, const char *s2);

char		*ft_strrchr(const char *s, int c);

char		*ft_substr(const char *s, unsigned int start, size_t len);

int			ft_tolower(int argument);

int			ft_toupper(int argument);

int			ft_printf(const char *format, ...);

int			ft_convert_printf(va_list args, const char mod);

int			ft_putchar_ct(char c);

int			ft_putnbr_ct(int n);

int			ft_putuns_ct(unsigned int n);

int			ft_putptr_ct(void *adr);

int			ft_putstr_ct(char *s);

int			ft_puthex_ct(int nbr, char *base);

char		*get_next_line(int fd);

char		*copyfile(int fd, char *buff);

char		*copyline(char *buff);

char		*newbuff(char *buff);

char		*ft_strjoin_gnl(char *s1, char *s2);

#endif
