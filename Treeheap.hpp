#ifndef TREEHEAP_H
#define TREEHEAP_H
#include <math.h>
#include <iostream>

using namespace std;

class TreeHeap{
	public:
		TreeHeap(int ); //constructor
		
		int obtener_Max(); //obtener el maximo
		int getparent(int);//Padre
		int getIzquierdo(int);//Hijo Izquierdo
		int getDerecho(int); //Hijo Derecho 
		int getsize();
		int getElemento(int);
		void imprimir(); //imprimir los datos 
		void insertar(int); //funcion insertar
		void PostOrden();
		void InOrden();
		void PreOrden();
		void broad(); //ancho
		
	
	private:
		int *H;
		int size=0;
		int maxtam;
		int Elemento;
		int parent(int);
		int hijoIzquierdo(int);
		int hijoDerecho(int);
		void subir(int);
		void bajar(int);	
	    int Postorden(int);
	    int InOrden(int );
	    int PreOrden(int );
};

#endif