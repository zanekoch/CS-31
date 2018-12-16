#pragma once
#include <iostream>
#include <string>
#include <assert.h>
#include <exception>
#include "AppleProduct.h"
using namespace std;

namespace cs31
{
	class AppleStore;
}
class cs31::AppleStore
{
public:
	//constructor
	AppleStore();
	//functions that make the apple products declarations:
	AppleProduct buyWatch1(string color);
	AppleProduct buyWatch3(string color);
	AppleProduct buyiPad(string color, int gigabytes);
	AppleProduct buyiPadPro(string color, int gigabytes);
	AppleProduct buyiPhone8(string color, int gigabytes);
	AppleProduct buyiPhone8Plus(string color, int gigabytes);
	AppleProduct buyiPhoneX(string color, int gigabytes);

};