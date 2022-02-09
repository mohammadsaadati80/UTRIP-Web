#include "handlers.hpp"
using namespace std;

Response *UserHomePageHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  HTMLTag html_tag;
  try
  {
    utrip->check_user_login();
  }
  catch(exception& e)
  {
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  string body;
  body += "<html>";
  body += "<body>";
  body += "    <head><title>User Home Page</title></head>";
  body += html_tag.logout_button_html_tag();
  body += "  <form action='updateStarFilter' method='POST'>";
  body += "    Min Star: <input type='text' name='min' value='" + to_string(1) + "'/><br/>";
  body += "    Max Star: <input type='text' name='max' value='" + to_string(5) + "'/><br/>";
  body += "    <input type='submit' value='Apply'/>";
  body += "  </form>";
  body += "    <p>";
  body += "  <form action='/userWallet' method='GET'>";
  body += "    <input type='submit' value='USER WALLET'/>";
  body += "    </p>";
  body += "  </form>";
  body += "</body>";
  body += "</html>";
  body += "<html>";
  body += html_tag.holtels_info_html_tag(utrip->get_all_hotels());
  res->setBody(body);
  return res;
}

Response *HotelDetailsHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  Hotel hotel = utrip->get_hotel(req->getQueryParam("id"));
  HTMLTag html_tag;
  ostringstream body;
  try
  {
    utrip->check_user_login();
  }
  catch(exception& e)
  {
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  body
    << "<html>" << endl
    << "<head><title>Details</title></head>" << endl
    << "<body>" << endl;
  body << html_tag.logout_button_html_tag();
  body << html_tag.home_button_html_tag();
  body
    << "<p>" << "<img src='" << hotel.get_hotel_image_address() << "'>" << "</p>"<< endl
    << "<p>" << "&#127976" << " " <<hotel.get_hotel_property_name() << "</p>"<< endl
    << "<p>" << "&#9432" << " " <<hotel.get_hotel_overview() << "</p>" << endl
    << "<p>" << "&#8505" << " Amenities: " << endl;
  vector<string> amenities = hotel.get_hotel_amenities();
  for(int current =0; current < amenities.size(); current++)
    body << "<p>" <<  "   " << amenities[current] << "</p>" << endl;
  body << "<p>";
  for(int current = 0; current < hotel.get_hotel_star_rating(); current++)
    body << "&#11088";
  body << "</p>" << endl;
  body
    << "<p>" << "&#128205" << "City: " <<hotel.get_hotel_city() << "</p>"<< endl
    << "  </form>" << endl
    << "            <table border=1>" << endl
    << "                <tr>" << endl
    << "                    <th>Room type</th>" << endl
    << "                    <th>Price</th>" << endl
    << "                    <th>Count</th>" << endl
    << "                </tr>" << endl;
    for (int current = 0; current < NUMBER_OF_ROOM_TYPES; current++) 
    {
      body
        << "                    <tr>" << endl
        << "                        <td>" << hotel.get_room_type(current) << "</td>" << endl
        << "                        <td>" << hotel.get_hotel_room_price(current) << "</td>" << endl
        << "                        <td>" << hotel.get_room_number(current) << "</td>" << endl
        << "                    </tr>" << endl;
    }
  body
    << "            </table>" << endl
    << "</body>" << endl
    << "</html>" << endl;
  res->setBody(body.str());
  return res;
}

Response *UpdateStarFilter::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  HTMLTag html_tag;
  try
  {
    utrip->check_user_login();
    vector<string> star;
    star.push_back(MIN_STAR);
    star.push_back(req->getBodyParam("min"));
    star.push_back(MAX_STAR);
    star.push_back(req->getBodyParam("max"));
    utrip->manage_star_filter(star);
  }
  catch(PermissionDeniedException& e)
  {
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  catch(exception& e)
  {
    res->setBody(html_tag.continue_button_html_tag(e.what(), "  <form action='home' method='GET'>"));
    return res;
  }
  return Response::redirect("/starfilter");
}

Response *StarFilterWeb::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  HTMLTag html_tag;
  vector<Hotel*> filtered_hotels = utrip->get_filtered_hotels();
  try
  {
    utrip->check_user_login();
  }
  catch(exception& e)
  {
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  string body;
  body += "<html>";
  body += "<head><title>Star Filter</title></head>";
  body += html_tag.logout_button_html_tag();
  body += "    </head>";
  body += html_tag.home_button_html_tag();
  body += html_tag.holtels_info_html_tag(filtered_hotels);
  res->setBody(body);
  return res;
}

Response *SignUpPageHandler::callback(Request *req) {
  Response *res = new Response;
  try
  {
    string username = req->getBodyParam("username");
    string password = req->getBodyParam("password");
    string re_password = req->getBodyParam("re_password");
    string email = req->getBodyParam("email");
    if(password == re_password)
      utrip->create_new_user(email, username, password);
    else
      throw PasswordNotMatchException();
    res->setSessionId(req->getBodyParam("email"));
  }
  catch(const std::exception& e)
  {
    res->setHeader("Content-Type", "text/html");
    HTMLTag html_tag;
    res->setBody(html_tag.continue_button_html_tag(e.what(), "  <form action='/' method='GET'>"));
    return res;
  }
  res = Response::redirect("/home");
  res->setSessionId(req->getBodyParam("email"));
  return res;
}

