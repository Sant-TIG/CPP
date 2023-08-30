#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
 * Parameterized constructor. Initializes the instance variables.
 */
Account::Account( int initial_deposit ) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

/*
 * Destructor.
 */
Account::~Account( void ) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed" << std::endl;
}

/*
 * Getter methods
 */
int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

/*
 * Processes a user's cash deposit.
 * Parameters:
 *     deposit: the amount to be deposited
 */
void	Account::makeDeposit( int deposit ) {
	int	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << p_amount
			  << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

/*
 * Processes a user's cash withdrawal. In case the amount to be withdrawn is greater than
 * the amount available, it rejects the transaction.
 * Parameters:
 *     withdrawal: the amount to be withdrawn
 * return:
 *    true: if the withdrawal can be made
 *    false: if it not.
 */
bool	Account::makeWithdrawal( int withdrawal ) {
	int p_amount = _amount;
	_amount -=withdrawal;
	if (checkAmount()) {
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbDeposits
				<< std::endl;		
		return true;
	} else {
		_amount = p_amount;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
				  << ";p_amount:" << _amount
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
}

/*
 * Check if withdrawal can be made.
 * Return:
 *     0: if it can't be made.
 *     1: if it can.
 */
int	Account::checkAmount( void ) const {
	return _amount >= 0;
}

/*
 * Displays summary information for all accounts.
 */
void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount 
			  << ";deposits:" << _totalNbDeposits 
			  << ";withdrawals:" << _totalNbWithdrawals 
			  << std::endl;
}

/*
 * Displays the specific information for one account.
 */
void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

/*
 * Displays a timestamp formatted as follow: [%Y%m%d_%H%M%S]
 *     Y: represents the year with four digits
 *     m: represents the month in two digits
 *     d: represents the day in two digits
 *     H: represents the hour in 24-hour format with two digits
 *     M: represents the minutes with two digits
 *     S: represents the seconds with two digits
 */
void	Account::_displayTimestamp( void ) {
	char		buffer[21];
	std::time_t	currentTime = std::time(NULL);
	std::tm		*timeInfo = std::localtime(&currentTime);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeInfo);
	std::cout << buffer;
}
