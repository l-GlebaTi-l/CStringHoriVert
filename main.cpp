//#include <iostream>
//#include "Vect.hpp"
//
//using namespace std;
//
//int main()
//{
//    CString sss;
//    char data[] = {"Hello world"};
//    sss.Create(data);
//    sss.out();
//    cout << "Hello world!" << endl;
//    return 0;
//}
//
//#include <iostream>
//
//using namespace std;
//
//class Nature{
//protected:
//    int f;
//public:
//    Nature(int n){
//        f = n;
//    }
//    virtual void info() = 0;
//    virtual ~Nature(){} //<-- Виртуальный деструктор
//};
//
//class Man:public Nature{
//public:
//    Man(int n) : Nature(n){}
//    void info(){
//        cout << "I'm is man! " << f << endl; //<-- Информация на экран для наглядности
//    }
//};
//
//class Animal:public Nature{
//public:
//    Animal(int n) : Nature(n){}
//    void info(){
//        cout << "I'm is animal! " << f << endl;//<-- Информация на экран для наглядности
//    }
//};
//
//
///*Создаём руководящий класс*/
//class Factory{
//public:
//    virtual Nature* Create(int n) = 0; //Чистая виртуальная функция показывает, что в производстве будет метод Create
//    virtual ~Factory(){}  //Виртуальный деструктор
//};
//
//
///*Создаём производство*/
//class ManFactory:public Factory{
//public:
//    Nature* Create(int n){
//        return new Man(n); //<-- Создаём объект типа "Человек"
//    }
//};
//
//class AnimalFactory:public Factory{
//public:
//    Nature* Create(int n){
//        return new Animal(n);//<-- Создаём объект типа "Животное"
//    }
//};
///*Создали производство*/
//
//
///*Та самая функция, мозг выносящая*/
//Nature* foo(Factory *value, int n){
//    return value->Create(n);
//}


#include <iostream>

using namespace std;

#include "VectTypes/Vect.hpp"
#include "Factory/Fabric.h"
#include "VectTypes/VectHori.hpp"
#include "VectTypes/VectVert.hpp"

CString *CreateData(char *str, CFabricData **f){
//    cout << "I = " << (int)(str[0] - 48) << endl;
    return f[(int)(str[0] - 48)] -> Create(str + 2);
}


////////////////////////////
int main()
{
    FactoryCStringHori hori_ptr;
    FactoryCStringVert vert_ptr;

    CFabricData **ptrs = new CFabricData*[2];
    ptrs[0] = &hori_ptr;
    ptrs[1] = &vert_ptr;

    CString **Objects = new CString*[0];

    FILE* file = fopen("input.txt", "r");
    char a;
    char *data = new char[1024];
    int N = 0;
//    cout << "START SCANING..." << endl;
    while(fscanf(file, "%c", &a) != EOF){
//        cout << a;
        int i = 0;
        while(a != '\n' && a != '\r'){
            data = (char*)realloc(data, (i+2)*sizeof(char));
            data[i] = a;
            i++;
            if(fscanf(file, "%c", &a) == EOF)
                break;
//            cout << a;
        }
        data[i] = '\0';
        Objects[N] = CreateData(data, ptrs);
        N++;
    }
//    cout << "END SCANING!" << endl;

    for(int i = 0; i < N; i++){
        Objects[i] -> output();
    }

//    for(int i = 0; i < N; i++)
//        delete Objects[i]; //Почистили память

    return 0;
}
