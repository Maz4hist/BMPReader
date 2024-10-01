# BMPReader
ТЗ:
Создайте класс, который читает формат BMP (24 или 32 бита, другие форматы не нужны) и выводит в консоль двумя разными символами два цвета: черный RGB(0, 0, 0) и белый (фон) RGB(255, 255, 255). На вход должны подаваться только картинки содержащие 2 этих цвета, небольшого размера. Для чтения из файла используйте библиотеку <fstream>. При запуске приложения передаем полный путь к файлу в виде параметра командной строки:
> drawBmp.exe C:\dev\1.bmp
После отображения картинки приложение освобождает все выделенные ресурсы (память, закрывает поток чтения и пр.) и завершается. Необходимые структуры для чтения формата BMP можно объявить самостоятельно или что лучше используйте готовые из <windows.h>.
Ваш класс должен инкапсулировать все необходимые данные по открытию и отображению картинки, а также 3 главные функции приложения: openBMP(const string & fileName), displayBMP(), closeBMP().
