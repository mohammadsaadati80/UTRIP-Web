#include "Utrip.hpp"
using namespace std;

Utrip::Utrip(vector<Hotel> _hotels_info)
{
	hotels_info = _hotels_info;
	managefilter.add_all_hotels(hotels_info);
}

vector<Hotel*> Utrip::get_all_hotels() 
{
	vector<Hotel*> all_hotels;
	for(int current = 0; current < hotels_info.size(); current++)
		all_hotels.push_back(&hotels_info[current]);
	return all_hotels;
}

Hotel Utrip::get_hotel(string id)
{
	for(int current = 0;current < hotels_info.size(); current++)
		if(hotels_info[current].get_hotel_unique_id() == id)
			return hotels_info[current];
}

vector<Hotel*> Utrip::get_filtered_hotels()
{
	return managefilter.get_filtered_hotel();
}

void Utrip::update_star_filter(int min, int max)
{
	managefilter.add_new_star_filter(min, max);
}

double Utrip::get_user_wallet(string email)
{
	for(int current = 0; current < logged_user.size(); current++)
		if (logged_user[current].session_id == email)
			return logged_user[current].current_user->get_user_wallet_amount();
}

void Utrip::manage_star_filter(vector<string> args)
{
	int min_star;
	int max_star;
	for (int current = 0; current < args.size(); current += 2)
	{
		if (args[current] == MIN_STAR)
			min_star = stoi(args[current + 1]);
		else if (args[current] == MAX_STAR)
			max_star = stoi(args[current + 1]);
		else
			throw BadRequestException();
	}
	managefilter.add_new_star_filter(min_star, max_star);
}

void Utrip::create_new_user(string email, string username, string password)
{
	for (int current = 0; current < users_info.size(); current++)
		if (users_info[current].is_duplicate_user(email, username)) 
			throw DuplicateUserException();	
	users_info.push_back(User(email, username, password));
	UserLogin new_user;
	new_user.session_id = email;
	new_user.current_user = &users_info[users_info.size() - 1];
	logged_user.push_back(new_user);
	managefilter.update_sort_user(&users_info[users_info.size() - 1]);
}

void Utrip::login_new_user(string email, string password)
{
	for (int current = 0; current < users_info.size();current++)
		if (users_info[current].login(email, password))
		{
			UserLogin new_user;
			new_user.session_id = email;
			new_user.current_user = &users_info[current];
			logged_user.push_back(new_user);
			managefilter.update_sort_user(&users_info[current]);
			return;
		}
	throw UserNotFoundException();
}

void Utrip::logout(string email)
{
	if (logged_user.size() > 0)
	{
		for(int current = 0; current < logged_user.size(); current++)
			if(logged_user[current].session_id == email)
			{
				logged_user[current].current_user->logout();
				logged_user.erase(logged_user.begin() + current);
				managefilter.delete_all_filters();
				managefilter.update_sort_user(NULL);
				managefilter.delete_sort();
			}
	}
	else
		throw PermissionDeniedException();
}

void Utrip::wallet_amount_current_user(double amount,string email)
{
	if (amount <= 0)
		throw BadRequestException();
	for(int current = 0; current < logged_user.size(); current++)
		if(logged_user[current].session_id == email)
			logged_user[current].current_user->wallet_amount(amount);
}

void Utrip::check_user_login()
{
	if (logged_user.size() == 0)
		throw PermissionDeniedException();
}