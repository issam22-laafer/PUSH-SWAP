/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:16:16 by lissam            #+#    #+#             */
/*   Updated: 2024/02/24 11:13:34 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
void swap_a(t_data **stack_a);

#endif