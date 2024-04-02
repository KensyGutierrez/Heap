#include "Treeheap.hpp"

TreeHeap::TreeHeap(int n){
	this->maxtam=n; //n es mi tamaño
	this->H=new int(n);
}

void TreeHeap::insertar(int p){
	if(this->size!=this->maxtam){
		H[size]=p;
	    subir(size);
	    size++;
	}else{
		cout<<"El Heap esta lleno"<<endl;
	}	
}

void TreeHeap::subir(int j){
	int a;
	while(i>=1 && (H[parent(j)] < H[j])){
		aux= H[parent(j)];
		H[parent(j)]=H[j];
		H[(j)]=a;
		j=parent(j);
	}
}

int TreeHeap::parent(int i){
	return ((i-1)/2);
}

int TreeHeap::obtener_Max(){
	int max=H[0];
	H[0]=H[size-1];
	size=size-1;
	bajar(0);
	
	return max;
}

void TreeHeap::bajar(int i){
	int m1=i;
	int m2=i;
	
	int max;
	
	int l=hijoIzquierdo(i);
	int r=hijoDerecho(i);
	int a;
	
if(l < size && H[l] >= H[m1]){
      m1=l;
}

if(r < size && H[r] >= H[m2]){
      m2=r;
}

if(m1 == i && m2!=i){
      a= H[i];
      H[i]= H[m2];
      H[m2]= a;
      
      bajar(m2);
      }

if(m1 != i && m2==i){
      a= H[i];
      H[i]= H[m1];
      H[m1]= a;
      
      bajar(m1);
      }

if(m1 != i && m2!=i){
      if(H[m1]>=H[m2]){
            max=m1;
      }else{
            max=m2;
      }
      aux= H[i];
      H[i]= H[max];
      H[max]=aux;
      
      bajar(max);
}
if(m1==i && m2==i){
      cout<<"Arbol vacio"<<endl;
}
}
int TreeHeap::hijoIzquierdo(int i){
      return (2*i+1);
}

int TreeHeap::hijoDerecho(int i){
      return (2*(i+1));
}

void TreeHeap::imprimir(){
      
      for(int i=0; i < size; i++){
            cout<<H[i]<<" ";
            cout<<endl;
      }
}

int TreeHeap::getparent(int i){
      return H[Padre(i)];
}
int TreeHeap::getElemento(int i){
      return H[i];
}
int Heap::getIzquierdo(int i){
      if(2*i+1>=size){
            cout<<"no tiene hijo izquierdo"<<endl;
            return i;
      }else{
            return H[2*i+1];
      }
}
int Heap::getDerecho(int i){
      if(2*(i+1)>=size){
            cout<<"no tiene hijo derecho"<<endl;
            return i;
      }else{
            return H[2*(i+1)];
      }
}
int Heap::getsize(){
      return this->size;
}
void Heap::PostOrden(){
      
      PostOrden(0);
}
int Heap::PostOrden(int i){
      
      if(i>=this->size){
            return i;
      }
      
      PostOrden(hijoI(i));
      
      PostOrden(hijoD(i));
      cout<<H[i]<<"  ";
      return i;
}
void TreeHeap::InOrden(){
      InOrden(0);
}
int TreeHeap::InOrden(int i){
      if(i>=this->size){
            return i;
      }
      InOrden(hijoI(i));
      cout<<H[i]<<"  ";
      InOrden(hijoD(i));
      return i;
}
void TreeHeap::PreOrden(){
      PreOrden(0);
}
int TreeHeap::PreOrden(int i){
      if(i>=this->size){
            return i;
      }
      cout<<H[i]<<"  ";
      PreOrden(hijoI(i));
    PreOrden(hijoD(i));
      return i;
}
void TreeHeap::Anchura(){
      int l=0;
      int aux=0;
      cout<<" || ";
      for(int i=0;i<this->size;i++){
            
               if(i<pow(2,l)+aux){
                    cout<<H[i]<<" ";
               }else{
                     cout<<" H: "<<H[i]<<" ";
                     aux=i;
                     l=l+1;
               }  
            }

}