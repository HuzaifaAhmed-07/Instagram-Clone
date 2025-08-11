#pragma once
#include <windows.h>
#include <string>
using namespace std;
class Authentication {
public:
	static bool login(const string& username, const string& password);
	static bool registerUser(const string& firstname, const string& lastname, const string& username, const string& password);
	static bool userExists(const string& username);
};