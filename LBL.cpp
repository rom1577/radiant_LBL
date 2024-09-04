// LBL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    // Создадим переменные, которые будут действовать во всей проге (константы)
    
    double hhh = 6.62607e-34; // постоянная планка Дж с
    double ccc = 2.997925e10; // скорость звука см/с
    double kkk = 1.380658e-23; // постоянная больцамана

    //std::cout << "Hello World!\n";
    clock_t start_time = clock();
    
    string filename = "C:/Users/roma/Desktop/MOLCHANOV/proga/test.txt";

    fstream reading(filename);
    
    if (reading)
    {   
        // Парсим файл из базы данных 
        string data;
        int m = 0;
        while (getline(reading, data)) // пока есть строчка. getline - считывание по строкам.
        {
            m++;

            string sM = data.substr(0, 2);
            cout << sM << endl;

            // конвертируем в число id молекулы
            int M = stoi(sM);
            cout << M << endl;

            // номер изотопа
            string sI = data.substr(2, 1);
            cout << sI << endl;
            int I = stoi(sI);
            cout << I << endl;

            // Волновое число. Конвертируем в числа с плавающей запятой с двйоной точностью
            string snu = data.substr(3, 12);
            cout << snu << endl;
            double nu = stod(snu);
            cout.precision(12);
            cout << nu << endl;  // Однако оно считалось до точки. Чтоб это убрать делаем cout.precision. Это прикол форматированного вывода на печать
            //cout << scientific << nu << endl;  // чтоб е в степени формат

            // Сила линии (интенсивность линии). Через него считаются коэф поглощения и отраж
            string sS = data.substr(15, 10);
            cout << sS << endl;
            double S = stod(sS);
            cout.precision(10);
            cout << S << endl;

            // коэф Энштейна
            string sA = data.substr(25, 10);
            cout << sA << endl;
            double A = stod(sA);
            cout.precision(10);
            cout << A << endl;

            // Линии расширяются (это не палочка). Она размыта вокруг центра по уширению Лоренца. Чтобы посчитать как размывается линия
            // нужны параметры Gaie , Sself
            string sGair = data.substr(35, 5);
            cout << sGair << endl;
            float Gair = stod(sGair); // превратим в двойную точность, но тк выделено памяти под float, проищойдет конвертация двойной точности в одинарную
            cout.precision(5);
            cout << Gair << endl;

            // уширение происзожит за счет соударения с такой же молекулой или с любой другой. Это уширение за счет соударнеия с самой собой.
            // Gair это с другими - подразумевается возудх.
            string sSself = data.substr(40, 5);
            cout << sSself << endl;
            float Self = stof(sSself);
            cout.precision(5);
            cout << Self << endl;

            // нижний энергетический уровень
            string sEl = data.substr(45, 10);
            cout << sEl << endl;
            double El = stod(sEl);
            cout.precision(10);
            cout << Self << endl;

            string sn = data.substr(55, 4);
            cout << sn << endl;
            float n = stof(sn);
            cout.precision(4);
            cout << n << endl;

            string sDelta = data.substr(59, 8);
            cout << sDelta << endl;
            double Delta = stod(sDelta);
            cout.precision(8);
            cout << scientific << Delta << endl;
            cout << n << endl;
        }
        cout << "m" << m << endl;
    }
    else
    {
        cout << "File colud not be opened" << endl;
        exit(1);

    }


   // Теперь запишем константу скорсоть света и больцмана, планка, пи, авогадро, газовая постоянная.
}
// область действия переменных определяется скобками. то есть переменная выйдя из скобки 
// удаляется из оперативной памяти и не видна. Это нужно чтоб не тащить ненужные переменные.
// В Fortran наоборот. Там все переменные объявляются в начлаае и тянутся по всей проге.




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
