#include "ManageFilter.hpp"
using namespace std;

void ManageFilter::add_all_hotels(vector<Hotel> &hotel_info)
{
	for (int current = 0; current < hotel_info.size(); current++)
		all_hotel_info.push_back(&hotel_info[current]);
	star_filter = new StarFilter;
	filters.push_back(star_filter);
}

void ManageFilter::add_new_star_filter(int min_star, int max_star)
{
	if (min_star > LAST_VALID_MIN_STAR || min_star < FIRST_VALID_MIN_STAR || max_star > LAST_VALID_MAX_STAR || max_star < FIRST_VALID_MAX_STAR || max_star < min_star)
		throw BadRequestException();
	star_filter->add_new_star_filter(min_star, max_star);
	filters[STARFILTER] = star_filter;
}

void ManageFilter::delete_all_filters()
{
	filtered_hotel_info = all_hotel_info;
	for (int current = 0;current < filters.size() - 1;current++)
		filters[current]->deactive_fliter();
}

void ManageFilter::update_sort(string propertyy, bool order)
{
	my_sort.update_sort(propertyy, order);
}

void ManageFilter::delete_sort()
{
	my_sort.deactive_sort();
}

void ManageFilter::update_sort_user(User* current_user)
{
	my_sort.update_user(current_user);
}

vector<Hotel*> ManageFilter::get_filtered_hotel()
{
	filtered_hotel_info = all_hotel_info;
	for (int current = 0;current < filters.size();current++)
		if (filters[current]->get_filter_status() == true)
			filtered_hotel_info = filters[current]->apply_filter(filtered_hotel_info);
	return filtered_hotel_info;
}