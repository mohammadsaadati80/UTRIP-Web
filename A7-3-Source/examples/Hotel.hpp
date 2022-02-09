#ifndef __HOTEL_H__
#define __HOTEL_H__

#include "Exceptions.hpp"
#include "DeluxeRoom.hpp"
#include "LuxuryRoom.hpp"
#include "PremiumRoom.hpp"
#include "StandardRoom.hpp"
#include <iomanip>
#include <numeric>

#define ROUND_UP_TO_TWO_DECIMAL_PLACES 2
#define SPACE ' '
#define COLON ':'
#define	STAR_TEXT "star: "
#define OVERVIEW_TEXT "overview: "
#define AMENITIES_TEXT "amenities: "
#define	CITY_TEXT "city: "
#define	LATITUDE_TEXT "latitude: "
#define LONGITUDE_TEXT "longitude: "
#define ROOM_SHOW_TEXT "#rooms: "
#define PRICE_TEXT "price: "
#define LOCATION_TEXT "location: "
#define CLEANLINESS_TEXT "cleanliness: "
#define STAFF_TEXT "staff: "
#define FACILITIES_TEXT	"facilities: "
#define VALUE_FOR_MONEY_TEXT "value_for_money: "
#define OVERALL_RATING_TEXT "overall_rating: "
#define UNIQUE_ID_ELEMENT 0
#define PROPERTY_NAME_ELEMENT 1
#define OVERVIEW_ELEMENT 2
#define CITY_ELEMENT 3
#define IMAGE_URL_ELEMENT 4
#define LATITUDE_ELEMENT 0
#define LONGITTUDE_ELEMENT 1
#define FIRST_RATE 1
#define SPECIAL_SEPARATOR '|'

class Hotel
{
public:
	Hotel(std::vector<std::string> hotel_string, int hotel_star, std::vector<std::string> hotel_facilities, std::vector<double> hotel_double, std::vector<std::vector<Room*> > hotel_rooms, std::vector<int> room_price);
	void show_summary_of_hotel_info();
	int calculate_hotel_total_num_of_rooms();
	std::string get_hotel_unique_id();
	std::string get_hotel_city();
	int get_hotel_star_rating();
	int find_room_type(std::string room_type);
	std::string get_hotel_property_name();
	int get_hotel_room_price(int room_type);
	std::string get_hotel_image_address();
	std::string get_hotel_overview();
	std::vector<std::string> get_hotel_amenities();
	int get_room_number(int room_type);
	std::string get_room_type(int room_type);


private:
	std::string hotel_unique_id;
	std::string hotel_property_name;
	int hotel_star_rating;
	std::string hotel_overview;
	std::vector<std::string> hotel_property_amenities;
	std::string hotel_city;
	double hotel_latitude;
	double hotel_longitude;
	std::string hotel_image_url;
	std::vector<std::vector<Room*> > hotel_rooms_info;
	std::vector<int> hotel_room_price;
	std::vector<double> manual_weights;
	std::string current_user_name;

};

#endif 