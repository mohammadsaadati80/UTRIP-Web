#ifndef  __SORT_H__
#define __SORT_H__
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <functional>
#include "Hotel.hpp"
#include "User.hpp"
#include <map>

#define STAR_RATING "star_rating"
#define ID "id"

class Sort
{
public:
	Sort();
	bool is_actived();
	void update_sort(std::string property, bool order);
	void deactive_sort();
	std::vector<Hotel*> my_sort(std::vector<Hotel*> filtered_hotel);
	std::vector<Hotel*> sort_based_on_property_type(std::vector<Hotel*> filtered_hotel);
	std::vector<Hotel*> sort_based_on_id(std::vector<Hotel*> filtered_hotel);
	static bool sort_id_asc(Hotel* first_hotel, Hotel* second_hotel);
	static bool sort_id_des(Hotel* first_hotel, Hotel* second_hotel);
	std::vector<Hotel*> sort_based_on_star(std::vector<Hotel*> filtered_hotel);
	static bool sort_star_id_asc(Hotel* first_hotel, Hotel* second_hotel);
	static bool sort_star_id_des(Hotel* first_hotel, Hotel* second_hotel);
	void update_user(User* current_user);
	
private:
	bool activation_status;
	bool ascending;
	std::string sort_type;
	User* current_user;

};

#endif 