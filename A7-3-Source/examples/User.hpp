#ifndef __USER_H__
#define __USER_H__

#include "Room.hpp"
#include "DeluxeRoom.hpp"
#include "LuxuryRoom.hpp"
#include "PremiumRoom.hpp"
#include "StandardRoom.hpp"
#include "Exceptions.hpp"

class User
{
public:
	User(std::string email, std::string username, std::string password);
	bool is_duplicate_user(std::string email, std::string username);
	bool login(std::string email, std::string password);
	void logout();
	void wallet_amount(double amount);
	std::string get_user_name();
	double get_user_wallet_amount();

private:
	std::string user_name;
	std::string user_email;
	size_t user_password_hash;
	bool user_logged;
	double user_wallet_amount;
	std::vector<double> user_wallet_turnover;

};

#endif 