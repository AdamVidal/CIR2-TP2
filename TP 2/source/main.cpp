#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#define multiplier(x,y)(x * y)


class  TextRectangle {
public:

	int TextRectangle::get_width() {
		return width;
	}

	int TextRectangle::get_height() {
		return height;
	}

	void TextRectangle::set_width(int w) {
		if(w>0 && w<10)
			width = w;
	}

	void TextRectangle::set_height(int h) {
		if (h > 0 && h < 10)
			height = h;
	}

	int TextRectangle::getArea() {
		return width * height;
	}

	int TextRectangle::getPerimeter() {
		return 2 * width + 2 * height;
	}

	void TextRectangle::print() {
		cout << "Width : " << get_width() << endl << "Height : " << get_height() << endl << "Area : " << getArea() << endl << "Perimeter : " << getPerimeter() << endl;
	}

	void drawArea(const char& pattern) {
		int h = get_height();
		int w = get_width();
		for(int i = 0; i < h; i++)
			cout << string(w, pattern) << endl;
	}

	void drawPerimeter(const char& pattern) {
		int h = get_height();
		int w = get_width();
		cout << string(w, pattern) << endl;
		if (h > 1) {
			for (int i = 1; i < h - 1; i++)
				cout << pattern << setw(w - 1) << pattern << endl;
			cout << string(w, pattern) << endl;
		}
	}

private:
	int width;
	int height;
};

TextRectangle create_rectangle(int width, int height) {
	TextRectangle rectangle;
	rectangle.set_width(width);
	rectangle.set_height(height);
	return rectangle;
}

int main() {
	int a;
	int b;

	cout << "Entrez une valeur :" << endl;
	cin >> a;
	cout << "Entrez une autre valeur :" << endl;
	cin >> b;
	cout << multiplier(a, b) << endl;


	//Ex 2
	int n;
	cout << "Table de multipication de :" << endl;
	cin >> n;
	cout << n << " *";
	for (int i = 1; i <= 10; i++) {
		cout << " | " << i;
	}
	cout << endl;
	cout << "    ";
	for (int i = 1; i <= 10; i++) {
		cout << "| ";
		cout << n * i;
		if (n * i <= 9) cout << " ";
	}
	cout << endl;


	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << setw(3) << i * j << " |";
		}
		cout << endl;
	}
	cout << endl;
	
	//Ex 3
	ifstream file("texte.txt");
	string line;
	int nb_lines = 0;
	int nb_letters = 0;
	int nb_words = 0;
	bool prev_is_letter;
	int letter_nb[26] = { 0 };
	int i;
	if (file.is_open()) {
		while (file.peek()!=EOF){
			getline(file, line);
			i = 0;
			while(line[i]!='\0'){
				cout << line[i];
				if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
					nb_letters++;
					prev_is_letter = true;
					if (line[i] <= 'z')
						letter_nb[line[i] - 'a']++;
					if (line[i] >= 'A')
						letter_nb[line[i] - 'A']++;
				}
				else if (line[i] == ' ' && prev_is_letter) {
					nb_words++;
					prev_is_letter = false;
				}
				else {
					prev_is_letter = false;
				}
				i++;
			}
			if (prev_is_letter) {
				nb_words++;
			}
			cout << endl;
			nb_lines++;
		}
		cout << "Nombre de lignes : " << nb_lines << endl << "Nombre de lettres : " << nb_letters << endl << "Nombre de mots : " << nb_words << endl;
		for (int i = 0; i < 26; i++) {
			cout << "Nombre de '" << (char)(i + 'a') << "' : " << letter_nb[i] << endl;
		}
	}

	//Ex4

	int w;
	int h;
	cout << "Entrez la largeur du rectangle : " << endl;
	cin >> w;
	cout << "Entrez la hauteur du rectangle : " << endl;
	cin >> h;

	TextRectangle rect = create_rectangle(w, h);

	rect.print();

	rect.drawArea('#');
	rect.drawPerimeter('+');

}