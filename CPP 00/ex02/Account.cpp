/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khuynh <khuynh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:13:22 by khuynh            #+#    #+#             */
/*   Updated: 2023/06/09 20:37:34 by khuynh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

Account::Account(void) { return ;}
Account::~Account(void) { return ;}

int	Account::getNbAccounts(void) {return (Account::_nbAccounts);}
int	Account::getTotalAmount(void) {return (Account::_totalAmount);}
int	Account::getNbDeposits(void) {return (Account::_totalNbDeposits);}
int	Account::getNbWithdrawals(void) {return (Account::_totalNbWithdrawals);}
int	Account::checkAmount(void) const {return (this->_amount);}

void	Account::_displayTimestamp(void)
{
	time_t		now = time(0);
	struct tm	*ltm = localtime(&now);

	std::cout << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() + 1 << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}