Response *LogOutHandler::callback(Request *req) {\
  Response *res = new Response;
  try
  {
    utrip->logout(req->getSessionId());
  }
  catch(exception& e)
  {
    res->setHeader("Content-Type", "text/html");
    HTMLTag html_tag;
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  res = Response::redirect("/loginpage");
  return res;
}

Response *LoginHandler::callback(Request *req) {
  try
  {
    string email = req->getBodyParam("email");
    string password = req->getBodyParam("password");
    utrip->login_new_user(email, password);
  }
  catch(exception& e)
  {
    Response *res = new Response;
    res->setHeader("Content-Type", "text/html");
    HTMLTag html_tag;
    res->setBody(html_tag.continue_button_html_tag(e.what(), "  <form action='/loginpage' method='GET'>"));
    return res;
  }
  Response *res = Response::redirect("/home");
  res->setSessionId(req->getBodyParam("email"));
  return res;
}

Response *UserWallet::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  HTMLTag html_tag;
  string body;
  try
  {
    utrip->check_user_login();
  }
  catch(exception& e)
  {
    res->setHeader("Content-Type", "text/html");
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  body +=
  body += "<html>";
  body += "<body>";
  body += "    <head><title>User Wallet</title></head>";
  body += html_tag.logout_button_html_tag();
  body += html_tag.home_button_html_tag();
  body += "  <form action='updateUserWallet' method='POST'>";
  body += "    New Wallet: <input type='text' name='wallet' value='" + to_string(0) + "'/><br/>";
  body += "    <input type='submit' value='Apply'/>";
  body += "  </form>";
  body += "</body>";
  body += "</html>";
  body += "    <p>";
  body += "      Wallet: " + to_string(utrip->get_user_wallet(req->getSessionId()));
  body += "    </p>";
  body += "    </body>";
  body += "</html>";
  res->setBody(body);
  return res;
}

Response *UpdateUserWallet::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  HTMLTag html_tag;
  try
  {
    utrip->check_user_login();
    utrip->wallet_amount_current_user(stod(req->getBodyParam("wallet")), req->getSessionId());
  }
  catch(PermissionDeniedException& e)
  {
    res->setBody(html_tag.user_not_login_html_tag(e.what()));
    return res;
  }
  catch(exception& e)
  {
    res->setBody(html_tag.continue_button_html_tag(e.what(), "  <form action='/userWallet' method='GET'>"));
    return res;
  }
  res = Response::redirect("/userWallet");
  return res;
}

string HTMLTag::user_not_login_html_tag(string exception_massage)
{
  string body;
  body += "<!DOCTYPE html>";
  body += "<html>";
  body += "<body>";
  body += "    <p>";
  body += exception_massage;
  body += "    </p>";
  body += "    <p>";
  body += "  <form action='/' method='GET'>";
  body += "    <input type='submit' value='Sign Up'/>";
  body += "  </form>";
  body += "    </p>";
  body += "    <p>";
  body += "  <form action='loginpage' method='GET'>";
  body += "    <input type='submit' value='Login'/>";
  body += "  </form>";
  body += "    </p>";
  body += "</body>";
  body += "</html>";
  return body;
}

string HTMLTag::holtels_info_html_tag(vector<Hotel*> filtered_hotels)
{
  string body;
  body += "    <body>";
  body += "            <table border=1>";
  body += "                <tr>";
  body += "                    <th>Image</th>";
  body += "                    <th>Property Name</th>";
  body += "                    <th>Star Rating</th>";
  body += "                    <th>City</th>";
  body += "                    <th>Details</th>";
  body += "                </tr>";
  for (int current = 0; current < filtered_hotels.size(); current++)
  {
    body += "                    <tr>";
    body += "                        <td><img src=" + filtered_hotels[current]->get_hotel_image_address() + "'></td>" ;
    body += "                        <td>" + filtered_hotels[current]->get_hotel_property_name() + "</td>";
    body += "                        <td>";
    for(int current_star = 0; current_star < filtered_hotels[current]->get_hotel_star_rating(); current_star++)
      body += "&#11088";
    body += "</td>";
    body += "                        <td>" + filtered_hotels[current]->get_hotel_city() + "</td>";
    body += "                        <td><a href='details?id=" + filtered_hotels[current]->get_hotel_unique_id() + "'>Details</a></td>";
    body += "                    </tr>" ;
  }
  body += "            </table>";
  body += "    <p>";
  body += "    </p>";
  body += "    </body>";
  body += "</html>";
  return body;
}

string HTMLTag::logout_button_html_tag()
{
  string body;
  body += "    <p>";
  body += "  <form action='/logout' method='POST'>";
  body += "    <input type='submit' value='LOG OUT'/>";
  body += "    </p>";
  body += "  </form>";
  return body;
}

string HTMLTag::home_button_html_tag()
{
  string body;
  body += "  <form action='home' method='GET'>";
  body += "    <input type='submit' value='HOME'/>";
  body += "  </form>";
  return body;
}

string HTMLTag::continue_button_html_tag(string exception_massage, string action)
{
  string body;
  body += "<html>";
  body += "<body>";
  body += "    <p>";
  body += exception_massage;
  body += "    </p>";
  body += "    <p>";
  body += action;
  body += "    <input type='submit' value='Continue'/>";
  body += "    </p>";
  body += "  </form>";
  body += "</body>";
  body += "</html>";
  return body;
}