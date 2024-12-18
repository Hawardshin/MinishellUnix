
#include "node.h"

int	check_syntax(t_token *start_tok)
{
	t_token	*tok;

	tok = start_tok;
	while (tok)
	{
		if (tok->tok_type == PIPE_TOK)
		{
			if (tok->bef == NULL || tok->next == NULL \
		|| tok->bef->tok_type == PIPE_TOK || tok->next->tok_type == PIPE_TOK)
			{
				g_state.exit_code = 258;
				return (1);
			}
		}
		else if (tok->tok_type == IO_TOK)
		{
			if (tok->next == NULL || tok->next->tok_type != ARGV_TOK)
			{
				g_state.exit_code = 258;
				return (1);
			}
		}
		tok = tok->next;
	}
	return (0);
}
