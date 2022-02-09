#ifndef __UTRIP_H__
#define __UTRIP_H__

#include "Exceptions.hpp"
#include "Hotel.hpp"
#include "User.hpp"
#include "Tools.hpp"
#include "DeluxeRoom.hpp"
#include "LuxuryRoom.hpp"
#include "PremiumRoom.hpp"
#include "StandardRoom.hpp"
#include "ManageFilter.hpp"

#define HOTELS_FILE 1
#define RATINGS_FILE 2
#define POST_COMMAND "POST"
#define GET_COMMAND "GET"
#define DELETE_COMMAND "DELETE"
#define COMMAND_SEPARATOR ' '
#define ENDL '\n'
#define SEPARATOR_BEFORE_ARGUMENT "?"
#define SIGNUP_COMMAND "signup"
#define SIGNUP_ARGUMENT_NUMBER 6
#define USERNAME "username"
#define EMAIL "email"
#define PASSWORD "password"
#define LOGIN "login"
#define LOGIN_ARGUMENT_NUMBER 4
#define LOGOUT_COMMAND "logout"
#define WALLET_COMMAND "wallet"
#define AMOUNT "amount"
#define WALLET_AMOUNT_ARGUMENT_NUMBER 2
#define HOTELS_COMMAND "hotels"
#define OK "OK"
#define SHOW_HOTEL_INFO_ARGUMENT_NUMBER 2
#define ID "id"
#define COMMENTS_COMMAND "comments"
#define COMMENT "comment"
#define HOTEL "hotel"
#define POST_COMMENTS_ARGUMENT_NUMBER 4
#define GET_COMMENTS_ARGUMENT_NUMBER 2
#define RATINGS_COMMAND "ratings"
#define LOCATION "location"
#define STAFF "staff"
#define CLEANLINESS "cleanliness"
#define FACILITIES "facilities"
#define VALUE_FOR_MONEY "value_for_money"
#define OVERALL_RATING "overall_rating"
#define POST_RATINGS_COMMAND_ARGUMENT_NUMBER 14
#define GET_RATINGS_COMMAND_ARGUMENT_NUMBER 2
#define FILTERS_COMMAND "filters"
#define CITY_FILTERS_ARGUMENT_NUMBER 2
#define CITY "city"
#define STAR_FILTERS_ARGUMENT_NUMBER 4
#define MIN_STAR "min_star"
#define MAX_STAR "max_star"
#define PRICE_FILTERS_ARGUMENT_NUMBER 4
#define MIN_PRICE "min_price"
#define MAX_PRICE "max_price"
#define RESERVE_COMMAND "reserves"
#define TYPE "type"
#define QUANTITY "quantity"
#define CHECK_IN "check_in"
#define CHECK_OUT "check_out"
#define POST_RESERVE_COMMAND_ARGUMENT_NUMBER 10
#define COUNT "count"
#define DELETE_RESERVE_COMMAND_ARGUMENT_NUMBER 2
#define RESERVE_FILTERS_ARGUMENT_NUMBER 8
#define FIRST_ELEMENT 0
#define STAR_FILTER_SIZE 8
#define PRICE_FILTER_SIZE 9
#define HOTEL_ID_ELEMENT 0
#define ROOM_TYPE_ELEMENT 1
#define QUANTITY_ELEMENT 0
#define CHECK_IN_ELEMENT 1
#define CHECK_OUT_ELEMENT 2
#define EMPTY_CHARACTER ""
#define SPACE_STRING " "
#define DEFAULT_PRICE_FILTER_COMMAND "default_price_filter"
#define DEFAULT_PRICE_FILTER_COMMAND_ARGUMENT_NUMBER 2
#define ACTIVE "active"
#define TRUE "true"
#define FALSE "false"
#define SORT_COMMAND "sort"
#define PROPERTY "property"
#define ORDER "order"
#define SORT_COMMAND_ARGUMENT_NUMBER 4
#define ASCENDING "ascending"
#define	DESCENDING "descending"
#define MANUAL_WEIGHT_COMMAND "manual_weights"
#define MANUAL_WEIGHT_ACTIVE_COMMAND_ARGUMENT_NUMBER 12
#define MANUAL_WEIGHT_INACTIVE_COMMAND_ARGUMENT_NUMBER 2
#define ESTIMATED_WEIGHTS_COMMAND "estimated_weights"

typedef struct UserLogin{
	std::string session_id;
	User* current_user;
}UserLogin;

class Utrip
{
public:
	Utrip(std::vector<Hotel> hotels_info);
	std::vector<Hotel*> get_all_hotels();
	Hotel get_hotel(std::string id);
	std::vector<Hotel*> get_filtered_hotels();
	void update_star_filter(int min, int max);
	double get_user_wallet(std::string email);
	void manage_star_filter(std::vector<std::string> args);
	void create_new_user(std::string email, std::string username, std::string password);
	void logout(std::string email);
	void login_new_user(std::string email, std::string password);
	void wallet_amount_current_user(double amount,std::string email);
	void check_user_login();
	
private:
	std::vector<Hotel> hotels_info;
	std::vector<User> users_info;
	std::vector<UserLogin> logged_user;
	Tools tools;
	ManageFilter managefilter;
	
};

#endif 