#include <vector>
#include <string>
using namespace std;

// Implementar la clase ListaOrdenada que permita 
// agregar elementos y verificar si un elemento existe en la lista.

bool busquedaBinaria(const vector<int> &v, int numero, int d, int h) {
    if(d == h-1) {
        if(numero == v[d]) {
            return true;
        } else {
            return false;
        }
    }

    else {
        int med = (d + h) / 2;
        if(v[med] > numero) {
            return busquedaBinaria(v, numero, d, med);
        } else {
            return busquedaBinaria(v, numero, med, h);
        }
    }
}  

void merge(vector<int> &v, int d, int med, int h){
    int i = 0; int j = 0; int k = d;
    vector<int> v1 = {};
    vector<int> v2 = {};

    for(int n = d; n < med; n++) {
        v1.push_back(v[n]);
    }

    for(int n = med; n < h; n++) {
        v2.push_back(v[n]);
    }

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            v[k] = v1[i];
            i++;
            k++;
        } else {
            v[k] = v2[j];
            j++;
            k++;
        }
    }

    while(i < v1.size()){
        v[k] = v1[i];
        i++;
        k++;
    }

    while(j < v2.size()){
        v[k] = v2[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> & v, int d, int h){
    // Ordena los elementos desde d hasta h (sin incluir)
    // Si hay 0 o 1 elementos, ya están ordenados
    if(h - d <= 1) {
        return ;
    }

    // Divide y ordena cada mitad
    int med = (d+h)/2;
    mergesort(v, d, med);
    mergesort(v, med, h);

    // Devuelve la unión ordenada de ambas mitades
    merge(v, d, med, h);
}


class ListaOrdenada {
    public:

    ListaOrdenada(){};
    
    // Observadores
    int obtenerElemento(int i) const{               // O(1)
        // Pre: 0 <= i < |lista| Post: vr = i-ésimo elemento de la lista
        return this->_elementos[i];
    };

    int size() {                                    // O(1)
        // Pre: True Post: vr = |lista|
        return this->_cant_elementos;
    }

    bool existeElemento(const int numero) const {   // O(log n)
        // Pre: True Post: vr = true sii el elemento se encuentra en la lista
        return busquedaBinaria(this->_elementos, numero, 0, this->_cant_elementos);
    };

    // Modificadores
    void agregarElemento(const int numero) {        // O(n log n)
        // Pre: True Post: agrega el elemento a la lista
        this->_cant_elementos++;
        this->_elementos.push_back(numero);
        mergesort(this->_elementos, 0, this->_cant_elementos);
        return;
    };


    void eliminarElemento(const int numero) {       // O(n)
        // Pre: True Post: elimina el elemento de la lista
        this->_cant_elementos--;
        vector<int> aux = {};
        
        for(int i = 0; i < this->size(); i++) {
            if(this->_elementos[i] != numero) {
                aux.push_back(this->_elementos[i]);
            }
        }

        this->_elementos = aux;

        return;
    };

    private:
    // completar
        vector<int> _elementos;
        int _cant_elementos;

};
