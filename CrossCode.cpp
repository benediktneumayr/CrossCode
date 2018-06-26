#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
	ofstream file;
	string text;
	string path;
	cout << "Enter Text:" << endl;
	getline(cin, text);
	cout << "Enter Path:" << endl;
	getline(cin, path);
	file.open(path, ios::trunc);
	int dimension = sqrt(text.length() * 7);
	if (dimension != 7 * text.length()) {
		dimension += 1;
	}
	dimension += 1;
	file << "<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" height=\"" << dimension * 100 << "\" width=\"" << dimension * 100 << "\" style=\"background:white\">";
	for (int i = 0; i < dimension; i++) {
		file << "<rect x=\"0\" y=\"" << i * 100 << "\" height=\"50\" width=\"" << dimension * 100 << "\" style=\"fill:black\" />";
	}
	for (int i = 0; i < text.length(); i++) {
		uint8_t letter = text.at(i);
		if (letter > 127) {
			cout << "ERROR: Character out of bounds!" << endl << "You may close the window and try again.";
			while (1) {}
		}
		for (int ii = 0; ii < 7; ii++) {
			int bit = (letter >> ii) & 1;
			static float x = 0;
			static float y = 0;
			bool nocount = false;
			static int previous_bit = 1;
			if (y == dimension - 1) {
				x++;
				y = 0;
			}
			if (bit == 1) {
				float height = 1;
				if (previous_bit == 0) {
					y += 0.75;
					height = 0.5;
					nocount = true;
				}
				file << "<rect x=\"" << x * 100 << "\" y=\"" << y * 100 << "\" height=\"" << height * 100 << "\" width=\"50\" style=\"fill:black\" />";	
			if (nocount == true) {
				y += 0.25;
			} 
			}
			previous_bit = bit;
			if (nocount == false) {
				y++;
			}
		}
	}
	file << "</svg>";
	file.close();
	cout << "SUCCESS!" << endl << "You may close the window now.";
	while (1) {}
		return 0;
}
