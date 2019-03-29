/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikourkji <ikourkji@student.42.us.or>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:35:46 by ikourkji          #+#    #+#             */
/*   Updated: 2019/03/29 11:57:32 by ikourkji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

# define MIN(x, y) ( (x) < (y) ? (x) : (y) )
# define MAX(x, y) ( (x) > (y) ? (x) : (y) )

# define IFRET(x, y) if (x) return (y)
# define ELIFRET(x, y) else if (x) return (y)
# define ELRET(y) else return (y)

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memrchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_atoi_skip(char **str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_iswhite(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isnan(long double f);
int					ft_isinf(long double f);
int					ft_isninf(long double f);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_charat(const char *s, char c);

void				*ft_memalloc(size_t size);
void				*ft_rememalloc(void *ptr, size_t old_s, size_t new_s);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubdel(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoindel(char *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_c(char const *s, char c);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_puterror(char const *s);

uint32_t			ft_swapend32(uint32_t n);
int					ft_findintab(char **haystack, char *needle);
int					ft_findintabn(char **haystack, char *needle, size_t len);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **also, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstmsort(t_list **lst, int (*f)(t_list*, t_list*));

typedef struct		s_qnode
{
	void			*content;
	struct s_qnode	*next;
}					t_qnode;

typedef struct		s_queue
{
	t_qnode			*first;
	t_qnode			*last;
}					t_queue;

int					ft_qis_empty(t_queue *queue);
t_queue				*ft_qinit(void);
void				ft_enqueue(t_queue *queue, void *content);
void				*ft_dequeue(t_queue *queue);
void				*ft_qpeek(t_queue *queue);

typedef struct		s_stnode
{
	void			*content;
	struct s_stnode	*next;
}					t_stnode;

typedef struct		s_stack
{
	struct s_stnode	*top;
}					t_stack;

int					ft_stis_empty(t_stack *stack);
t_stack				*ft_stinit(void);
void				*ft_pop(t_stack *stack);
void				ft_push(t_stack *stack, void *content);
void				*ft_stpeek(t_stack *stack);
#endif
