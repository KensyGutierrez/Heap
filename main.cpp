#include "TreeHeap.hpp"
#include <iostream>

using namespace std;
int main(){
	int n=6;
	int l=4;
	int A[n]={10,80,100,10,5,25};
	
	
	TreeHeap H(n);
	for(int i=0;i<n;i++){
		H.insertar(A[i]);
	}
    H.imprimir();
    
    cout<<"__________________________________________________________________"<<endl;
    cout<<"Obtendremos el maximo de nuestro Heap"<<endl;
    H.obtener_Max();
    H.imprimir(); //imprimimos nuestro Heap
    cout<<"__________________________________________________________________"<<endl;
    H.insertar(92); 
    H.imprimir();
    H.insertar(34);
   
 return 0;
}
