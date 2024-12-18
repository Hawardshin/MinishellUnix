
#include "node.h"
#include "utils.h"
#include "libft.h"

static t_token	*create_token(t_readline *src)
{
	if (token_case(see_char(src)) == QUOTES)
		return (create_quotes(src));
	else if (token_case(see_char(src)) == D_QUOTES)
		return (create_d_quotes(src));
	else if (token_case(see_char(src)) == SPACE_B)
		return (create_space_tok(src));
	else if (token_case(see_char(src)) == PIPE)
		return (create_pipe_tok(src));
	else if (token_case(see_char(src)) == DOLLAR)
		return (create_dollar_tok(src));
	else if (token_case(see_char(src)) == DIRECT)
		return (create_direct_tok(src));
	else if (token_case(see_char(src)) == RE_DIRECT)
		return (create_redirect_tok(src));
	else if (token_case(see_char(src)) == CHAR)
		return (create_char_tok(src));
	return (NULL);
}

static t_main_token	*main_tok_init(t_token *tmp)
{
	t_main_token	*main_tok;

	main_tok = malloc(sizeof(t_main_node));
	if (!main_tok)
		print_error(0, NULL);
	ft_memset(main_tok, 0, sizeof(t_main_node));
	main_tok->start_token = tmp;
	main_tok->end_token = tmp;
	return (main_tok);
}

static t_main_token	*tok_error(t_main_token	*main_tok, t_token *tmp)
{
	main_tok -> is_error = 1;
	tmp->next = NULL;
	return (main_tok);
}

t_main_token	*tokenize(t_readline *src)
{
	t_main_token	*main_tok;
	t_token			*tmp;
	t_token			*next;

	tmp = create_token(src);
	main_tok = main_tok_init(tmp);
	while (tmp)
	{
		if (tmp->tok_type == ERROR_TOK)
			return (tok_error(main_tok, tmp));
		next = create_token(src);
		tmp->next = next;
		if (!next)
		{
			main_tok->end_token = tmp;
			break ;
		}
		next->bef = main_tok->end_token;
		next->next = NULL;
		main_tok->token_num++;
		tmp = next;
	}
	merge_argv_tok(main_tok);
	delete_all_space_tok(main_tok);
	return (main_tok);
}
