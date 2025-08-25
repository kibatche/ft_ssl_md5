/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:40:18 by chbadad           #+#    #+#             */
/*   Updated: 2022/01/28 15:12:42 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

void				*ft_memset(void *dst, int c, size_t len);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *b, int c, size_t len);
int					ft_memcmp(const void *b1, const void *b2, size_t len);
size_t				ft_strlen(const char *s);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *big,
						const char *little, size_t len);
int					ft_atoi(const char *nptr);
void				*ft_calloc(size_t number, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *s1, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}		t_btree;

t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root,
						void *item, int (*cmpf)(void *, void *));
void				*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *));
int					btree_level_count(t_btree *root);
void				btree_apply_by_level(t_btree *root, void (*applyf)
						(void *item, int current_level, int is_first_elem));

int					ft_ischarset(int c, const char *charset);
char				*ft_strrev(char *str);
long int			ft_abs(long int n);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_isspace(int c);
char				*ft_itoa_base(long long n, int base);
void				*ft_memalloc(int size);
void				ft_memdel(void **p);
void				ft_putwchar_fd(int c, int fd);
void				ft_putchar(int c);
int					ft_atoi_base(const char *str, int base);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
char				*ft_strcapitalize(char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strncasecmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strcasestr(const char *big, const char *little);
char				*ft_strcat(char *s, const char *append);
char				*ft_strncat(char *s, const char *append, size_t count);
void				ft_strdel(char **s);
char				*ft_strins(char *dst, char *src);
char				*ft_strndup(const char *str, size_t len);
int					ft_ispunct(int c);
long long			ft_strtol(const char *nptr, char **endptr);
unsigned long long	ft_strtoul(const char *nptr, char **endptr);
char				*ft_strdupcat(char *s1, char *s2, size_t len);
char				**ft_str_split(char const *s, char *sep);
void				*ft_cleartab(void **tab, int len);
void				free_strs(char **strs);
char				*ft_strcpy(char *dst, const char *src);
int					ft_tablen(void **tab);
size_t				ft_tabs_len(char **tab);

#endif
