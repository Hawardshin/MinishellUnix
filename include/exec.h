#ifndef EXEC_H
# define EXEC_H
# include "node.h"

void	infile_init(t_node *node, int *o_fd);
void	outfile_init(t_node *node, int *w_fd);
void	exec_first(t_main_node *px);
void	exec_pipe(int idx, t_main_node *px);
void	exec_last(t_main_node *px);
#endif
