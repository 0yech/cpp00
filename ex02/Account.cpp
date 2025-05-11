/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrey <nrey@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:15:54 by nrey              #+#    #+#             */
/*   Updated: 2025/05/11 20:03:31 by nrey             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

//	Initiating so called "global" values, which are just private static vars.
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//	Constructor call, creating an account with an initial amount.
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount+= initial_deposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

//	Destructor call, no need for frees since only static elements are created.
Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount" << _amount
				<< ";closed" << std::endl;
}

//	Display time stamp before any log.
void Account::_displayTimestamp()
{
	std::time_t current;
	std::tm *t;

	current = std::time(NULL);
	t = std::localtime(&current);
	std::cout	<< "["
				<< (t->tm_year + 1900)
				<< std::setw(2) << std::setfill('0') << t->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << t->tm_mday << "_"
				<< std::setw(2) << std::setfill('0') << t->tm_hour
				<< std::setw(2) << std::setfill('0') << t->tm_min
				<< std::setw(2) << std::setfill('0') << t->tm_sec
				<< "] ";
}

/*	Displays the status of an Account object.
	"const member functions" are functions which
	will have no rights on editing its content.
	Used here because the function only displays data.
*/	
void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals" << _nbWithdrawals
				<< std::endl;
}

/*	Prints the deposit information,
	updates the static and non-static vars
	and prints the succesful deposit.
*/
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

/*	Prints the withdrawal information.
	Checks if the withdrawal is possible.
	Updates the static and non-static vars
	and prints the output.
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -=withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

//	Prints all static vars
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total" << _totalAmount
				<< ";deposits" << _totalNbDeposits
				<< ";withdrawals" << _totalNbWithdrawals
				<< std::endl;
}


