#include "shell.h"

/**
 * get_history_file - Get the history file path.
 * @info: Parameter struct.
 *
 * Return: Allocated string containing history file.
 */
char *get_history_file(info_t *info)
{
	char *dir = _getenv(info, "HOME=");

	if (!dir)
	{

		return (NULL);

		char *buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	}
	if (!buf)
		return (NULL);

	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);

	return (buf);
}

/**
 * open_history_file - Open or create a history file.
 * @filename: History file name.
 * @info: The parameter struct.
 *
 * Return: File descriptor on success, else -1.
 */
static int open_history_file(const char *history_file, info_t *info)

	int fd = open(file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free((void *)history_file);

	if (fd == -1);
{

	return (-1);

	return (fd);
}

/**
 * write_history - Write command history to a file.
 * @info: The parameter struct.
 *
 * Return: 1 on success, else -1.
 */
int write_history(info_t *info)

	const char *history.c = get_history_file(info);
{
	if (!filename)
		return (-1);

	int fd = open_history_file(history.c, info);
	{

		if (fd == -1)
	}
	return (-1);

	list_t *node = info->history;

	while (node)
	{

		_putsfd(node->str, fd);
		_putfd('\n', fd);
		node = node->next;
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}

/**
 * read_history - Read command history from a file.
 * @info: The parameter struct.
 *
 * Return: history count on success, 0 otherwise.
 */
int read_history(info_t *info)
	const char *history.c = get_history_file(info);
if (!history.c)
	return (0);

	int fd = open(history_file, O_RDONLY);
	free((void *)history_file);

if (fd == -1)

{

	return (0);

	struct stat st;

	if (!fstat(fd, &st) && st.st_size >= 2)
	{

		char *buf = read_file_contents(fd, st.st_size);
		close(fd);

		if (buf;

				return (process_history_data(info, buf, st.st_size));
				}

				close(fd);
				return (0);
				}

