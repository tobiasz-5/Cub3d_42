/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:27:20 by mapichec          #+#    #+#             */
/*   Updated: 2025/01/18 17:44:52 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <errno.h>
# include <ctype.h>
# define FALSE 0
# define TRUE 1

typedef enum state
{
	STATE_NORMAL,
	STATE_DOLLAR,
	STATE_SINGLE_QUOTES,
	STATE_DOUBLE_QUOTES,
	STATE_DOLLAR_DOUBLE_QUOTES
}	t_token_state;

typedef enum type
{
	TOKEN_WORD,
	TOKEN_OPTION,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF,
	TOKEN_DOLLAR,
	TOKEN_DOUBLE_QUOTES,
	TOKEN_SINGLE_QUOTES,
	TOKEN_WHITESPACE,
	TOKEN_COMMAND,
	TOKEN_APPENDICE,
	TOKEN_WORD_QT
}	t_token_type;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	t_token_state	state;
	struct s_token	*next;
}	t_token;

int			ft_isalnum(char c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_strlen(const char *str);
size_t		ft_strlen_2(const char *s, int flag);
///////////////////////////////////////////////
void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
///////////////////////////////////////////////
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
///////////////////////////////////////////////
int			ft_toupper(int c);
int			ft_tolower(int c);
//////////////////////////////////////////////
char		*ft_strchr(const char *s, int c);
int			ft_strchr_2(char *s, int c);
char		*ft_strrchr(char *s, int c);
int			ft_strncmp(char *s1, char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strdup(const char *s);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoin_gnl(char *buff, char *tmp);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strtrim2(char *s1, char *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
//////////////////////////////////////////////
int			ft_atoi(const char *str);
long long	ft_atol(const char *str);
char		*ft_itoa(int n);
//////////////////////////////////////////////
void		*ft_calloc(size_t nmemb, size_t size);
//////////////////////////////////////////////
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
//////////////////////////////////////////////
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//////////////////////////////////////////////
int			ft_printf(const char *format, ...);
int			ft_print_unsinged(unsigned long n);
int			ft_printptr(unsigned long address);
int			ft_printhex(unsigned long nbr, int maiusc);
//////////////////////////////////////////////
int			ft_putchar(char c);
int			ft_putstr(char *str);
//////////////////////////////////////////////
char		*ft_strjoin_gnl(char *s1, char *s2);
//////////////////////////////////////////////
char		*get_next_line(int fd);
// Minishell
t_token		*ft_lstnewtoken(t_token_type type, char *content);
void		ft_tokenadd_back(t_token **lst, t_token *new);
char		*ft_strndup(const char *s, size_t n);
int			ft_lstsize_token(t_token *lst);
int			ft_strlen_char(char *str, int c);
void		tkn_delone(t_token **current, t_token *del);

#endif
