#include <iostream>
#include "BmpDisplay.h"

using namespace std;

int main(int args, string path)
{
    if (args < 2)
    {
        cout << "Usage: TestTaskCpp.exe <full_file_path>";
        return 1;
    }

    BmpDisplay* bmp = new BmpDisplay();

    if (bmp->openBMP(path) == -1) 
        return -1;
    bmp->displayBMP();
    bmp->closeBMP();

    delete bmp;
    return 0;
}
