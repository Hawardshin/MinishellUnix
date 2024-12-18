
#ifndef BUILTIN_H
# define BUILTIN_H

# include "node.h"
int		cmd_len(char **cmd);
void	ft_cd(char **cmd, int flag);
void	ft_echo(char **cmd);
void	ft_env(int is_sort, char *format);
void	ft_exit(char	**cmd);
void	ft_export(char **cmd);
void	ft_pwd(void);
void	ft_unset(char **cmd);
int		ft_in_built(t_node *val, int flag);
int		ft_built_check(char *str);
int		ft_built_first_check(char *str);
#endif
