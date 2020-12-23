// Lab8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

struct Employer
{
    string country;
    string team ;
    string F;

    string N;

    string O;

    int number = 0;

    int age = 0;

    int growth = 0;
    
    int weight = 0;
};



void input2(Employer* ar, int size)
{

    printf_s("\nВывод полученной структуры на экран:\n");
    for (int i = 0; i < size; i++)
    {
        printf_s("Игрок:\n");

        cout << "Страна команды: " << ar[i].country << endl;
        cout << "Название комадны: " << ar[i].team << endl;
        cout << "ФИО: " << ar[i].F << "\t" << ar[i].N << "\t" << ar[i].O << endl;

        cout << "Номер игрока: " << ar[i].number << endl;
        cout << "Возраст: " <<  ar[i].age << endl;
        cout << "Рост: " << ar[i].growth << endl;
        cout << "Вес: " << ar[i].weight << endl;
        printf_s("\n");
    }
}
void input(Employer* ar, int size)
{
    int sum = ar[0].age, b = 0;
    for (int i = 0; i < size; i++)
    {
        if (ar[i].age > ar[i + 1].age && i != size - 1)
        {
            if (sum > ar[i + 1].age)
            {
                sum = ar[i + 1].age;
                b = i + 1;
            }
        }

    }



    string way = "Data2.txt";
    ofstream file;
    file.open(way);

    if (!file.is_open())
    {
        cout << "Ошибка файла\n";
    }
    else
    {
        
        file << ar[b].country << "\t";
        file << ar[b].team << "\t";
        file << ar[b].F << "\t";
        file << ar[b].N << "\t";
        file << ar[b].O << "\t";
        file << ar[b].number << "\t";
        file << ar[b].age << "\t";
        file << ar[b].growth << "\t";
        file << ar[b].weight << "\t";
    }

    file.close();
}
void change(Employer* ar, int del)
{


    int i = del;
    printf_s("Игрок:\n");
    cout << "Введите страну комнады:\n";
    cin >> ar[i].country;
    cout << "Введите название команды: \n";
    cin >> ar[i].team;
    printf_s("Введити Фамилию:\n");
    cin >> ar[i].F;
    printf_s("Введити Имя:\n");
    cin >> ar[i].N;
    printf_s("Введити Отчество:\n");
    cin >> ar[i].O;
    printf_s("Введити номер игрока:\n");
    cin >> ar[i].number;
    printf_s("Введити возраст:\n");
    cin >> ar[i].age;
    printf_s("Введити рост игрока:\n");
    cin >> ar[i].growth;
    cout << "Введите вес игрока:\n";
    cin >> ar[i].weight;



}


Employer* delete2(Employer* ar, int size, int del)
{
    int sizeN = size - 1;
    Employer* arrayN = new Employer[sizeN];

    

    for (int i = 0; i < del; i++)
    {
        arrayN[i].country = ar[i].country;
        arrayN[i].team = ar[i].team;
        arrayN[i].F = ar[i].F;
        arrayN[i].N = ar[i].N;
        arrayN[i].O = ar[i].O;
        arrayN[i].number = ar[i].number;
        arrayN[i].age = ar[i].age;
        arrayN[i].growth = ar[i].growth;
        arrayN[i].weight = ar[i].weight;

    }
    
    for (int i = del; i < sizeN; i++)
    {
        arrayN[i].country = ar[i+1].country;
        arrayN[i].team = ar[i+1].team;
        arrayN[i].F = ar[i+1].F;
        arrayN[i].N = ar[i+1].N;
        arrayN[i].O = ar[i+1].O;
        arrayN[i].number = ar[i+1].number;
        arrayN[i].age = ar[i+1].age;
        arrayN[i].growth = ar[i+1].growth;
        arrayN[i].weight = ar[i+1].weight;
    }
    
    return arrayN;


}


