#pragma once
#include <iostream>
using namespace std;
class output
{
public:
	bool result;
	string path;
	output(bool result, string path) :
		result(result), path(path){}
	void displayOutput() {
		cout << "Result: " << boolalpha << result << endl;
		cout << "Path: " << path << endl;
	}
};

