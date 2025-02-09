/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:04:15 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/02/08 12:36:38 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

// helper functions
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_atoi(const char *str);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strchr(const char *s, char c);
char				*ft_strjoin2(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*get_next_line(int fd);

// parcing functions
int					*parce_nums(int ac, char **av, int *size);
int					has_duplicates(int *arr, int size);
void				free2(char **split, char *joined);

// lists functions
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);

// rules functions
void				swap(t_list **stack);
void				push(t_list **dest, t_list **src);
void				rotate(t_list **stack);
void				reverse_rotate(t_list **stack);

// moves functions
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);

// stack functions
void				assign_indexes(t_list *stack);
void				free_stack(t_list *stack);
int					is_sorted(t_list *stack);
t_list				*init_stack(int *nums, int size);

// bonus funcions
int					valid_instruction(char *line);
void				apply_instructions(char *line, t_list **stack_a,
						t_list **stack_b);
void				check_sorted(t_list *stack_a, t_list *stack_b);	

#endif
