// Lab8-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

struct Employer
{
    char F[100] = {};

    char N[100] = {};

    char O[100] = {};

    int numberOtdela = 0;

    char dol[100] = {};

    int stazh = 0;
};


void sort(Employer* ar, int size)
{
    /// Сортировка по Алфавиту
    
    int LeftMark = 0;
    int rightMark = size - 1;
    while (LeftMark <= rightMark)
    {
        for (int i = rightMark; i >= LeftMark; i--)
        {
            if (ar[i - 1].F[0] > ar[i].F[0])
                swap(ar[i - 1], ar[i]);
        }
        LeftMark++;

        for(int i = LeftMark; i < rightMark; i++)
        {
            if (ar[i + 1].F[1] < ar[i].F[1])
                swap(ar[i + 1], ar[i]);
        }
        rightMark--;
    }
}
void input2(Employer* ar, int size)
{

    printf_s("\nВывод полученной структуры на экран:\n");
    for (int i = 0; i < size; i++)
    {
        printf_s("Сотрудник:\n");
        printf_s("%s\t%s\t%s\n", ar[i].F, ar[i].N, ar[i].O);

        printf_s("Номер отдела : %i\n", ar[i].numberOtdela);
        printf_s("Должность: %s\n", ar[i].dol);
        printf_s("Стаж работы: %i\n", ar[i].stazh);
        printf_s("\n");
    }
}
void input(Employer* ar, int size)
{
    printf_s("Введите номер отдела, чтобы узнать сотрудников со стажем более 20 лет\n");
    int n = 0;
    scanf_s("%d", &n);

    printf_s("Список сотрудников: \n");
    for (int i = 0; i < size; i++)
    {
        if (ar[i].numberOtdela == n && ar[i].stazh >= 20)
            printf_s("%s\t%s\t%s\n", ar[i].F, ar[i].N, ar[i].O);
    }
}
void change(Employer* ar, int del)
{
    

    int i = del;
    printf_s("Сотрудник:\n");
    printf_s("Введити Фамилию:\n");
    scanf_s("%s", ar[i].F, 100);
    printf_s("Введити Имя:\n");
    scanf_s("%s", ar[i].N, 100);
    printf_s("Введити Отчество:\n");
    scanf_s("%s", ar[i].O, 100);
    printf_s("Введити номер отдела:\n");
    scanf_s("%d", &ar[i].numberOtdela);
    printf_s("Введити должность:\n");
    scanf_s("%s", ar[i].dol, 100);
    printf_s("Введити стаж работы:\n");
    scanf_s("%d", &ar[i].stazh);


       
}


Employer* delete2(Employer* ar, int size, int del)
{
    int sizeN = size - 1;
    Employer* arrayN = new Employer[sizeN];

    for (int i = 0; i < del; i++)
    {
        strcpy_s(arrayN[i].F, ar[i].F);
        strcpy_s(arrayN[i].N, ar[i].N);
        strcpy_s(arrayN[i].O, ar[i].O);
        arrayN[i].numberOtdela = ar[i].numberOtdela;
        strcpy_s(arrayN[i].dol, ar[i].dol);
        arrayN[i].stazh = ar[i].stazh;

    }

    for (int i = del; i < sizeN; i++)
    {
        strcpy_s(arrayN[i].F, ar[i+1].F);
        strcpy_s(arrayN[i].N, ar[i+1].N);
        strcpy_s(arrayN[i].O, ar[i+1].O);
        arrayN[i].numberOtdela = ar[i+1].numberOtdela;
        strcpy_s(arrayN[i].dol, ar[i+1].dol);
        arrayN[i].stazh = ar[i+1].stazh;
    }

    return arrayN;

   
}


