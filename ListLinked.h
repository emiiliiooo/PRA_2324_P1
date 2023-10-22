#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	
	Node<T>* first;
	int n;
	
	
    public:
	ListLinked(){
		first = nullptr;
		n = 0;
	}

	~ListLinked(){
		while(first != nullptr){
			Node<T>* aux = first->next;
			delete first;
			first = aux;
		}
	}
        
	T operator[](int pos){
		if(pos < 0 || pos > size()-1) {
                 	throw std::out_of_range("La posición no es correcta");
             	}
		
		Node<T>* aux = first;
		int i = 0;
		while(aux != nullptr && i<pos){
			aux = aux->next;
			i++;
		}

		return aux->data;
	}

	friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		out<<"List -> [";

		Node<T>* aux = list.first;

		while(aux){
			out<<aux->data;
			if (aux->next != nullptr){
				out<< ",";
			}
			aux = aux->next;
		}
		out << "]";
		return out;
	} 
	

	// Métodos Clase List
	
	void insert(int pos, T e){
		if(pos < 0 || pos > size()) {
                        throw std::out_of_range("La posición no es correcta");
        	}
		
		if(pos == 0){
			prepend(e);
		}
		else if(pos == size()){
			append(e);
		}
		else{
			Node<T>* aux = first;
			Node<T>* prev = nullptr;

			int i = 0;

			while(i<pos){
				prev = aux;
				aux = aux->next;
				i++;
			}

			prev->next = new Node(e, aux);
			n++;
		}

	}

	void append(T e){
		Node<T>* aux = first;
		while(aux->next != nullptr){
			aux = aux->next;
		}

		aux->next = new Node(e, aux->next);
		n++;
	}

	void prepend(T e){
		first = new Node(e, first);
		n++;
	}


	T remove(int pos){
		if(pos < 0 || pos > size()-1) {
                        throw std::out_of_range("La posición no es correcta");
                }

		T dato;

		Node<T>* aux = first;
                Node<T>* prev = nullptr;

		if(pos == 0){
			first = aux->next;
			dato = aux->data;
			delete aux;
			n--;
		}

		else{
			int i = 0;

                	while(i<pos){
                    		prev = aux;
                       		aux = aux->next;
                      		i++;
			}

			prev->next = aux->next;
			dato = aux->data;
			delete aux;
			n--;
		}
		return dato;
	}


	T get(int pos){
		if(pos < 0 || pos > size()-1) {
                        throw std::out_of_range("La posición no es correcta");
                }
		
		Node<T>* aux = first;
		
		int i = 0;

		while(i<pos){
                        aux = aux->next;
                        i++;
		}
		return aux->data;
	}


	int search(T e){;

		Node<T>* aux = first;
		int i = 0;

		while(aux != nullptr){
			if(aux->data == e){
				return i;
			}
			aux = aux->next;
			i++;
		}

		return -1;
	}

	bool empty(){
		if(n==0){
			return true;
		}
		else{
			return false;
		}
	}

	int size(){
		return n;
	}
};

