#include "auth.h"
#include <fstream>
#include <sstream>
using namespace std;
bool Authentication::login(const string& username, const string& password) {
	ifstream file("users.txt");
	string line;
	while (getline(file, line)) {
		string Username, Password;
		stringstream ss(line);
		getline(ss, line, ',');
		getline(ss, Username, ',');
		getline(ss, Password, ',');
		if (Username == username && Password == password) {
			file.close();
			return true;
		}
	}
	file.close();
	return false;
}
bool Authentication::registerUser(const string& firstname, const string& lastname, const string& username, const string& password) {
	if (userExists(username)) {
		return false; 
	}
	ofstream file("users.txt", ios::app);
	file << firstname << " " << lastname << "," << username << "," << password << endl;
	file.close();
	return true;
}
bool Authentication::userExists(const string& username) {
	ifstream file("users.txt");
	string line;
	while (getline(file, line)) {
		string Username;
		stringstream iss(line);
		getline(iss, line, ','); 
		getline(iss, Username, ',');
		if (Username == username) {
			file.close();
			return true;
		}
	}
	file.close();
	return false; 
}