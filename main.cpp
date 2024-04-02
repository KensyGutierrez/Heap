#include <iostream>
#include "Nodo.hpp"
#include<vector>

using namespace std;

int main()
{
  vector<Nodo> arbol;
  vector<Nodo>newTree()=arbol;
  monstrarArbol(arbol);
  cout<<" La altura del arbol  es :  "<< Height(arbol)<<endl;
  
  return 0;
}