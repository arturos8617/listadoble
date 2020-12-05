#ifndef LISTADOBLELIGADA_H
#define LISTADOBLELIGADA_H
#include <iostream>
using namespace std;

template <class T>
class listaDobleLigada{
	private:
		struct Nodo{
			T dato;
			Nodo *sig;
			Nodo *ant;
			Nodo(const T &dato,Nodo *sig=nullptr,Nodo *ant=nullptr)
			:dato(dato),sig(sig),ant(ant){}
		};
		Nodo *head;
		Nodo *tail;
		size_t cont;
	public:
		listaDobleLigada();
		~listaDobleLigada();
		bool empty();
		void pushfront(const T &dato);
		void pushback(const T &dato);
		int size();
		listaDobleLigada& operator <<(const T &dato){
			pushback(dato);
			return *this;
		}
		T* operator<<(size_t p){
			size_t pos=0;
			Nodo *temp=head;
			while(temp!=nullptr){
				if(p==pos){
					return &temp->dato;
				}
				temp=temp->sig;
				pos++;
			}
			return nullptr;
		}
		void print();
		void print_reverse();
		T* front();
		T* back();
		void pop_front();
		void pop_back();
		void insertar(const  T &dato,size_t);
		void eliminar(size_t);
		T* buscar(const T &dato);
};

template <class T>
listaDobleLigada<T>::listaDobleLigada(){
	cont=0;
	head=NULL;
	tail=NULL;
}
template <class T>
listaDobleLigada<T>::~listaDobleLigada(){
	while(!empty()){
		pop_back();
	}
}
template <class T>
bool listaDobleLigada<T>::empty(){
	return cont==0;
}
template <class T>
void listaDobleLigada<T>::pushfront(const T &dato){
	Nodo *nodo=new Nodo(dato,head);
	if(cont==0){
		head=nodo;
		tail=nodo;
	}
	else{
		head->ant=nodo;
		head=nodo;
	}
	cont++;
}
template <class T>
void listaDobleLigada<T>::pushback(const T &dato){
	Nodo *nodo=new Nodo(dato,nullptr,tail);
	if(cont==0){
	
		head=nodo;
		tail=nodo;
	}
	else{
		tail->sig=nodo;
		
		tail=nodo;
	}
	cont++;
}
template <class T>
int listaDobleLigada<T>::size(){
	return cont;
}
template <class T>
void listaDobleLigada<T>::print(){
	Nodo *temp=head;
	while(temp!=nullptr){
		cout<<temp->dato<<endl;
		temp=temp->sig;
	}
}
template <class T>
void listaDobleLigada<T>::print_reverse(){
	Nodo *temp=tail;
	while(temp!=nullptr){
		cout<<temp->dato<<endl;
		temp=temp->ant;
	}
} 

template <class T>
T* listaDobleLigada<T>::front(){
	if(empty()){
		return nullptr;
	}
	else{
		return &head->dato;
	}
}
template <class T>
T* listaDobleLigada<T>::back(){
	if(empty()){
		return nullptr;
	}
	else{
		return &tail->dato;
	}
}
template <class T>
void listaDobleLigada<T>::pop_front(){
	if(empty()){
		cout<<"Lista Vacia"<<endl;
	}
	else if(cont==1){
		delete head;
		head=nullptr;
		tail=nullptr;
		cont--;
	}
	else{
		Nodo *temp=head->sig;
		temp->ant=nullptr;
		delete head;
		head=temp;
	}
}
template <class T>
void listaDobleLigada<T>::pop_back(){
	if(empty()){
		cout<<"Lista Vacia"<<endl;
	}
	else if(cont==1){
		pop_front();
	}
	else{
		Nodo *temp=tail->ant;
		temp->sig=nullptr;
		delete tail;
		tail=temp;
		cont--;
	}
}
template <class T>
void listaDobleLigada<T>::insertar(const T &dato,size_t p){
	if(p>=cont){
		cout<<"Posicion no valida"<<endl;
	}
	else if(p==0)
	{
		pushfront(dato);
	}
	else{
		Nodo *temp= head;
		size_t pos=1;
		while(temp!=nullptr){
			if(pos==p){
				Nodo *nuevo= new Nodo(dato);
				nuevo->sig=temp;
				nuevo->ant=temp->ant;
				temp->ant->sig=nuevo;
				nuevo->sig->ant=nuevo;
				break;
			}
			temp=temp->sig;
			pos++;
		}
		
	}
	
}
template <class T>
void listaDobleLigada<T>::eliminar(size_t p){
	if(p>=cont){
		cout<<"Posicion no valida"<<endl;
	}
	else if(p==0){
		pop_front();
	}
	else if(p==cont-1){
		pop_back();
	}
	else{
		Nodo *temp= head;
		size_t pos=1;
		while(temp->sig!=nullptr){//temp->sig es puesto por que popback ya cubre el ultimo elemento
			if(pos==p){
				temp->sig->ant=temp->ant;
				temp->ant->sig=temp->sig;
				delete temp;
				cont--;
				break;
			}
			temp=temp->sig;
			pos++;
		}
	}
}
template <class T>
T* listaDobleLigada<T>::buscar(const T &dato){
	if(empty()){
		cout<<"Posicion No Valida"<<endl;
	}
	else{
		Nodo *temp=head;
		size_t pos=0;
		while(temp!=nullptr){
			if(temp->dato==dato){
				return &temp->dato;
			}
			temp=temp->sig;
			pos++;
		}
		return nullptr;
	}
}



#endif

