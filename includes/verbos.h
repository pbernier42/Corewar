/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbernier <pbernier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:20:02 by pbernier          #+#    #+#             */
/*   Updated: 2017/11/16 20:49:14 by pbernier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERBOS_H
# define VERBOS_H

/*
** color
*/
# define RESET "\033[0m"
# define RED "\033[38;5;1m"
# define RED_MINUS "\033[38;5;9m"
# define GREEN_MINUS "\033[38;5;10m"
# define GREY "\033[38;5;8m"
# define WHITE "\033[38;5;7m"
# define GRAS "\033[1m"

/*
** error
*/
# define NB_ARG 1
# define EXTENTION 2
# define OPEN_CHAMP 3
# define READ_CHAMP 4
# define MALLOC 5

/*
** verbos
*/
# define NAME_EXIST 0
# define SYNTAX 1
# define NAME_LEN 2
# define INVALID_NAME 3
# define NAME_DIFF_FILE 4
# define INVALID_CHAR 5
# define COMMENT_EXIST 6
# define COMMENT_LEN 7
# define INVALID_COMMANDE 8
# define INVALID_LABEL 9
# define INVALID_OPCODE 10
# define OPCODE_EXIST 11
# define NEED_ARG 12
# define WRONG_ARG 13
# define INVALID_REG 14
# define NOT_ENOUGHT_ARG 15
# define INVALID_ARG_LABEL 16
# define INVALID_DIR 17

# define MISSING_NAME 18
# define MISSING_COMMENT 19

# endif
