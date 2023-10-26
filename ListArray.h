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
			T arr2 [new_size];
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
			out << "List -> [ ";
			
			for(int i=0 ; i<list.n ; i++){
				out << list.arr[i] << " ";
			}
			
			out << "]";

			return out;		
		}



		// Métodos clase LIST

		virtual void insert(int pos, T e)override{
			if(pos < 0 || pos > size()) {
				throw std::out_of_range("La posición no es correcta");
			}
			
			if(size() == max){
				resize(size()*2);
			}
		
			if(pos == 0){
				prepend(e);
			}

			else if(pos == size()){
				append(e);
			}

			else {
				for (int i=size() ; i > pos ; i--){
					arr[i] = arr[i-1];
				}	
				arr[pos] = e;
				n++;
			}
		}

		virtual void append(T e) override{
			arr[n] = e;
			n++;
		}

		virtual void prepend(T e) override{
			for (int i=size() ; i > 0 ; i--){
               	                arr[i] = arr[i-1];
			}		
                        arr[0] = e;
              		n++;
		}

		virtual T remove(int pos) override{
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

		virtual T get(int pos) override{
			if(pos < 0 || pos > size()-1) {
                                throw std::out_of_range("La posición no es correcta");
                        }

			return arr[pos];
		}

		virtual int search (T e) override{
			for(int i=0 ; i<size() ; i++){
				if(arr[i] == e){
					return i;
				}
			}
			return -1;
		}

		virtual bool empty() override{
			if(n==0){
				return true;
			}
			else{
				return false;
			}
		}

		virtual int size () override{
			return n;
		}

};
