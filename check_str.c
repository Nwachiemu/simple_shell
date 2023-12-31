#include "shell.h"
/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter else 0
 */
bool is_chain(in_formations *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->sep_buff_kind = 1;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->sep_buff_kind = AND_F;
	}
	else if (buf[j] == ';')
	{
		buf[j] = 0;
		info->sep_buff_kind = CHAIN_F;
	}
	else
		return (false);
	*p = j;
	return (true);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(in_formations *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->sep_buff_kind == AND_F)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->sep_buff_kind == OR_F)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	*p = j;
}

/**
 * change_v - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int change_v(in_formations *info)
{
	int i = 0;
	list_stru *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;
		if (!compare_strinds(info->argv[i], "$?"))
		{
			change_string(&(info->argv[i]),

						   duplicate_strings(change_base(info->status, 10, 0)));

			continue;
		}
		if (!compare_strinds(info->argv[i], "$$"))
		{
			change_string(&(info->argv[i]),

						   duplicate_strings(change_base(getpid(), 10, 0)));

			continue;
		}
		node = node_str_start(info->env, &info->argv[i][1], '=');
		if (node)
		{
			change_string(&(info->argv[i]),

						   duplicate_strings(char_strings(node->str, '=') + 1));

			continue;
		}
		change_string(&info->argv[i], duplicate_strings(""));
	}
	return (0);
}
/**
 * change_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int change_string(char **old, char *new)
{
	free(*old);
	*old = new;

	return (1);
}
