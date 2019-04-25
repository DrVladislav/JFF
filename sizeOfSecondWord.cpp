#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string strToSplit, char delimeter)
{
	stringstream ss(strToSplit);
	string item;
	vector<string> splittedStrings;
	while (getline(ss, item, delimeter))
	{
		splittedStrings.push_back(item);
	}
	return splittedStrings;
}

int main() {
	cout << "Vvedite stroky: " << endl;
	string s;
	string delimiter = " ";

	getline(cin, s);
	vector <string> strings = split(s, ' ');
	cout << strings[1].size() << endl;

	system("pause");
}
