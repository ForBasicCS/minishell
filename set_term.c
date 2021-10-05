/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_term.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minchoi <minchoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 10:51:38 by minchoi           #+#    #+#             */
/*   Updated: 2021/10/05 10:56:04 by minchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_input_mode(t_cmd *cmd)
{
	tcgetattr(STDIN_FILENO, &cmd->org_term); // STDIN으로부터 터미널 속성을 받아온다
}

// new_term에 원하는 터미널 속성 설정
void	set_input_mode(t_cmd *cmd)
{
	tcgetattr(STDIN_FILENO, &cmd->new_term); // STDIN으로부터 터미널 속성을 받아온다
	cmd->new_term.c_lflag &= ~(ICANON | ECHO);  // ICANON, ECHO 속성을 off
	cmd->new_term.c_cc[VMIN] = 1;               // 1 바이트씩 처리
	cmd->new_term.c_cc[VTIME] = 0;              // 시간은 설정하지 않음
	tcsetattr(STDIN_FILENO, TCSANOW, &cmd->new_term); // 변경된 속성의 터미널을 STDIN에 바로 적용
}

void	reset_input_mode(t_cmd *cmd)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &cmd->org_term);  // STDIN에 기존의 터미널 속성을 바로 적용
}
