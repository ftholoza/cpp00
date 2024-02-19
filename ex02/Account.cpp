/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:49:01 by ftholoza          #+#    #+#             */
/*   Updated: 2024/02/18 19:38:39 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>


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
		//_displayTimestamp();
		//std::cout << std::endl;
		//this->displayStatus();
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
	std::cout << "[19920104_091532] ";
	std::cout << "index:", std::cout << _accountIndex; 
	std::cout << ";amount:", std::cout << _amount;
	std::cout << ";created" << std::endl;
}

void Account :: _displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}

void Account :: displayAccountsInfos(void)
{
	std::cout << "[19920104_091532] accounts:", std::cout << _nbAccounts;
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

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}