#include <cassert>
#include "weather.h"
#include<iostream>

using namespace std;

int main() {
	GPS loc = GPS(46.3, 67.2);
	Weather irkutsk = Weather("Irkutsk", loc);
	cout << irkutsk<< endl;
}