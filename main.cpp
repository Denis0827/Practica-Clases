#include "lista_ordenada.cpp"
#include <iostream>
#include <set>
#include <map>

using namespace std;

int main(){

    std::cout  << "Hello, World" << std::endl;

    ListaOrdenada lista;
    lista.agregarElemento(1);
    lista.agregarElemento(2);
    lista.agregarElemento(-1);

    std::cout << "Lista" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << lista.obtenerElemento(i) << std::endl;
    }

    std::cout << lista.existeElemento(1) << std::endl;
    std::cout << lista.obtenerElemento(2) << std::endl;

    lista.eliminarElemento(2);
    std::cout << lista.existeElemento(2) << std::endl;

    return 0;
}