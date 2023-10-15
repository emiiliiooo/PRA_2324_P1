#include <ostream>
#include "List.h"

template <typename T>

class ListArray : public List<T> {
	private:
		T* arr;
		int max;
		int n; 
		static const int MINSIZE = 2;

		void resize (int new_size){
			int arr2 [new_size];
			for (int i=0 ; i<size() ; i++){
				arr2[i] = arr[i];
			}
			delete arr;

			arr = new int [new_size];
			for (int i=0 ; i<new_size ; i++){
				arr[i] = arr2[i];
			}
			max = new_size;
		}


	public:
		ListArray(){
			n = 0;
			max = 2;
			arr = new int[MINSIZE];
		}

		~ListArray(){
			delete arr;
		}

		T operator[] (int pos){
			if(pos < 0 || pos > size()-1) {
                                throw std::out_of_range("La posición no es correcta");
                        }
			
			return arr[pos];
		}

		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			for(int i=0 ; i<list.n ; i++){
				out << list.arr[i] << " ";
			}
			return out;		
		}



		// Métodos clase LIST

		void insert(int pos, T e){
			if(pos < 0 || pos > size()) {
				throw std::out_of_range("La posición no es correcta");
			}
			else{
				if(pos = 0){
					append(e);
				}

				else if(pos = size()){
					prepend(e);
				}

				else {
					for (int i=size() ; i > pos ; i--){
					arr[i] = arr[i-1];
					}	
					arr[pos] = e;
					n++;
				}
			}
		}

		void append(T e){
			arr[n] = e;
			n++;
		}

		void prepend(T e){
			for (int i=size() ; i > 0 ; i--){
               	                arr[i] = arr[i-1];
			}		
                        arr[0] = e;
              		n++;
		}

		T remove(int pos){
			if(pos < 0 || pos > size()-1) {
                                throw std::out_of_range("La posición no es correcta");
                        }

			int aux = arr[pos];
			for(int i=pos ; i<n-1 ; i++){
				arr[i] = arr[i+1];
			}
			n--;
			return aux;
		}

		T get(int pos){
			if(pos < 0 || pos > size()-1) {
                                throw std::out_of_range("La posición no es correcta");
                        }

			return arr[pos];
		}

		int search (T e){
			for(int i=0 ; i<size() ; i++){
				if(arr[i] = e){
					return i;
				}
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

		int size (){
			return n;
		}

};
