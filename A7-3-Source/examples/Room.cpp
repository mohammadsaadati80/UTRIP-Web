#include "Room.hpp"
using namespace std;

Room::Room(int _rate)
{
	rate = _rate;
}

void Room::initialization(string room_id, string room_type)
{
	this->room_id = room_id;
	this->room_type = room_type;
}

int Room::get_room_rate() { return rate; }

string Room::get_room_id() { return room_id; }

string Room::get_room_type() { return room_type; }