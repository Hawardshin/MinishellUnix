
#include "node.h"
#include "utils.h"
#include "libft.h"

static void	tok_buff_init(t_readline *src, char **tok_buff, t_token *tok)
{
	char	*env_text;
	int		i;

	i = 0;
	while ((token_case(see_char(src)) != D_QUOTES) && (see_char(src) != ENDOF))
	{
		if (token_case(see_char(src)) == DOLLAR)
		{
			env_text = make_env_text(src);
			while (env_text && *env_text)
				(*tok_buff)[i++] = *env_text++;

		}
		else
			(*tok_buff)[i++] = move_char(src);
	}
	(*tok_buff)[i] = '\0';
	tok->tok_type = ARGV_TOK;
}

static char	*make_double_tok(t_readline *src, t_token *tok)
{
	char	*tok_buff;

	tok_buff = malloc(ft_all_len(src) + 1);
	if (!tok_buff)
		print_error(0, NULL);
	tok_buff_init(src, &tok_buff, tok);
	return (tok_buff);
}

t_token	*create_d_quotes(t_readline *src)
{
	t_token	*tok;

	move_char(src);
	tok = malloc(sizeof(t_token));
	if (!tok)
		print_error(0, NULL);
	ft_memset(tok, 0, sizeof(t_token));
	tok->text = make_double_tok(src, tok);
	if (token_case(see_char(src)) == ENDOF)
		tok->tok_type = ERROR_TOK;
	else
		move_char(src);
	tok->text_len = ft_strlen(tok->text);
	return (tok);
}
