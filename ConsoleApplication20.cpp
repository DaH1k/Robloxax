#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//Alex 1 0 0 1 1 1 0
void main()
{
	ifstream fin("attendance.txt");
	ofstream fout("summary.txt");
	string line;
	int totalStudents = 0, totalPresent = 0, totalEntries = 0;
	while (getline(fin, line)) {
		istringstream iss(line);
		string name;
		int status, present = 0, absent = 0;
		iss >> name;
		while (iss >> status) {
			if (status == 1) { present++; }
			else { absent++; }
		}
		fout << name << ": Attendance - " << present <<" Absents: " << absent << endl;
		totalStudents++;
		totalPresent += present;
		totalEntries += present + absent;
	}
	double avg = (totalEntries > 0) ? (double)totalPresent / totalEntries * 100 : 0;
	fout << "---------------------------------------------------------------" << endl;
	<< endl;
	fout << "Average attendance: " << avg << " % " << endl;
	cout << "Hello world!"<<endl;
	fin.close();
	fout.close();
}
