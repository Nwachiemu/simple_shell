#include "shell.h"

/**
 * _myexit - Exits the shell.
 * @info: Pointer to the info_t structure.
 *
 * Return: The exit status.
 */
/**
 * _mycd - changes the current directory of the process
 * @info: Structure containing potential arguments and environment variables.
 *
 * Return: 0 on success, 1 on error
 */
int _mycd(info_t *info)
{
	char *dir = NULL;
	int chdir_ret;

	if (!info->argv[1])
		dir = _getenv(info, "HOME=") ?: _getenv(info, "PWD=");
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD="));
		_putchar('\n');
		dir = _getenv(info, "OLDPWD=");
	}
	else
		dir = info->argv[1];

	if (chdir(dir) == -1)
	{
		perror("chdir");
		return (1);
	}

	if (update_pwd(info) == -1)
		perror("getcwd");

	return (0);
}

/**
 * _myhelp - Displays help information.
 * @info: Pointer to the info_t structure.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *info)
{
	(void)info;
	_puts("help call works. Function not yet implemented\n");
	return (0);
}
