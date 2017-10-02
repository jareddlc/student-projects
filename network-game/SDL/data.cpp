#include "data.h"
#include <string>

Data::Data(){}

void Data::setData(int x, int y)
{
	string temp = to_string(x);
	temp += ",";
	temp += to_string(y);
	localPlayer = temp;
	/*
			string test = to_string(coordinate.x);
		OutputDebugStringA(test.c_str());
		OutputDebugStringA("\n");
		*/
}

void Data::getData()
{
}

string Data::getLocal()
{
	return localPlayer;
}