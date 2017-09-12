

// edited text
// save as DAT1.TXT on your directory
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

int MAX = 80;

using namespace std;

void diff(string f1, string f2);

void margin(string path, int left, int right);

int main() {
	string path = "file.txt"; // change to user input
	int left, right;
	// cout << "Enter the path to the file" << endl;
	// getline(cin, line);
	
	fstream out("DAT1.txt");
	cout << "Enter the left and right margins separated by space" << endl;
	string margins;
	getline(cin, margins);
	istringstream unpack(margins);
	unpack >> left >> right;
	margin(path, left, right);

	return 0;
}

// the program should include as many words as can "fit"
// between the margins

// trailing blanks after words, punctuation and special characters

// two spaces after sentences, start at left, max inp. line 80 chars

///concerned with paragraphs

// left_margin + right_margin + text <= 80 chars

void margin(string path, int left, int right) {
	fstream in(path);
	fstream out("DAT1.txt");
	in >> noskipws;
	int cc = 0;
	char c;
	while (in >> c) {
		// output left no. of blanks
		out << stirng(left, ' ');
		cc += left;
		// output 80-(right+left) no. of blanks
		while (cc <= 80-right) {
			out << c;
			in >> c;
		}
		
	}
	in.close();
	out.close();
	return;
}
