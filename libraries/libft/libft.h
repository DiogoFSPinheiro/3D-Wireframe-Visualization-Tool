/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:16:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/20 09:48:34 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 50
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <stdbool.h>
# include <fcntl.h>

//typedef struct s_list
//{
//	void			*content;
//	struct s_list	*next;
//}	t_list;
void	*ft_calloc(size_t n, size_t size);
char	*ft_strdup(char const *src);
void	ft_bzero(void *ptr, size_t n);
int		ft_atoi(const char *str);
char	*ft_strnstr(const char *big, const char *little, size_t t);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	*ft_memchr(const void *src, int c, size_t n);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, int x, size_t n);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalnum(char c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
int		ft_perror_exit(char *str);
void	free_args(char **numbers);
//t_list	*ft_lstlast(t_list *list);
//t_list	*ft_lstnew(void *content);
//int		ft_lstsize(t_list *lst);
//void	ft_lstadd_back(t_list **lst, t_list *new);
//void	ft_lstadd_front(t_list **lst, t_list *new);
//void	ft_lstdelone(t_list *lst, void (*del)(void*));
//void	ft_lstclear(t_list **lst, void (*del)(void *));
//void	ft_lstiter(t_list *lst, void (*f)(void *));
//t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
//-----------gnl-----------------
void	ft_bzero(void *ptr, size_t n);
int		str_len(const char *str);
void	*ft_calloc_nl(size_t n, size_t size);
char	*str_join(char *stack, char *buffer);
char	*read_file(int fd, char *stack);
char	*polish(char *stack);
char	*get_next_line(int fd);
char	*get_end_line(char *stack);
int		words(char const *s, char c);

#endif
