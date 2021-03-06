/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:04:11 by rlecart           #+#    #+#             */
/*   Updated: 2018/04/08 20:50:13 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <corewar.h>
# include <ncurses.h>
# include <limits.h>

# define REG champs[i].reg

# define O_NONE		0
# define O_REG		1
# define O_DIR		2
# define O_IND		4

typedef struct s_reg			t_reg;
typedef struct s_champ			t_champ;
typedef struct s_corewar		t_corewar;
typedef struct s_ocp			t_ocp;
typedef struct s_need_ocp		t_need_ocp;
typedef struct s_need_norm		t_need_norm;

struct				s_ocp
{
	int				p[3];
};

struct				s_need_norm
{
	int				i;
	int				r[3];
	int				tpc[2];
	t_ocp			ocp;
};

struct				s_need_ocp
{
	int				i;
	int				j;
	int				j2;
	int				tmp2;
	char			*tmp;
};

struct				s_reg
{
	int				n;
	int				pc;
	int				cycle;
	int				live_counter;
	int				r[REG_NUMBER];
	char			carry;
	t_reg			*prev;
	t_reg			*next;
};

struct				s_champ
{
	int				len;
	int				nbr_live;
	bool			is_alive;
	char			*name;
	char			*comment;
	char			*content;
	t_reg			*reg;
};

struct				s_corewar
{
	int				nbc;
	int				dump;
	int				cycle;
	int				cycle_tmp;
	int				max_checks;
	int				cycle_delta;
	int				cycle_to_die;
	int				nbr_live_all;
	int				nbr_processes;
	int				last_live_call;
	int				numbers[4];
	int				*colors;
	bool			flag_v;
	char			*map;
	char			*(champs_path[4]);
	void			(*opcodes[17])(t_corewar *, t_reg *);
	t_reg			**trash;
	t_champ			*champs;
};

void				check_dump(int ac, char **av, t_corewar *ret, int *i);
void				check_n(int ac, char **av, t_corewar *ret, int *(i[2]));
void				check_cor(char **av, t_corewar *ret, int *i, int *j);
t_corewar			check_all(int argc, char **argv);

void				error(int code, char *val);

t_champ				*get_all_champs(t_corewar data);

int					still_alive(t_champ *champs, int nbc);
int					live_counter(t_champ *champs, t_corewar *d);
void				reset_lives(t_champ *champs, int nbc);

int					*init_colors(t_champ *champs, t_corewar *d);
char				*init_battle(t_champ *champs, t_corewar *d);
void				init_opcodes(t_corewar *d);

void				battle(t_champ *champs, t_corewar *d);

void				display(char *map, int *colors, t_corewar *d);
void				display_map(char *map, int *colors, t_corewar *d);
void				display_champs_color(int color);

void				game(t_champ *champs, t_corewar *d, char *map);
void				end_game(t_champ *champs, t_corewar *d);

void				op_null(t_corewar *d, t_reg *reg);
void				op_live(t_corewar *d, t_reg *reg);
void				op_ld(t_corewar *d, t_reg *reg);
void				op_st(t_corewar *d, t_reg *reg);
void				op_add(t_corewar *d, t_reg *reg);
void				op_sub(t_corewar *d, t_reg *reg);
void				op_and(t_corewar *d, t_reg *reg);
void				op_or(t_corewar *d, t_reg *reg);
void				op_xor(t_corewar *d, t_reg *reg);
void				op_zjmp(t_corewar *d, t_reg *reg);
void				op_ldi(t_corewar *d, t_reg *reg);
void				op_sti(t_corewar *d, t_reg *reg);
void				op_fork(t_corewar *d, t_reg *reg);
void				op_lld(t_corewar *d, t_reg *reg);
void				op_lldi(t_corewar *d, t_reg *reg);
void				op_lfork(t_corewar *d, t_reg *reg);
void				op_aff(t_corewar *d, t_reg *reg);
t_reg				*fork_reg(t_reg *reg, int pc, bool mod);

int					find_hexa(char *str, int i, int len);
int					find_ocp(t_ocp *ret, unsigned char op, unsigned char ocp);
int					get_modulo(int n, int modulo);
bool				is_anybody_here(t_corewar *d, int pc);
bool				valid_ocp(t_ocp *ocp, unsigned char op);
bool				false_cmd(t_corewar *d, t_reg *reg, bool carry);
void				true_pc(int *pc);
void				put_hexa(t_corewar *d, int nbc, int pc, int value);
void				jump_to_next(t_reg *reg, int o);
t_reg				*get_first_reg(t_reg *reg);
int					get_processes(int nbc, t_champ *champs);

void				print_reg(t_reg *reg);
void				light_down(t_corewar *d, int *colors);
void				light_up_pc(t_corewar *d, int *colors);
int					get_color_here(t_corewar *d, int pc);

#endif
