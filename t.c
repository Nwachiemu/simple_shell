#include "shell.h"

int handle_exit(in_formations *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = err_num(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			puts_err(info->argv[1]);
			putchar_err('\n');
			return (1);
		}
		info->error_code = err_num(info->argv[1]);
		return (-2);
	}
	info->error_code = -1;
	return (-2);
}
