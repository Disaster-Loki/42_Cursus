/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:53:05 by sde-carv          #+#    #+#             */
/*   Updated: 2024/10/17 10:53:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	cmd_pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
}

void	cmd_exit(char **mt)
{
	free_mat(mt);
	printf("exit\n");
	exit(0);
}

void	cmd_cd(t_shell *sh)
{
	char	*home;

	if (sh->mt[1] == NULL)
	{
		home = var_env(sh, "HOME");
		if (home)
			chdir(home);
		return ;
	}
	if (chdir(sh->mt[1]) != 0)
		printf("bash: cd: %s: No such file or directory\n", sh->mt[1]);
	if (sh->mt[2])
		printf("bash: cd: too many arguments\n");
}

void	cmd_echo(char **mt)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (mt[i] && !ft_strncmp(mt[i], "-n", ft_strlen(mt[i])))
	{
		flag = 1;
		i++;
	}
	if (mt[i] == NULL)
	{
		if (!flag)
			ft_putchar_fd('\n', 1);
		return ;
	}
	while (mt[i])
	{
		ft_putstr_fd(mt[i], 1);
		if (mt[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
}
