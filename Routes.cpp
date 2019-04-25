#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <functional> 
#include <algorithm>

using namespace std;

struct Buses {
	string route;
	string destination;
	double time_out;
	double time_in;
};

vector <Buses> getBuses() {
	// Read csv
	ifstream csv_file("test.csv");
	
	if (csv_file.fail()) {
		throw "Error";
	}

	string line;
	int count_rows = 0;

	while (getline(csv_file, line)) {
		count_rows++;
	}
	
	csv_file.clear();
	csv_file.seekg(0, ios::beg);

	//Buses *buses = new Buses[count_rows];
	vector <Buses> buses(count_rows);

	count_rows = 0;
	string route, destination, time_out, time_in;
	while (getline(csv_file, line)) {
		istringstream s(line);
		getline(s, route, ',');
		getline(s, destination, ',');
		getline(s, time_out, ',');
		getline(s, time_in, '\n');
		//put into struct
		buses[count_rows].route = route;
		buses[count_rows].destination = destination;
		buses[count_rows].time_out = stod(time_out);
		buses[count_rows].time_in = stod(time_in);
		count_rows++;
	}

	csv_file.close();
	
	return buses;
}

void separate() {
	cout << "======================" << endl;
}

void show() {
	vector <Buses> buses = getBuses();
	for (int i = 0; i < buses.size(); i++) {
		cout << "Route:\t" << buses[i].route
			<< "\nDestination:\t" << buses[i].destination
			<< "\nVremya otpravki:\t" << buses[i].time_out
			<< "\nVremya pribitija:\t" << buses[i].time_in << endl;
		separate();
	}
}

void add() {
	cout << "Skolko hotite dobavitj?" << endl;
	int count;
	cin >> count;
	string route, destination, time_out, time_in;
	
	// file pointer 
	fstream csv;

	// opens an existing csv file or creates a new file. 
	csv.open("test.csv", ios_base::app);	
	
	for (size_t i = 0; i < count; i++) {
		cout << "Route:";
		cin >> route;
		cout << "\nDestination:";
		cin >> destination;
		cout << "\nVremya otpravki:";
		cin >> time_out;
		cout << "\nVremya pribitija:";
		cin >> time_in;

		csv << route << ","
			<< destination << ","
			<< time_out << ","
			<< time_in 
			<< "\n";
		separate();
	}

	csv.close();
}

void diff() {
	double _time_out;
	string _destination;

	cout << "Puntk naznachenija:";
	cin >> _destination;
	cout << "\nVremya otpravki:";
	cin >> _time_out;
	
	vector <Buses> buses = getBuses();
	for (int i = 0; i < buses.size(); i++) {
		if (buses[i].destination == _destination && _time_out < buses[i].time_out) {
			separate();
			cout << "Vam podoidet etot avtobus" << endl;
			cout << "Route:\t" << buses[i].route
				<< "\nDestination:\t" << buses[i].destination
				<< "\nVremya otpravki:\t" << buses[i].time_out
				<< "\nVremya pribitija:\t" << buses[i].time_in << endl;
			separate();
		}
	}
}

int main() {
	//Question
	cout << "Esli hotite dobavitj dannie (add), esli sravnitj (diff), esli pokazatj vse (show)?" << endl;
	separate();

	string question;
	getline(cin, question);

	if (question == "add") {
		add();
	}
	if (question == "diff") {
		diff();
	}
	if (question == "show") {
		show();
	}

	system("PAUSE");
}
