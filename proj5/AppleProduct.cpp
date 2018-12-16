#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
#include "AppleProduct.h"
#include "AppleStore.h"
using namespace std;

namespace cs31
{
	class AppleProduct;
}
namespace cs31
{
	class AppleStore;
}

//default constructor definition
cs31::Apple
{
	AppleProduct::mKind = NOTSPECIFIED;
	AppleProduct::mVersion = "";
	AppleProduct::mColor = "";
	AppleProduct::mCost = 0.0;
}
//cosntructor defintion
cs31::AppleProduct::AppleProduct(cs31::AppleProduct::Kind kind, string version, string color, double cost)
{
	AppleProduct::mKind = kind;
	AppleProduct::mVersion = version;
	AppleProduct::mColor = color;
	AppleProduct::mCost = cost;
}
//get's for various variables of apple product
string cs31::AppleProduct::getVersion()
{
	return mVersion;
}
string cs31::AppleProduct::getColor()
{
	return mColor;
}
double cs31::AppleProduct::getCost()
{
	return mCost;
}
cs31::AppleProduct::Kind cs31::AppleProduct::getKind()
{
	return mKind;
}



