/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:41:49 by jlim              #+#    #+#             */
/*   Updated: 2022/01/23 22:41:50 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0; //Accounts개수를 일단 0으로 초기화
int	Account::_totalAmount = 0; //totalAmount를 0으로 초기화
int	Account::_totalNbDeposits = 0; //totalNbDeposits를 0으로 초기화
int	Account::_totalNbWithdrawals = 0; //totalNbWithdrawals를 0으로 초기화

void	Account::_displayTimestamp(void)
{//앞의 시간을 찍어주는 함수
	time_t	timestamp;
	char	buff[16];

	time(&timestamp);
	strftime(buff, sizeof(buff), "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << buff << "]";
}

Account::Account(int initial_deposit)
{//Account생성자, Account가 생성될 때 바로 실행
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";created" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits = 1;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	result;
	_amount -= withdrawal;

	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex << ";";
	if (_amount < 0)
	{//amount가 0보다 작으면 withdrawal은 거절되고 기존의 amount값으로 복귀
		result = 0;
		_amount += withdrawal;
		std::cout << "p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	}
	else
	{
		result = 1;
		_nbWithdrawals = 1;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "p_amount:" << _amount + withdrawal << ";";
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (result);
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";closed" << std::endl;
}

