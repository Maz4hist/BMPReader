#include "BmpDisplay.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;


int BmpDisplay::openBMP(const string& fileName)
{
	ifstream pic;
	pic.open(fileName, ios::binary);

	if (!pic)
	{
		cerr << "File could not be opened";
		return -1;
	}

	pic.read(reinterpret_cast<char*>(&this->flhd), sizeof(BITMAPFILEHEADER));
	pic.read(reinterpret_cast<char*>(&this->infhd), sizeof(BITMAPINFOHEADER));

	if (flhd.bfType != 0x4D42)
	{
		cerr << "This file is not a BMP or is corrupted";
		return -1;
	}

	if (infhd.biBitCount != 24 && infhd.biBitCount != 32)
	{
		cerr << "This BMP file is not 24 or 32 bit";
		return -1;
	}

	data = new unsigned char[flhd.bfSize - flhd.bfOffBits];

	pic.seekg(flhd.bfOffBits, ios::beg);
	pic.read(reinterpret_cast<char*>(this->data), flhd.bfSize - flhd.bfOffBits);

	pic.close();
	return 0;
}

void BmpDisplay::displayBMP()
{
	int bitesPerPixel = infhd.biBitCount / 8;
	int rowSize = bitesPerPixel * infhd.biWidth;
	int rowPadding = (4 - rowSize % 4) % 4;

	for (int i = infhd.biHeight - 1; i >= 0; i--)
	{
		for (int j = 0; j < rowSize; j += bitesPerPixel)
			printChar(i * (rowSize + rowPadding) + j);
		cout << endl;
	}
}

void BmpDisplay::closeBMP()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

void BmpDisplay::printChar(int index)
{
	if (data[index + 2] == 0xff &&
		data[index + 1] == 0xff &&
		data[index] == 0xff)
		cout << whiteChar;
	else if (data[index + 2] == 0x00 &&
		data[index + 1] == 0x00 &&
		data[index] == 0x00)
		cout << blackChar;
	else
		cerr << "The file contains not only white and black colors" << endl;
}