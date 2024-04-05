#include "Treeheap.hpp" 
#include<iostream>
using std::cout;
using std::endl;

// Constructor de la clase TreeHeap
TreeHeap::TreeHeap(int n){
    this->maxtam=n; // Asignamos el tamaño máximo del árbol como n
    this->H=new int(n); // Creamos un array dinámico de tamaño n para el árbol
}

// Método para insertar un elemento en el árbol
void TreeHeap::insertar(int p){
    if(this->size!=this->maxtam){ // Si el tamaño actual del árbol no es igual al tamaño máximo
        H[size]=p; // Insertamos el elemento en la posición size
        subir(size); // Llamamos al método subir para mantener la propiedad del heap
        size++; // Incrementamos el tamaño del árbol
    }else{
        cout<<"El Heap esta lleno"<<endl; 
    }   
}

// Método para mantener la propiedad del heap subiendo un elemento en la posición j
void TreeHeap::subir(int j){
    int a;
    while(i>1 && (H[parent(j)] < H[j])){
        aux= H[parent(j)];
        H[parent(j)]=H[j];
        H[(j)]=a;
        j=parent(j);
    }
}

// Método para obtener el padre de un elemento en la posición i
int TreeHeap::parent(int i){
    return ((i-1)/2);
}

// Método para obtener el máximo elemento del árbol que en nuestro caso reia la raiz
int TreeHeap::obtener_Max(){
    int maximo=H[0];
    H[0]=H[size-1];
    size=size-1;
    bajar(0);
    
    return maximo;
}

// Método para mantener la propiedad del heap bajando un elemento en la posición i
void TreeHeap::bajar(int i){
    int m1=i;
    int m2=i;
    
    int max;
    
    int l=hijoIzquierdo(i);
    int r=hijoDerecho(i);
    int a;
    //Aqui se tomo todos los casos posibles 
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

// Método para obtener el hijo izquierdo de un elemento en la posición i
int TreeHeap::hijoIzquierdo(int i){
    return (2*i+1);
}

// Método para obtener el hijo derecho de un elemento en la posición i
int TreeHeap::hijoDerecho(int i){
    return (2*(i+1));
}

// Método para imprimir el árbol
void TreeHeap::imprimir(){
    for(int i=0; i < size; i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
}

// Método para obtener el padre de un elemento en la posición i
int TreeHeap::getparent(int i){
    return H[Padre(i)]; // Supongo que Padre(i) debería ser parent(i)
}

// Método para obtener el elemento en la posición i
int TreeHeap::getElemento(int i){
    return H[i];
}

// Método para obtener el hijo izquierdo de un elemento en la posición i
int Heap::getIzquierdo(int i){
    if(2*i+1>=size){
        cout<<"no tiene hijo izquierdo"<<endl;
        return i;
    }else{
        return H[2*i+1];
    }
}

// Método para obtener el hijo derecho de un elemento en la posición i
int Heap::getDerecho(int i){
    if(2*(i+1)>=size){
        cout<<"no tiene hijo derecho"<<endl;
        return i;
    }else{
        return H[2*(i+1)];
    }
}

// Método para obtener el tamaño del árbol
int Heap::getsize(){
    return this->size;
}

// Método para imprimir el árbol en postorden
void Heap::PostOrden(){
    PostOrden(0);
}

// Método recursivo para imprimir el árbol en postorden
int Heap::PostOrden(int i){
    if(i>=this->size){
        return i;
    }
    
    PostOrden(hijoIzquierdo(i));
    
    PostOrden(hijoDerecho(i));
    cout<<H[i]<<"  ";
    return i;
}

// Metodo para imprimir el árbol en inorden
void TreeHeap::InOrden(){
    InOrden(0);
}

// Método recursivo para imprimir el árbol en inorden
int TreeHeap::InOrden(int i){
    if(i>=this->size){
        return i;
    }
    InOrden(hijoIzquierdo(i));
    cout<<H[i]<<"  ";
    InOrden(hijoDerecho(i));
    return i;
}

// Método para imprimir el árbol en preorden
void TreeHeap::PreOrden(){
    PreOrden(0);
}

// Método recursivo para imprimir el árbol en preorden
int TreeHeap::PreOrden(int i){
    if(i>=this->size){ //se considera el caso en que i es mayor que la cantidad de nodos
        return i; 
    }
    cout<<H[i]<<"  ";
    PreOrden(hijoIzquierdo(i));
    PreOrden(hijoDerecho(i));
    return i;
}

void TreeHeap::Eliminar(int i){
	b=H[i]; //guardamos en una variable el elemento que queremos eliminar
	H[i]=H[this->size-1];// se toma el dato del ultimo nodo de nuestro Heap
	this->size=size-1; //como eliminamos un elemento entonces actualizamos el tamaño
	subir(n); //se coloca como prueba si es necesario subir
	bajar(n); //se coloca como prueba si es necesario bajar
}
