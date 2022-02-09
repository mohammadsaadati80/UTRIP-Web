CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) utrip.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: examples/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/Utrip.hpp
	$(CC) $(CF) -c examples/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/main.o: examples/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp examples/Utrip.hpp
	$(CC) $(CF) -c examples/main.cpp -o $(BUILD_DIR)/main.o


$(BUILD_DIR)/Tools.o: examples/Tools.cpp examples/Tools.hpp examples/Hotel.hpp examples/Room.hpp examples/DeluxeRoom.hpp examples/LuxuryRoom.hpp examples/PremiumRoom.hpp examples/StandardRoom.hpp
	$(CC) -c examples/Tools.cpp -o $(BUILD_DIR)/Tools.o

$(BUILD_DIR)/Exceptions.o: examples/Exceptions.cpp examples/Exceptions.hpp
	$(CC) $(CF) -c examples/Exceptions.cpp -o $(BUILD_DIR)/Exceptions.o

$(BUILD_DIR)/Utrip.o: examples/Utrip.cpp examples/Utrip.hpp examples/Exceptions.hpp examples/User.hpp examples/ManageFilter.hpp examples/Tools.hpp examples/Hotel.hpp examples/Room.hpp examples/DeluxeRoom.hpp examples/LuxuryRoom.hpp examples/PremiumRoom.hpp examples/StandardRoom.hpp
	$(CC) $(CF) -c examples/Utrip.cpp -o $(BUILD_DIR)/Utrip.o

$(BUILD_DIR)/Hotel.o: examples/Hotel.cpp examples/Hotel.hpp examples/Exceptions.hpp examples/DeluxeRoom.hpp examples/LuxuryRoom.hpp examples/PremiumRoom.hpp examples/StandardRoom.hpp
	$(CC) $(CF) -c examples/Hotel.cpp -o $(BUILD_DIR)/Hotel.o

$(BUILD_DIR)/User.o: examples/User.cpp examples/User.hpp examples/Exceptions.hpp examples/Room.hpp examples/DeluxeRoom.hpp examples/LuxuryRoom.hpp examples/PremiumRoom.hpp examples/StandardRoom.hpp
	$(CC) $(CF) -c examples/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Room.o: examples/Room.cpp examples/Room.hpp
	$(CC) $(CF) -c examples/Room.cpp -o $(BUILD_DIR)/Room.o

$(BUILD_DIR)/DeluxeRoom.o: examples/DeluxeRoom.cpp examples/DeluxeRoom.hpp examples/Room.hpp
	$(CC) $(CF) -c examples/DeluxeRoom.cpp -o $(BUILD_DIR)/DeluxeRoom.o

$(BUILD_DIR)/LuxuryRoom.o: examples/LuxuryRoom.cpp examples/LuxuryRoom.hpp examples/Room.hpp
	$(CC) $(CF) -c examples/LuxuryRoom.cpp -o $(BUILD_DIR)/LuxuryRoom.o

$(BUILD_DIR)/PremiumRoom.o: examples/PremiumRoom.cpp examples/PremiumRoom.hpp examples/Room.hpp
	$(CC) $(CF) -c examples/PremiumRoom.cpp -o $(BUILD_DIR)/PremiumRoom.o

$(BUILD_DIR)/StandardRoom.o: examples/StandardRoom.cpp examples/StandardRoom.hpp examples/Room.hpp
	$(CC) $(CF) -c examples/StandardRoom.cpp -o $(BUILD_DIR)/StandardRoom.o

$(BUILD_DIR)/ManageFilter.o: examples/ManageFilter.cpp examples/ManageFilter.hpp examples/MainFilter.hpp examples/StarFilter.hpp examples/Sort.hpp
	$(CC) $(CF) -c examples/ManageFilter.cpp -o $(BUILD_DIR)/ManageFilter.o

$(BUILD_DIR)/MainFilter.o: examples/MainFilter.cpp examples/MainFilter.hpp examples/Hotel.hpp
	$(CC) $(CF) -c examples/MainFilter.cpp -o $(BUILD_DIR)/MainFilter.o

$(BUILD_DIR)/StarFilter.o: examples/StarFilter.cpp examples/StarFilter.hpp examples/MainFilter.hpp
	$(CC) $(CF) -c examples/StarFilter.cpp -o $(BUILD_DIR)/StarFilter.o
	
$(BUILD_DIR)/Sort.o: examples/Sort.cpp examples/Sort.hpp examples/Hotel.hpp examples/User.hpp
	$(CC) $(CF) -c examples/Sort.cpp -o $(BUILD_DIR)/Sort.o



utrip.out: $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Tools.o $(BUILD_DIR)/Exceptions.o $(BUILD_DIR)/Utrip.o $(BUILD_DIR)/Hotel.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Room.o $(BUILD_DIR)/DeluxeRoom.o $(BUILD_DIR)/LuxuryRoom.o $(BUILD_DIR)/PremiumRoom.o $(BUILD_DIR)/StandardRoom.o $(BUILD_DIR)/ManageFilter.o $(BUILD_DIR)/MainFilter.o $(BUILD_DIR)/StarFilter.o $(BUILD_DIR)/Sort.o
	$(CC) $(CF) $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/Tools.o $(BUILD_DIR)/Exceptions.o $(BUILD_DIR)/Utrip.o $(BUILD_DIR)/Hotel.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Room.o $(BUILD_DIR)/DeluxeRoom.o $(BUILD_DIR)/LuxuryRoom.o $(BUILD_DIR)/PremiumRoom.o $(BUILD_DIR)/StandardRoom.o $(BUILD_DIR)/ManageFilter.o $(BUILD_DIR)/MainFilter.o $(BUILD_DIR)/StarFilter.o $(BUILD_DIR)/Sort.o -o utrip.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