Employer* add(Employer* ar, int size, int ad, int* count)
{
    int sizeN = size + ad;
    Employer* arrayN = new Employer[sizeN];

    for (int i = 0; i < size; i++)
    {
        arrayN[i].country = ar[i].country;
        arrayN[i].team = ar[i].team;
        arrayN[i].F = ar[i].F;
        arrayN[i].N = ar[i].N;
        arrayN[i].O = ar[i].O;
        arrayN[i].number = ar[i].number;
        arrayN[i].age = ar[i].age;
        arrayN[i].growth = ar[i].growth;
        arrayN[i].weight = ar[i].weight;

    }
    for (int i = size; i < sizeN; i++)
    {
        cout << "Игрок:\n";
        cout << "Введите название страны команды:\n";
        cin >> arrayN[i].country;
        cout << "Введите название команды:\n";
        cin >> arrayN[i].team;
        cout << "Введите фамилию игрока:\n";
        cin >> arrayN[i].F;
        cout << "Введите имя игрока:\n";
        cin >> arrayN[i].N;
        cout << "Введите отчество игрока:\n";
        cin >> arrayN[i].O;
        cout << "Введите номер игрока:\n";
        cin >> arrayN[i].number;
        cout << "Введите возраст игрока:\n";
        cin >> arrayN[i].age;
        cout << "Введите рост игрока:\n";
        cin >> arrayN[i].growth;
        cout << "Введите вес игрока:\n";
        cin >> arrayN[i].weight;
    }

    
    printf_s("Добавить еще сотрудника?(0/1)\n");

    int t;

    scanf_s("%d", &t);

    if (t == 0)
    {
        printf_s("Сколько вы хотите довавить игроков?\n");
        int num = 0;
        scanf_s("%d", &num);
        *count += num;
        int f = size + ad;
        return add(arrayN, f, num, count);
    }
    else return arrayN;


}




int main()
{

    setlocale(LC_ALL, "Russian");
    int size = 3;
    Employer* array1 = new Employer[size];

    // "Введити информацию о каждом сотруднике(ФИО, номер отдела, стаж работы):\n";



    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

   
    


    /// Заполнение массива структур из файла

    string way = "Data.txt";
    ifstream file2;
    file2.open(way);

    if (!file2.is_open())
        cout << "Ошибка доступа к файлу\n";
    else
    {
        for (int i = 0; i < size; i++)
        {
            string s1, s2, s3, s4, s5;
            int s6, s7, s8, s9;
            file2 >> s1;
            array1[i].country = s1;
            file2 >> s2;
            array1[i].team = s2;
            file2 >> s3;
            array1[i].F = s3;
            file2 >> s4;
            array1[i].N = s4;
            file2 >> s5;
            array1[i].O = s5;
            file2 >> s6;
            array1[i].number = s6;
            file2 >> s7;
            array1[i].age = s7;
            file2 >> s8;
            array1[i].growth = s8;
            file2 >> s9;
            array1[i].weight = s9;
        }
    }

    file2.close();





    

    /// Функция просмотра массива динамической струкуры 
    input2(array1, size);

    //// Добавление в массив новых струтур

    int t;
    printf_s("Хотите добавить нового игрока?(0/1)\n");
    scanf_s("%d", &t);

    if (t == 0)
    {
        printf_s("Сколько вы хотите довавить игроков?\n");
        int num = 0, count = 0;
        scanf_s("%d", &num);
        count += num;
        array1 = add(array1, size, num, &count);
        size += count;
    }

    

    ///Функция удаления массива структур

    printf_s("Хотите удалить игрока?(0/1)\n");
    scanf_s("%d", &t);
    if (t == 0)
    {
        printf_s("Какого игрока вы хотите убрать?(Введите фамилию)\n");
        string st;
        int h = 0;
        cin >> st;
        for (int i = 0; i < size; i++)
        {
            if (st == array1[i].F)
            {
                h = i;
                break;
            }
        }
        array1 = delete2(array1, size, h);
        size -= 1;
    }

    /// Функция для изменения массива структур
    

    printf_s("Хотите изменить данные о игроке?(0/1)\n");
    scanf_s("%d", &t);
    if (t == 0)
    {
        printf_s("Какого игрока вы хотите изменить?(Введите фамилию)\n");
        string st;
        int h = 0;
        cin >>  st;
        for (int i = 0; i < size; i++)
        {

            if (st == array1[i].F)
            {
                h = i;
                break;
            }
        }
        change(array1, h);
    }


    /// Вывод на экран массива
    printf_s("Вывод измененного массива структур на экран\n");
    input2(array1, size);
    /// Поиск нужного элемента 
    printf_s("Хотите узнать информацию о самой молодой команде?(0/1)\n");
    scanf_s("%d", &t);
    if (t == 0)
        input(array1, size);



    delete[] array1;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
