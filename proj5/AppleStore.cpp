
#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
#include "AppleProduct.h"
#include "AppleStore.h"
using namespace std;

namespace cs31
{
	class AppleStore;
}


//constructor defintion
cs31::AppleStore::AppleStore() {}
//functions that make the apple products definitions:
cs31::AppleProduct cs31::AppleStore::buyWatch1(string color)
{
	cs31::AppleProduct watch1(cs31::AppleProduct::Kind::WATCH, "1", color, 249.00);
	return (watch1);
}
cs31::AppleProduct cs31::AppleStore::buyWatch3(string color)
{
	cs31::AppleProduct watch3(cs31::AppleProduct::Kind::WATCH, "3", color, 329.00);
	return (watch3);
}
cs31::AppleProduct cs31::AppleStore::buyiPad(string color, int gigabytes)
{
	if (gigabytes == 32)
	{
		cs31::AppleProduct iPad(cs31::AppleProduct::Kind::IPAD, "", color, 329.00);
		return (iPad);
	}
	else if (gigabytes == 128)
	{
		cs31::AppleProduct iPad(cs31::AppleProduct::Kind::IPAD, "", color, 429.00);
		return (iPad);
	}
	else
	{
		throw logic_error("bad");
	}

}
cs31::AppleProduct cs31::AppleStore::buyiPadPro(string color, int gigabytes)
{
	if (gigabytes == 64)
	{
		cs31::AppleProduct iPadPro(cs31::AppleProduct::Kind::IPAD, "Pro", color, 649.00);
		return (iPadPro);
	}
	else if (gigabytes == 256)
	{
		cs31::AppleProduct iPadPro(cs31::AppleProduct::Kind::IPAD, "Pro", color, 799.00);
		return (iPadPro);
	}
	else if (gigabytes == 512)
	{
		cs31::AppleProduct iPadPro(cs31::AppleProduct::Kind::IPAD, "Pro", color, 999.00);
		return (iPadPro);
	}
	else
	{
		throw logic_error("bad");
	}

}
cs31::AppleProduct cs31::AppleStore::buyiPhone8(string color, int gigabytes)
{
	if (gigabytes == 64)
	{
		cs31::AppleProduct iPhone8(cs31::AppleProduct::Kind::IPHONE, "8", color, 699.00);
		return (iPhone8);
	}
	else if (gigabytes == 256)
	{
		cs31::AppleProduct iPhone8(cs31::AppleProduct::Kind::IPHONE, "8", color, 849.00);
		return (iPhone8);
	}
	else
	{
		throw logic_error("bad");
	}

}
cs31::AppleProduct cs31::AppleStore::buyiPhone8Plus(string color, int gigabytes)
{
	if (gigabytes == 64)
	{
		cs31::AppleProduct iPhone8Plus(cs31::AppleProduct::Kind::IPHONE, "8Plus", color, 799.00);
		return (iPhone8Plus);
	}
	else if (gigabytes == 256)
	{
		cs31::AppleProduct iPhone8Plus(cs31::AppleProduct::Kind::IPHONE, "8Plus", color, 949.00);
		return (iPhone8Plus);
	}
	else
	{
		throw logic_error("bad");
	}
}
cs31::AppleProduct cs31::AppleStore::buyiPhoneX(string color, int gigabytes)
{
	if (gigabytes == 64)
	{
		cs31::AppleProduct iPhoneX(cs31::AppleProduct::Kind::IPHONE, "X", color, 999.00);
		return (iPhoneX);
	}
	else if (gigabytes == 256)
	{
		cs31::AppleProduct iPhoneX(cs31::AppleProduct::Kind::IPHONE, "X", color, 1149.00);
		return (iPhoneX);
	}
	else
	{
		throw logic_error("bad");
	}
}