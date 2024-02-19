/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftholoza <ftholoza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:49:01 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/19 17:03:01 by ftholoza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

int Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
	std::cout << ";deposit:" << deposit;
	_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount < withdrawal)
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:refused";
		std::cout << std::endl;
		return (false);
	}
	else
	{
		this->_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		std::cout << ";withdrawal:" << withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals;
		std::cout << std::endl;
	}
	return (true);
}

Account :: Account (int initial_deposit)
{
	_totalAmount += initial_deposit;
	_nbAccounts++;
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts - 1;
	this->_nbDeposits = 0;
	this->_displayTimestamp();
	std::cout << "index:", std::cout << _accountIndex; 
	std::cout << ";amount:", std::cout << _amount;
	std::cout << ";created" << std::endl;
}

void Account :: _displayTimestamp(void)
{
	time_t time_now = time(NULL);
    struct tm *pLocal = localtime(&time_now);
    std::cout << '[' << pLocal->tm_year + 1900;
	if (pLocal->tm_mon < 10)
		std::cout << "0"; 
	std::cout << pLocal->tm_mon << pLocal-> tm_mday << "_"
    << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec << "] ";
}

void Account :: displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:", std::cout << _totalAmount;
	std::cout << ";deposits:", std::cout << _totalNbDeposits;
	std::cout << ";withdrawals:", std::cout << _totalNbWithdrawals << std::endl;
}

void Account :: displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:", std::cout << _accountIndex;
	std::cout << ";amount:", std::cout << _amount;
	std::cout << ";deposits:", std::cout << this->_nbDeposits;
	std::cout << ";withdrawals:", std::cout << this->_nbWithdrawals << std::endl;
}

Account :: ~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount << ";closed" << std::endl;
}
