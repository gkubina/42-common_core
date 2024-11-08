/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkubina <gkubina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:44:05 by gkubina           #+#    #+#             */
/*   Updated: 2024/07/02 14:08:30 by gkubina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

	Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}

	Account::Account( void )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;

}

	Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount()
	<< ";deposit:" << deposit; 
	this->_amount += deposit;
	std::cout << ";amount:"<< checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount()
	<< ";withdrawal:"; 
	if (withdrawal <= this->_amount)
	{
		_nbWithdrawals++;	
		this->_amount -= withdrawal;
		std::cout  << withdrawal << ";amount:"<< checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return(1);
	}
	else
		std::cout << "refused" << std::endl;
	return (0);
}
	
int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout << "[";
	std::cout << 1900 + ltm->tm_year;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << 1 + ltm->tm_mon;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << ltm->tm_mday;
	std::cout << "_";
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << ltm->tm_hour;
	std::cout.width(2);
	std::cout.fill('0');
	std::cout << ltm->tm_min;
	std::cout.width(2);
	std::cout.fill('0');	
	std::cout << ltm->tm_sec;
	std::cout << "]";
	//std::cout << "[19920104_091532]";
}