Employer* add(Employer* ar, int size, int ad, int* count)
{
    int sizeN = size + ad;
    Employer* arrayN = new Employer[sizeN];

    for (int i = 0; i < size; i++)
    {
        strcpy_s(arrayN[i].F, ar[i].F);
        strcpy_s(arrayN[i].N, ar[i].N);
        strcpy_s(arrayN[i].O, ar[i].O);
        arrayN[i].numberOtdela = ar[i].numberOtdela;
        strcpy_s(arrayN[i].dol, ar[i].dol);
        arrayN[i].stazh = ar[i].stazh;

    }
    for (int i = size; i < sizeN; i++)
    {
        printf_s("Сотрудник:\n");
        printf_s("Введити Фамилию:\n");
        scanf_s("%s", arrayN[i].F, 100);
        printf_s("Введити Имя:\n");
        scanf_s("%s", arrayN[i].N, 100);
        printf_s("Введити Отчество:\n");
        scanf_s("%s", arrayN[i].O, 100);
        printf_s("Введити номер отдела:\n");
        scanf_s("%d", &arrayN[i].numberOtdela);
        printf_s("Введити должность:\n");
        scanf_s("%s", arrayN[i].dol, 100);
        printf_s("Введити стаж работы:\n");
        scanf_s("%d", &arrayN[i].stazh);
    }
    printf_s("Добавить еще сотрудника?(0/1)\n");

    int t;

    scanf_s("%d", &t);

    if (t == 0)
    {
        printf_s("Сколько вы хотите довавить сотрудников?\n");
        int num = 0;
        scanf_s("%d", &num);
        *count += num;
        return add(arrayN, size + ad, num, count);
    }
    else return arrayN;

    
}




int main()
{

    setlocale(LC_ALL, "Russian");
    int size = 3;
    Employer* array1 = new Employer[size];

   // "Введити информацию о каждом сотруднике(ФИО, номер отдела, стаж работы):\n";

    

    printf_s("Введити информацию о каждом сотруднике(ФИО, номер отдела, должность, стаж):\n");

    for (int i = 0; i < size; i++)
    {

        


        printf_s("Сотрудник:\n");
        printf_s("Введити Фамилию:\n");
        scanf_s("%s", array1[i].F,100);
        printf_s("Введити Имя:\n");
        scanf_s("%s", array1[i].N,100);
        printf_s("Введити Отчество:\n");
        scanf_s("%s", array1[i].O,100);
        printf_s("Введити номер отдела:\n");
        scanf_s("%d", &array1[i].numberOtdela);
        printf_s("Введити должность:\n");
        scanf_s("%s", array1[i].dol,100);
        printf_s("Введити стаж работы:\n");
        scanf_s("%d", &array1[i].stazh);
        

    }

    /// Функция просмотра массива динамической струкуры 
       input2(array1, size);

       //// Добавление в массив новых струтур

       int t;
       printf_s("Хотите добавить нового сотрудника?(0/1)\n");
       scanf_s("%d", &t);

       if (t == 0 )
       {
           printf_s("Сколько вы хотите довавить сотрудников?\n");
           int num = 0, count = 0;
           scanf_s("%d", &num);
           count += num;
           array1 = add(array1, size, num, &count);
           size += count;
       }

       ///Функция удаления массива структур
       
       printf_s("Хотите удалить сотрудника?(0/1)\n");
       scanf_s("%d", &t);
       if (t == 0)
       {
           printf_s("Какого сотрудника вы хотите убрать?(Введите фамилию)\n");
           char st[100];
           int h = 0;
           scanf_s("%s", st,100);
           for (int i = 0; i < size; i++)
           {
               if (strcmp(st, array1[i].F) == 0)
               {
                   h = i;
                   break;
               }
           }
           array1 = delete2(array1, size, h);
           size -= 1;
       }

       /// Функция для изменения массива структур

       printf_s("Хотите изменить данные о сотруднике?(0/1)\n");
       scanf_s("%d", &t);
       if (t == 0)
       {
           printf_s("Какого сотрудника вы хотите изменить?(Введите фамилию)\n");
           char st[100];
           int h = 0;
           scanf_s("%s", st, 100);
           for (int i = 0; i < size; i++)
           {

               if (strcmp(st, array1[i].F) == 0)
               {
                   h = i;
                   break;
               }
           }
          change(array1, h);
       }

       /// Шейкер сортировка
       
       sort(array1, size);

       /// Вывод на экран массива
       printf_s("Вывод измененного массива структур на экран\n");
       input2(array1, size);
     /// Поиск нужного элемента 
       printf_s("Хотите узнать сотрудников с стажем более 20 лет?(0/1)\n");
       scanf_s("%d", &t);
       if (t == 0)
           input(array1, size);
         
    
    
    delete[] array1;
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
