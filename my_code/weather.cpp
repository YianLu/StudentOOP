#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

/*
 * A constructor for weather class.
 * */
Weather::Weather(std::string nm, GPS loc) :
	station_nm(nm), my_loc(loc) {

}


string Weather::get_name() const {

	return station_nm;
}

int Weather::get_rating()const {
	return rating;
}

void Weather::set_rating(int new_rating) {
	rating = new_rating;
}

void Weather::add_reading(WReading wr) {
	wreadings.push_back(wr);
}

Date::Date(int d, int m, int y): day(d), month(m), year(y){}
ostream& operator <<(ostream& os, const Date& date) {
	os << "the date is " << date.day << date.month << date.year << endl;
	return os;
}

ostream& operator <<(ostream& os, const WReading& wr) {
	os << "date is" << wr.date;
	os << "temperature is " << wr.temperature << "humidity is " 
		<< wr.humidity << "windspeed is " << wr.windspeed << endl;
	return os;
}

ostream& operator <<(ostream& os, const GPS& gps) {
	os << "the latitude is" << gps.latitude << "the longtitude is " << gps.longitude << endl;
	return os;
}

ostream& operator <<(ostream& os, const Weather& w) {
	os << w.get_name() << ":rating " << w.get_rating() << "; " << w.my_loc << endl;
	for (WReading wr : w.wreadings) {
		os << "     " << wr << endl;
	}

	return os;
}