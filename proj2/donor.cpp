#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Initializing variables
	string donorName;
	string gender;
	int age;
	int weight;
	int height;
	


	//reading in user data
	cout << "Donor name: ";
	getline(cin, donorName);
	
	if (donorName == "")
	{
		cout << "--- You must enter a valid name." << endl;
		return (0);
	}

	cout << "Gender: ";
	getline(cin, gender);

	if (gender != "Male")
	{
		if (gender != "Female")
		{
			if (gender != "Trans Male")
			{
				if (gender != "Trans Female")
				{
					if (gender != "Queer")
					{
						if (gender != "Different")
						{
							cout << "--- You must enter a valid gender." << endl;
							return (0);
						}
					}
				}
			}
		}
	}

	cout << "Age: ";
	cin >> age;

	if (age <= 0)
	{
		cout << "--- You must enter a valid age." << endl;
		return (0);
	}

	cout << "Weight: ";
	cin >> weight;

	if (weight <= 0)
	{
		cout << "--- You must enter a valid weight." << endl;
		return (0);
	}

	cout << "Height: ";
	cin >> height;
	if (height <= 0)
	{
		cout << "--- You must enter a valid height." << endl;
		return (0);
	}


	
	//checking cases where noone can donate regardless of gender or weight or height
	if (age < 16) 
	{
		cout << "--- No, " << donorName << " you cannot donate blood." << endl;
	}
	else if (weight < 110) 
	{
		cout << "--- No, " << donorName << " you cannot donate blood." << endl;
	}
	
	
	/*tests each gender to see if it user is that gender and if no goes to next and if yes tests other variables to determine blood donation candidacy*/
	else if (gender != "Male")
	{
		if (gender != "Female")
		{
			if (gender != "Trans Male")
			{
				if (gender != "Trans Female")
				{
					if (gender != "Queer")
					{
						if (gender == "Different")
						{
							if (age > 22)
							{
								cout << "--- Yes, " << donorName << " you can donate blood." << endl;
							}
							else
							{
								cout << "--- No, " << donorName << " you cannot donate blood." << endl;
							}
						}
					}
					else if (gender == "Queer")
					{
						if (age > 22)
						{
							cout << "--- Yes, " << donorName << " you can donate blood." << endl;
						}
						else
						{
							cout << "--- No, " << donorName << " you cannot donate blood." << endl;
						}
					}
				}
				else if (gender == "Trans Female")
				{
					if (age > 22)
					{
						cout << "--- Yes, " << donorName << " you can donate blood." << endl;
					}
					else
					{
						cout << "--- No, " << donorName << " you cannot donate blood." << endl;
					}
				}
			}
			else if (gender == "Trans Male")
			{
				if (age > 22)
				{
					cout << "--- Yes, " << donorName << " you can donate blood." << endl;
				}
				else
				{
					cout << "--- No, " << donorName << " you cannot donate blood." << endl;
				}
			}

		}
		else if (gender == "Female")
		{
			if (age <= 22)
			{
				if (height < 58)
				{
					cout << "--- No, " << donorName << " you cannot donate blood." << endl;
				}
				else if (height == 58)
				{
					if (weight >= 146)
					{
						cout << "--- Yes, " << donorName << " you can donate blood." << endl;
					}
					else
					{
						cout << "--- No, " << donorName << " you cannot donate blood." << endl;
					}
				}
				else if (height == 59)
				{
					if (weight >= 142)
					{
						cout << "--- Yes, " << donorName << " you can donate blood." << endl;
					}
					else
					{
						cout << "--- No, " << donorName << " you cannot donate blood." << endl;
					}
				}
				else
				{
					cout << "--- Yes, " << donorName << " you can donate blood." << endl;
				}
			}
			else
			{
				cout << "--- Yes, " << donorName << " you can donate blood." << endl;
			}
		}
	}
	else
	{
		if (age > 22)
		{
			cout << "--- Yes, " << donorName << " you can donate blood." << endl;
		}
		else
		{
			if (height < 60)
			{
				cout << "--- No, " << donorName << " you cannot donate blood." << endl;
			}
			else
			{
				cout << "--- Yes, " << donorName << " you can donate blood." << endl;
			}
		}
	}
//its over yoooooo
}
	