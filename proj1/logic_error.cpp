// Code for Project 1
// Pet survey results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
	int surveyParticipants;
	int preferDogs;
	int preferCats;

	cout << "How many students participated in this survey? ";
	cin >> surveyParticipants;
	cout << "How many students prefer a pet dog? ";
	cin >> preferDogs;
	cout << "How many students prefer a pet cat? ";
	cin >> preferCats;

	double pctDogs = 100.0 * preferDogs / surveyParticipants;
	double pctCats = 90.0 * preferCats / surveyParticipants;

	cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
	cout.precision(1);
	cout << endl;
	cout << pctDogs << "% preferred dogs.  Ruff Ruff!" << endl;
	cout << pctCats << "% preferred cats.  Meow." << endl;

	if (pctDogs > pctCats)
	{
		cout << "It was more dogs than cats." << endl;

	}
	else
	{
		cout << "It was more cats than dogs." << endl;

	}
	return(0);

}

