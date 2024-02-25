/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:16:16 by lissam            #+#    #+#             */
/*   Updated: 2024/02/25 17:19:24 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct node
{
	int data;
	struct node *next;
} t_data;

typedef struct numbers
{
	char **numbers;
	int argc_number;
} t_numbers;

void ft_putstr(char *str);
void check_n_args(int ac);
char **ft_split(char const *s, char c);
size_t ft_strlen(const char *str);
char *ft_substr(char const *s, unsigned int start, size_t len);
void insert_back(t_data **head, int nb);
// void			creat_stack_a(t_numbers *the_numbers, t_data *head);
int if_number(char *str);
int ft_atoi(char *str);
void check_doubles(t_data **stack_a);
int count_nodes(t_data **stack);
void swap_a(t_data **stack_a);
void rotate_a(t_data **stack_a);
void reverse_rotate_a(t_data **stack_a);
void push_b(t_data **stack_a, t_data **stack_b);
void swap_b(t_data **stack_b);
void rotate_b(t_data **stack_b);
void reverse_rotate_b(t_data **stack_b);
void push_a(t_data **stack_b, t_data **stack_a);
void ss(t_data **stack_a,t_data **stack_b);
void rr(t_data **stack_a,t_data **stack_b);
void rrr(t_data **stack_a,t_data **stack_b);


#endif