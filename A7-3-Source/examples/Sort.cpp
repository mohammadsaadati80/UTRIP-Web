#include "Sort.hpp"
using namespace std;

Sort::Sort()
{
	activation_status = false;
	ascending = true;
}

bool Sort::is_actived() { return activation_status; }

void Sort::update_sort(string propertyy, bool order)
{
	activation_status = true;
	sort_type = propertyy;
	ascending = order;
}

void Sort::deactive_sort()
{
	activation_status = false;
}

vector<Hotel*> Sort::my_sort(vector<Hotel*> filtered_hotel)
{
	if (activation_status == false)
		sort(filtered_hotel.begin(), filtered_hotel.end(), sort_id_asc);
	else
		filtered_hotel = sort_based_on_property_type(filtered_hotel);
	return filtered_hotel;
}

vector<Hotel*> Sort::sort_based_on_property_type(vector<Hotel*> filtered_hotel)
{
	if (sort_type == ID)
		filtered_hotel = sort_based_on_id(filtered_hotel);
	else if (sort_type == STAR_RATING)
		filtered_hotel = sort_based_on_star(filtered_hotel);
	return filtered_hotel;
}

vector<Hotel*> Sort::sort_based_on_id(vector<Hotel*> filtered_hotel)
{
	if(ascending)
		sort(filtered_hotel.begin(), filtered_hotel.end(), sort_id_asc);
	else
		sort(filtered_hotel.begin(), filtered_hotel.end(), sort_id_des);
	return filtered_hotel;
}

bool Sort::sort_id_asc(Hotel* first_hotel, Hotel* second_hotel)
{
	return (first_hotel->get_hotel_unique_id() < second_hotel->get_hotel_unique_id());
}

bool Sort::sort_id_des(Hotel* first_hotel, Hotel* second_hotel)
{
	return (first_hotel->get_hotel_unique_id() > second_hotel->get_hotel_unique_id());
}

vector<Hotel*> Sort::sort_based_on_star(std::vector<Hotel*> filtered_hotel)
{
	if (ascending)
		sort(filtered_hotel.begin(), filtered_hotel.end(), sort_star_id_asc);
	else
		sort(filtered_hotel.begin(), filtered_hotel.end(), sort_star_id_des);
	return filtered_hotel;
}

bool Sort::sort_star_id_asc(Hotel* first_hotel, Hotel* second_hotel)
{
	if (first_hotel->get_hotel_star_rating() == second_hotel->get_hotel_star_rating())
		return sort_id_asc(first_hotel, second_hotel);
	else
		return (first_hotel->get_hotel_star_rating() < second_hotel->get_hotel_star_rating());
}

bool Sort::sort_star_id_des(Hotel* first_hotel, Hotel* second_hotel)
{
	if (first_hotel->get_hotel_star_rating() == second_hotel->get_hotel_star_rating())
		return sort_id_asc(first_hotel, second_hotel);
	else
		return (first_hotel->get_hotel_star_rating() > second_hotel->get_hotel_star_rating());
}

void Sort::update_user(User* current_user)
{
	this->current_user = current_user;
}