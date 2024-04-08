/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:00:10 by agras             #+#    #+#             */
/*   Updated: 2022/08/02 15:35:30 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

//LIBC HEADERS

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>

//MACROS

# define ERROR 0
# define SA 1
# define SB 2
# define SS 3
# define PA 11
# define PB 22
# define RA 111
# define RB 222
# define RR 333
# define RRA 1111
# define RRB 2222
# define RRR 3333

# define FRONT_SLIDER 0
# define BACK_SLIDER 1

//STRUCTS

typedef struct s_moves
{
	int	total;
	int	to_do;
	int	to_do_then;
}			t_moves;

typedef struct s_instrc
{
	short			label;
	struct s_instrc	*prev;
	struct s_instrc	*next;
}	t_instrc;

typedef struct s_list
{
	int				content;
	int				place;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
typedef struct s_sliders
{
	t_list	*front;
	t_list	*back;
}	t_sliders;

typedef struct s_stacks
{
	t_list		*a;
	t_list		*b;
	int			tofind_len;
	int			tomove_len;
	int			best;
	int			switch_stacks;
	int			elem_selec;
	int			moveto_selec;
	t_list		*prev_elem;
	t_instrc	*instructions;
}	t_stacks;

// --------------  PROJECT SRC HEADERS --------------

// PARSE

int				parse_args(t_list **stack, char **av, int size);

// UTILS

char			**ft_split(char *s, char c);
unsigned int	ft_strlen(char *str);
int				ft_atoi_check(char *nptr, long *nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str, int fd);

// LIST MANAGEMENT

t_list			*ft_lstnew(int content);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstsearch(t_list *lst, int content);
void			ft_lstclear(t_list **lst, void (*del)(int content));
void			ft_lstprint(t_list *lst);
void			ft_nothing(int content);
void			ft_lstprint_int(int content);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstdup(t_list *lst);
t_list			*ft_lstnew_from(t_list *elem);

// INSTRUCTIONS

void			push_to_a(t_stacks *stacks);
void			push_to_b(t_stacks *stacks);
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			rotate_a(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			rrotate_a(t_stacks *stacks);
void			rrotate_b(t_stacks *stacks);
void			rotate(t_list **lst);
void			rrotate(t_list **lst);

void			push(t_list **l1, t_list **l2);
void			rotate(t_list **lst);
void			rrotate(t_list **lst);

// INSTRCUTIONS LIST MANAGEMENT

// void			add_instruction(t_instrc **instructions, short label);
// t_instrc		*ft_instrc_new(short content);

// EXIT

void			free_stacks(t_stacks *stacks);
int				exit_error(t_stacks *stacks);
int				exit_success(t_stacks *stacks);

// ALGO

void			basic_sort(t_stacks *prog);
void			simple_sort(t_stacks *prog);
void			radix_sort(t_stacks *prog, int max_digits);
int				is_sorted(t_list *stack);
int				is_ordered(t_list *stack);
long			get_absolute(int nb);
int				get_nb_binary_len(long nb);
void			init_sorting(t_stacks *stacks);
void			sort_number(t_stacks *stacks, t_moves moves);

#endif