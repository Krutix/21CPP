#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ';'
			  << "total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts++),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_totalAmount += this->_amount;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ";created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ";closed\n";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:"
		<< deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << '\n';
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused\n";
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal
			<< ";nb_withdrawal:" << this->_nbWithdrawals + 1 << '\n';
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbWithdrawals << ";withdrawals:" << this->_nbWithdrawals << '\n';
}

void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(nullptr);
	std::cout << '[' << std::put_time(gmtime(&t), "%Y%m%d_%H%M%S") << ']';
}
