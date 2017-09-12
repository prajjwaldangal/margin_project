

// edited text
// save as DAT1.TXT on your directory
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int MAX = 80;
string OUT_PATH = "DAT1.txt";

void diff(string f1, string f2);

void margin(string path, int left, int right);

int main() {
	map <char, bool> myMap; //  period, comma, and parentheses, special chars
	// myMap.insert(pair<char, bool>('.', true));
	myMap.insert(pair<char, bool>(',', true));
	myMap.insert(pair<char, bool>(')', true));
	myMap.insert(pair<char, bool>('@', true));
	myMap.insert(pair<char, bool>('!', true));
	myMap.insert(pair<char, bool>('%', true));
	myMap.insert(pair<char, bool>('$', true));
	myMap.insert(pair<char, bool>('&', true));
	myMap.insert(pair<char, bool>('#', true));
	myMap.insert(pair<char, bool>('^', true));
	myMap.insert(pair<char, bool>('*', true));
	myMap.insert(pair<char, bool>('_', true));
	string path = "file.txt"; // change to user input
	int left, right;
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
	fstream out(OUT_PATH);
	in >> noskipws;
	char c;
	int cc; // cc: character count
	while (in >> c) {
		cc = 0;
		// output left no. of blanks
		out << string(left, ' ');
		cc += left;
		// output 80-(right+left) no. of blanks
		while (cc <= 80-right-1) {
			out << c;
			cc += 1;
			in >> c;
		}
		out << c;
		// output right margin
		out << string(right, ' ');
		out << '\n';
	}
	in.close();
	out.close();
	return;
}
