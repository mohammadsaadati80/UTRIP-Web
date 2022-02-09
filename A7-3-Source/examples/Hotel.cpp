#include "Hotel.hpp"
using namespace std;

Hotel::Hotel(vector<string> hotel_string, int hotel_star, std::vector<std::string> hotel_facilities, vector<double> hotel_double, vector<vector<Room*> > hotel_rooms, vector<int> room_price)
{
	hotel_unique_id = hotel_string[UNIQUE_ID_ELEMENT];
	hotel_property_name = hotel_string[PROPERTY_NAME_ELEMENT];
	hotel_star_rating = hotel_star;
	hotel_overview = hotel_string[OVERVIEW_ELEMENT];
	hotel_property_amenities = hotel_facilities;
	hotel_city = hotel_string[CITY_ELEMENT];
	hotel_latitude = hotel_double[LATITUDE_ELEMENT];
	hotel_longitude = hotel_double[LONGITTUDE_ELEMENT];
	hotel_image_url = hotel_string[IMAGE_URL_ELEMENT];
	hotel_rooms_info = hotel_rooms;
	hotel_room_price = room_price;
}

int Hotel::calculate_hotel_total_num_of_rooms()
{
	return accumulate(hotel_rooms_info.begin(), hotel_rooms_info.end(), 0, [](int total, vector<Room*> current_rooms) {return total + current_rooms.size();});
}

string Hotel::get_hotel_unique_id() { return hotel_unique_id; }

string Hotel::get_hotel_city() { return hotel_city; }

int Hotel::get_hotel_star_rating() { return hotel_star_rating; }

int Hotel::find_room_type(string room_type)
{
	if (room_type == STANDARD_ROOM_TYPE)
		return STANDARD_ROOM;
	if (room_type == DELUXE_ROOM_TYPE)
		return DELUXE_ROOM;
	if (room_type == LUXURY_ROOM_TYPE)
		return LUXURY_ROOM;
	if (room_type == PREMIUM_ROOM_TYPE)
		return PREMIUM_ROOM;
	return -1;
}

string Hotel::get_hotel_property_name() { return hotel_property_name; }

int Hotel::get_hotel_room_price(int room_type)
{
	if (hotel_room_price[room_type] > 0)
		return hotel_room_price[room_type];
	else
		return 0;
}

string Hotel::get_hotel_image_address() {return hotel_image_url;}

string Hotel::get_hotel_overview() {return hotel_overview;}

vector<std::string> Hotel::get_hotel_amenities(){return hotel_property_amenities;}

int Hotel::get_room_number(int room_type){return hotel_rooms_info[room_type].size();}

string Hotel::get_room_type(int room_type)
{
	if (room_type == STANDARD_ROOM)
		return STANDARD_ROOM_TYPE;
	if (room_type == DELUXE_ROOM)
		return DELUXE_ROOM_TYPE;
	if (room_type == LUXURY_ROOM)
		return LUXURY_ROOM_TYPE;
	if (room_type == PREMIUM_ROOM)
		return PREMIUM_ROOM_TYPE;
}