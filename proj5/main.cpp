
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



int main()
{
	cs31::AppleStore z;
	cs31::AppleProduct watch1 = z.eatadick("blue");
	assert(watch1.getVersion() == "1");
	assert(watch1.getCost() == 249.00);
	assert(watch1.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(watch1.getColor() == "blue");

	cs31::AppleStore a;
	cs31::AppleProduct watch3 = a.buyWatch3("blue");
	assert(watch3.getVersion() == "3");
	assert(watch3.getCost() == 329.00);
	assert(watch3.getKind() == cs31::AppleProduct::Kind::WATCH);
	assert(watch3.getColor() == "blue");

	cs31::AppleStore b;
	cs31::AppleProduct ipad = b.buyiPad("blue", 32);
	assert(ipad.getVersion() == "");
	assert(ipad.getCost() == 329.00);
	assert(ipad.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipad.getColor() == "blue");

	cs31::AppleStore c;
	cs31::AppleProduct ipadpro = b.buyiPadPro("blue", 64);
	assert(ipadpro.getVersion() == "Pro");
	assert(ipadpro.getCost() == 649.00);
	assert(ipadpro.getKind() == cs31::AppleProduct::Kind::IPAD);
	assert(ipadpro.getColor() == "blue");

	cs31::AppleStore d;
	cs31::AppleProduct iphone8 = b.buyiPhone8("blue", 64);
	assert(iphone8.getVersion() == "8");
	assert(iphone8.getCost() == 699.00);
	assert(iphone8.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iphone8.getColor() == "blue");

	cs31::AppleStore e;
	cs31::AppleProduct iPhone8Plus = b.buyiPhone8Plus("blue", 64);
	assert(iPhone8Plus.getVersion() == "8Plus");
	assert(iPhone8Plus.getCost() == 799.00);
	assert(iPhone8Plus.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhone8Plus.getColor() == "blue");

	cs31::AppleStore f;
	cs31::AppleProduct iPhoneX = b.buyiPhoneX("blue", 64);
	assert(iPhoneX.getVersion() == "X");
	assert(iPhoneX.getCost() == (999.00));
	assert(iPhoneX.getKind() == cs31::AppleProduct::Kind::IPHONE);
	assert(iPhoneX.getColor() == "blue");

	cerr << "asserts worked..." << endl;

	try
	{
		cs31::AppleStore store;
		cs31::AppleProduct iPad = store.buyiPad("black", 33);
		cs31::AppleProduct iPadPro = store.buyiPadPro("black", 65);
		cs31::AppleProduct iPhone8 = store.buyiPhone8("black", 65);
		cs31::AppleProduct iPhone8Plus = store.buyiPhone8Plus("black", 65);
		cs31::AppleProduct iPhoneX = store.buyiPhoneX("black", 65);
		cerr << "trying..." << endl;
		assert(false);
	}
	catch (logic_error)
	{
		cerr << "exception caught" << endl;
		assert(true);
	}
	cerr << "all tests passed" << endl;
}