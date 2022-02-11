#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    std::cout << "[19920104_091532] ";
}

Account::Account( void )
{
    this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    this->_accountIndex = _nbAccounts;
    std::cout << "index:" << this->_accountIndex << ';';
    this->_amount = initial_deposit;
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "created" << '\n';
    _totalAmount += this->_amount;
    _nbAccounts++;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "closed" << '\n';
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ';';
    std::cout << "total:" << _totalAmount << ';';
    std::cout << "deposits:" << _totalNbDeposits << ';';
    std::cout << "withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "deposits:" << this->_nbDeposits << ';';
    std::cout << "withdrawals:" << _nbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "p_amount:" << this->_amount << ';';
    std::cout << "deposit:" << deposit << ';';
    this->_amount += deposit;
    this->_nbDeposits++;
    std::cout << "amount:" << this->_amount << ';';
    std::cout << "nb_deposits:" << this->_nbDeposits << '\n';
    _totalAmount += deposit;
    _totalNbDeposits++;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ';';
    std::cout << "p_amount:" << this->_amount << ';';
    try {
        if (checkAmount() < withdrawal) throw 0;
        std::cout << "withdrawal:" << withdrawal << ';';
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        std::cout << "amount:" << this->_amount << ';';
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << '\n';
        _totalNbWithdrawals++;
    } catch (int except) {
        std::cout << "withdrawal:refused" << '\n';
        return (false);
    }
    return (true);
}

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
