#include "User.hpp"
using namespace std;

User::User(string email, string username, string password)
{
	user_email = email;
	user_name = username;
	user_password_hash = hash<string>{}(password);
	user_logged = true;
	user_wallet_amount = double(0);
	user_wallet_turnover.push_back(user_wallet_amount);
}

bool User::is_duplicate_user(string email, string username)
{
	if (user_name == username || user_email == email)
		return true;
	else
		return false;
}

bool User::login(string email, string password)
{
	if (user_email == email && user_password_hash == hash<string>{}(password))
	{
		if(user_logged == true)
			throw YouAreLoginException();
		user_logged = true;
		return true;
	}
	else
		return false;
}

void User::logout()
{
	user_logged = false;
}

void User::wallet_amount(double amount)
{
	user_wallet_amount += amount;
	user_wallet_turnover.push_back(user_wallet_amount);
}

string User::get_user_name() { return user_name; }

double User::get_user_wallet_amount() { return user_wallet_amount; }