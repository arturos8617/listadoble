#include <iostream>
#include "listadobleligada.h"
using namespace std;

int main(){
	enteros.push_front(1);
    enteros.push_front(2);
    enteros.push_front(3);
    enteros << 4 << 5 << 6;

     for (size_t i = 0; i < enteros.size(); i++)
		{
    	   cout << *enteros[i] << endl;
    	}
    
    enteros.insertar(0, 3); 
    enteros.eliminar(1);

    cout << "cantidad: " << enteros.size() << endl;

    enteros.print();
    cout << endl;
    enteros.print_reverse();
    int *front = enteros.front();
    if (front) {
        cout << "front: " << *front << endl;
    }
    int *back = enteros.back();
    if (back) {
        cout << "back: " << *back << endl;
    }
    enteros.pop_front();
    cout << endl;
    enteros.print();
    cout << endl;
    enteros.pop_back();
    enteros.print();
    enteros.~listaDobleLigada();
    cout << "cantidad: " << enteros.size() << endl;

	return 0;
}
