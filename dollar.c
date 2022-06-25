#include "minishell.h"

int	ft_check_for_dollarsign(char *str)
{
	int	inside_s_quote;
	int	inside_d_quote;
	int	i;

	i = -1;
	inside_s_quote = 0;
	inside_d_quote = 0;
	while (str[++i])
	{
		quotes_check(&inside_s_quote, &inside_d_quote, str[i]);
		if (!inside_s_quote && str[i] == '$')
			return (1);
	}
	return (0);
}

int	ft_replace_wildcards(t_cmds *command, t_list *args_copy)
{
    int flag;

	// printf("qwe\n");
	while (args_copy)
	{
		if (ft_check_for_dollarsign(args_copy->content))
            flag = 1;
		args_copy->content = del_quotes(args_copy->content, command);
		args_copy = args_copy->next;
	}
    if (flag)
        return (0);
	return (1);
}