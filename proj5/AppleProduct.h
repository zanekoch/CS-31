#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
using namespace std;

namespace cs31
{
	class AppleProduct;
}

class cs31::AppleProduct
{
	//private variables
	string mVersion;
	string mColor;
	double mCost;
public:
	//kind variables must be public because they are referenced outside
	enum Kind { NOTSPECIFIED, IPHONE, IPAD, WATCH };
	Kind mKind;
	//get's for various variables
	string getVersion();
	string getColor();
	double getCost();
	AppleProduct::Kind getKind();
	//default constructor
	AppleProduct();
	//non default constructor
	AppleProduct(cs31::AppleProduct::Kind, string, string, double);
};
