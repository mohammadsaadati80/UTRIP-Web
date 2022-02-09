#include "handlers.hpp"
using namespace std;
#define SERVER_PORT 8080

int main(int argc, char* argv[])
{
	Tools tools;
	try {
    Server server(SERVER_PORT);
   	Utrip utrip(tools.read_hotels_info(argv[HOTELS_FILE]));
    server.get("/home", new UserHomePageHandler(&utrip));
    server.get("/details", new HotelDetailsHandler(&utrip));
    server.post("/updateStarFilter", new UpdateStarFilter(&utrip));
    server.get("/starfilter", new StarFilterWeb(&utrip));
    server.get("/", new ShowPage("static/signupcss.html"));
    server.post("/signup", new SignUpPageHandler(&utrip));
    server.post("/logout", new LogOutHandler(&utrip));
    server.get("/loginpage", new ShowPage("static/logincss.html"));
    server.post("/login", new LoginHandler(&utrip));
    server.get("/userWallet", new UserWallet(&utrip));
    server.post("/updateUserWallet", new UpdateUserWallet(&utrip));
    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
	return 0;
}