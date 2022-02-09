#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>
#include "Utrip.hpp"

class UserHomePageHandler : public RequestHandler {
public:
	UserHomePageHandler(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class HotelDetailsHandler : public RequestHandler {
public:
	HotelDetailsHandler(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class UpdateStarFilter : public RequestHandler {
public:
	UpdateStarFilter(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class StarFilterWeb : public RequestHandler {
public:
	StarFilterWeb(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class SignUpPageHandler : public RequestHandler {
public:
  	SignUpPageHandler(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class LogOutHandler : public RequestHandler {
public:
  	LogOutHandler(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class LoginHandler : public RequestHandler {
public:
  	LoginHandler(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class UpdateUserWallet : public RequestHandler {
public:
	UpdateUserWallet(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class UserWallet : public RequestHandler {
public:
	UserWallet(Utrip* all_info) : utrip(all_info) {}
	Response *callback(Request *);
private:
	Utrip* utrip;
};

class HTMLTag {
public:
	std::string user_not_login_html_tag(std::string exception_massage);
	std::string holtels_info_html_tag(std::vector<Hotel*> filtered_hotels);
	std::string logout_button_html_tag();
	std::string home_button_html_tag();
	std::string continue_button_html_tag(std::string exception_massage, std::string action);
};

#endif