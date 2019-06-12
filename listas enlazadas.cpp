#include <iostream>
using namespace std;

template <typename T>
class nodo
{
	public:
	T data;
	nodo<T> *siguiente;
	nodo(){this->data=NULL,this->siguiente=NULL;}
	nodo(T data_){this->data=data_,this->siguiente=NULL;}
	nodo(nodo<T> *aux){
		this->data=aux.data;
		this->siguiente=aux.siguiente;
	}
	~nodo();	
};

template <class T>
class ListaEnlazada{
	
	nodo<T> *head;
	int size;
	
	public:
		ListaEnlazada(){this->head=NULL,this->size=0;}
		ListaEnlazada(nodo<T> head_){
			head= new nodo<T>(head_);
			size=1;
		}
		void agregar(T data_ ){
		nodo<T> *nuevo_nodo = new nodo<T> (data_);
		nodo<T> *aux=head;
		
		if(!head){
			head=nuevo_nodo;
		}else{
			nuevo_nodo->siguiente=head;
			head=nuevo_nodo;
		}
		size++;
		}	
		
		void insertar_por_indice(nodo<T>aux,int indice){
			T elemento;
        	for (int i = 1; i <= indice; i++) {
		        cout<<"Ingresar el elemento"<<i<<endl;
		        cin>>elemento;
				aux=aux->siguiente;
		      	agregar(elemento);
        	}
    	}	
		
		void eliminar_por_indice(int indice){
			nodo<T> *aux = head;
    		nodo<T> *aux1 = aux->siguiente;
		    if (indice < 1 || indice > size) {
		        cout << "Fuera de rango " << endl;
		    } else if (indice == 1) {
		          head = aux->siguiente;
		    } else {
		        for (int i = 2; i <= indice; i++) {
		            if (i == indice) {
		                nodo<T> *aux_nodo = aux1;
		                aux->siguiente = aux1->siguiente;
		                delete aux_nodo;
		                size--;
		            }
		            aux = aux->siguiente;
		            aux1 = aux1->siguiente;
		        }
		    }
		}
		
		void buscar(T data_)
		{
			nodo<T> *aux = head;
		    int cont = 1;
		    int cont1 = 0;
		 
		    while (aux) {
		        if (aux->data == data_) {
		            cout << "El dato se encuentra en la posición: " << cont << endl;
		            cont1++;
		        }
		        aux = aux->siguiente;
		        cont++;
		    }
		 
		    if (cont1 == 0) {
		        cout << "No existe el dato " << endl;
		    }
		    cout << endl << endl;
		}
		
		void imprimir(){
			nodo<T> *aux=head;
			if (!head){
				cout<<"La lista esta vacia "<<endl;
			}else {
				while(aux){
					cout<<aux->data<<" ";
					if(!aux->siguiente)cout<<"NULL";
					    aux=aux->siguiente;
				}
			}
			cout<<endl<<endl;
		}		
};

int main()
{
	ListaEnlazada<int>listaEnlazada_1;
	listaEnlazada_1.agregar(4);
	ListaEnlazada.agregar(9);
	listaEnlazada_1.imprimir();

}


