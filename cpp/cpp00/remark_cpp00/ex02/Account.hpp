// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); //
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void ); //accounts, total, deposits, withdrawals를 보여줌

	Account( int initial_deposit ); //Account 생성자
	~Account( void ); //Account 소멸자

	void	makeDeposit( int deposit ); //index, p_amount, deposit, amount, nb_deposits를 보여줌
	bool	makeWithdrawal( int withdrawal ); //index, p_amount, withdrawal, amount, nb_withdrawal를 보여줌
	int		checkAmount( void ) const;
	void	displayStatus( void ) const; //index, amount, deposits, withdrawals를 보여줌


private:

	static int	_nbAccounts; //Accounts의 개수
	static int	_totalAmount; //Amount 함계
	static int	_totalNbDeposits; //Deposits 합계
	static int	_totalNbWithdrawals; //withdrawals 합계

	static void	_displayTimestamp( void ); //시간을 찍어주는 함수

	int				_accountIndex; //index
	int				_amount; //amount 양
	int				_nbDeposits; //Deposits 개수
	int				_nbWithdrawals; //Withdrawals 개수

	Account( void ); //Account 기본 생성자

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
