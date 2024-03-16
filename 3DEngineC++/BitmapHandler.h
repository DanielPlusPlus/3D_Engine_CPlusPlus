#include <iostream>
#include <string>
#include <vector>
#include <GL/freeglut.h>

class BitmapHandler
{
public:
	int width;
	int height;
	std::vector<unsigned char> data;
	BitmapHandler();
	BitmapHandler(int width, int height); //tworzenie
	~BitmapHandler(); //usuwanie
	void loadFromFile(std::string filename); //wczytywanie z pliku
	void saveToFilePNG(std::string filename); //zapisywanie do pliku
	void saveToFileJPG(std::string filename); //zapisywanie do pliku
	void saveToFileBMP(std::string filename); //zapisywanie do pliku
	void saveToFileTGA(std::string filename); //zapisywanie do pliku
	void copyFromBitmap(BitmapHandler texture); //kopiowanie pomiêdzy bitmapami 
	void draw(); //rysowanie bitmapy z tekstury
};

