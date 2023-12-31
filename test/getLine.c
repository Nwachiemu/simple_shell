/**
 * input_buf - Buffers chained commands.
 * @info: Parameter struct.
 * @buf: Address of buffer.
 * @len: Address of len var.
 *
 * Return: Bytes read.
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)

		free(*buf);
	*buf = NULL;
	signal(SIGINT, sigintHandler);
	r = getline(buf, &len_p, stdin);
	if (r > 0)

		if ((*buf)[r - 1] == '\n')
		{
			(*buf)[r - 1] = '\0';
			r--;
		}
	info->linecount_flag = 1;
	remove_comments(*buf);
	build_history_list(info, *buf, info->histcount++);
	*len = r;
	info->cmd_buf = buf;
}

return (r);

/**
 * _getline - Gets the next line of input from STDIN.
 * @info: Parameter struct.
 * @ptr: Address of pointer to buffer, preallocated or NULL.
 * @length: Size of preallocated ptr buffer if not NULL.
 *
 * Return: Bytes read.
 */
int _getline(info_t *info, char **ptr, size_t *length);
char buf[READ_BUF_SIZE];
size_t i = 0, len = 0;
size_t k;
ssize_t r = 0, s = 0;
char *p = *ptr;
char *new_p = NULL;
char *c;

if (p && length)
{
	s = *length;
	if (i == len)
	{
		i = len = 0;
		r = read_buf(info, buf, &len);
	}
	if (r == -1 || (r == 0 && len == 0);
			return (-1);


			c = _strchr(buf + i, '\n');
			k = c ? 1 + (unsigned int)(c - buf) : len;
			new_p = _realloc(p, s, s ? s + k : k + 1);
			if (!new_p)
			return (p ? free(p), -1 : -1);


			if (s)
			_strncat(new_p, buf + i, k - i);
			else
			{
			_strncpy(new_p, buf + i, k - i + 1);
			}

			s += k - i;
			i = k;
			p = new_p;

			if (length)
				*length = s;
			*ptr = p;
			return (s);
}

