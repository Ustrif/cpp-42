#include <iostream>
#include "Account.hpp"
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";deposit:" << deposit
			<< ";amount:" << (_amount + deposit)
			<< ";nb_deposits:" << (_nbDeposits + 1)
			<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (withdrawal > _amount)
	{
		std::cout	<< ";withdrawal:refused"
					<< std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}

Account::Account( int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *t = gmtime(&now);

	std::cout	<< "["
				<< 1900 + t->tm_year
				<< ((t->tm_mon + 1) < 10 ? "0" : "") << (t->tm_mon + 1) 
				<< (t->tm_mday < 10 ? "0" : "") << t->tm_mday
				<< "_"
				<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour
				<< (t->tm_min < 10 ? "0" : "") << t->tm_min
				<< (t->tm_sec < 10 ? "0" : "") << t->tm_sec
				<< "] ";
}


