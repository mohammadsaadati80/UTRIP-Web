#ifndef __MANAGE_FILTER_H__
#define __MANAGE_FILTER_H__

#include "MainFilter.hpp"
#include "StarFilter.hpp"
#include "Sort.hpp"

#define STARFILTER 0
#define VALID_PRICE 0
#define FIRST_VALID_MIN_STAR 1  
#define LAST_VALID_MIN_STAR 5
#define FIRST_VALID_MAX_STAR 1  
#define LAST_VALID_MAX_STAR 5

class ManageFilter
{
public:
	void add_all_hotels(std::vector<Hotel> &hotel_info);
	void add_new_star_filter(int min_star, int max_star);
	void delete_all_filters();
	void update_sort(std::string property, bool order);
	void delete_sort();
	void update_sort_user(User* current_user);
	std::vector<Hotel*> get_filtered_hotel();

private:
	std::vector<Hotel*> all_hotel_info;
	std::vector<Hotel*> filtered_hotel_info;
	std::vector<MainFilter*> filters;
	StarFilter* star_filter;
	Sort my_sort;

};

#endif 