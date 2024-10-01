#pragma once
#include <string>
#include <Windows.h>

class BmpDisplay
{
	BITMAPFILEHEADER flhd;
	BITMAPINFOHEADER infhd;

	unsigned char* data;
	char blackChar = '#';
	char whiteChar = '.';

private:
	void printChar(int index);

public:
	int openBMP(const std::string& fileName);
	void displayBMP();
	void closeBMP();
};
