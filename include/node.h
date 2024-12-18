
#ifndef NODE_H
# define NODE_H

# include<signal.h>
# include<stdio.h>
# include<sys/wait.h>
# include<readline/readline.h>
# include<readline/history.h>
# include<sys/stat.h>
# include<sys/wait.h>
# include<unistd.h>
# include<stdlib.h>
# include<errno.h>
# include<fcntl.h>

enum e_char_case
{
	ENDOF = -1,
	CHAR = 10,
	PIPE ,
	QUOTES ,
	D_QUOTES,
	SPACE_B,
	DOLLAR,
	DIRECT,
	RE_DIRECT,
} ;

typedef enum e_outfile_type
{
	APPEND_TYPE=10,
	WRITE_TYPE
}	t_outfile_type;

typedef enum e_tok_type
{
	IO_TOK = 10,
	ARGV_TOK,
	PIPE_TOK,
	SPACE_TOK,
	ERROR_TOK,
	DELETE_TOK,
}	t_toke_type;

typedef struct s_infile_node
{
	int						is_heardoc;
	char					*file;
	struct s_infile_node	*hnext;
	struct s_infile_node	*hprev;
	struct s_infile_node	*prev;
	struct s_infile_node	*next;
}	t_infile_node;

typedef struct s_outfile_node
{
	char					*file;
	t_outfile_type			type;
	struct s_outfile_node	*prev;
	struct s_outfile_node	*next;
}	t_outfile_node;

typedef struct s_node
{
	int				idx;
	char			**cmd;
	char			*cmd_path[2];
	t_infile_node	*heardoc_node;
	t_infile_node	*infile_node;
	t_outfile_node	*outfile_node;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_main_node
{
	char	**ev;
	char	**path;
	int		**pipefd;
	int		cmd_num;
	t_node	*node_head;
	t_node	*node_tail;
}	t_main_node;

typedef struct s_token
{
	t_toke_type		tok_type;
	int				text_len;
	char			*text;
	struct s_token	*bef;
	struct s_token	*next;
}	t_token;

typedef struct s_main_token
{
	t_token	*start_token;
	t_token	*end_token;
	int		token_num;
	int		is_error;
}	t_main_token;

/*env*/
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef struct s_env_main_node
{
	t_env	*head;
	t_env	*tail;
	int		count;
}	t_env_main_node;

typedef struct s_state
{
	t_env_main_node	env_main_node;
	pid_t			pid;
	int				exit_code;
}	t_state;

typedef struct s_readline
{
	char	*buffer;
	int		bufsize;
	int		now_pos;
}	t_readline;

t_state	g_state;

t_main_token	*tokenize(t_readline *src);
char			see_char(t_readline *src);
char			move_char(t_readline *src);
int				token_case(char a);
int				ft_env_len(t_readline *src);
t_token			*create_quotes(t_readline *src);
t_token			*create_d_quotes(t_readline *src);
t_token			*create_space_tok(t_readline *src);
t_token			*create_pipe_tok(t_readline *src);
t_token			*create_dollar_tok(t_readline *src);
t_token			*create_direct_tok(t_readline *src);
t_token			*create_redirect_tok(t_readline *src);
t_token			*create_char_tok(t_readline *src);
void			merge_argv_tok(t_main_token *tok);
void			delete_all_space_tok(t_main_token *tok);
int				ft_dallar_len_utils(t_readline *src);

void			connect_two_node(t_env *front, t_env *back);
void			env_lst_delete(char *key);
void			env_lst_add_back(char *key, char *value);
void			init_g_state(char **envp);
char			*get_env(char *key);
int				check_syntax(t_token *start_tok);
t_env			*env_of_idx(t_env_main_node main_node, int idx);
void			free_all_env_main_node(t_env_main_node *main_node);
void			swap_env(t_env_main_node main_node, int idx1, int idx2);
char			*make_env_text(t_readline *src);
t_env_main_node	env_dup(t_env_main_node env);

t_main_node		*make_tok_to_node(t_main_token *tok);
char			*find_path(char *text, t_main_node *main_node);
void			make_hdoc_node(t_node *node, t_token **tmp_tok);
void			make_ifile_node(t_node *node, t_token **tmp_tok);
void			make_ofile_node(t_node *node, t_token **tmp_tok);
void			make_rfile_node(t_node *node, t_token **tmp_tok);
t_node			*make_pipe_node(t_token **tmp_tok, t_main_node *main_node);
t_main_node		*main_init(t_main_token **tok, \
							t_token **tmp_tok, t_node **node);
int				fork_child(t_main_node *px);

void			ft_all_close(t_main_node *px, int idx, int bef);
t_node			*mlst_find(int idx, t_main_node *data);

int				ft_all_len(t_readline *src);
void			init_rd_line(t_readline *src, char *rd_line);
void			ft_tc_on(void);

#endif
