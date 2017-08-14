#ifndef COMPILER_LIST_H
#define COMPILER_LIST_H

#include <cstdlib>

namespace Compiler {
	
	template <class T>
	class List {
	private:
		T* data;
		int ptr;
		int size;
		
	public:
		List(int size);
		~List();
		
		void set(T data, int ptr);
		void add(T data);
		T get(int ptr);
		
		inline T* getRawData() const { return data; }
		inline int getPointer() const { return ptr; }
		inline int getSize() const { return ptr; }
		inline int getAllocatedSize() const { return size; }
	};
	
	template <class T>
	List<T>::List(int size) {
		this->data = (T*) malloc(sizeof(T) * size);
		this->size = size;
		this->ptr = 0;
	}
	
	template <class T>
	List<T>::~List() {
		free(this->data);
	}
	
	template <class T>
	void List<T>::set(T data, int ptr) {
		this->data[ptr] = data;
	}
	
	template <class T>
	void List<T>::add(T data) {
		if (getSize() >= getAllocatedSize()) {
			this->size *= 2;
			this->data = (T*) realloc(this->data, sizeof(T) * getAllocatedSize());
		}
		
		this->data[this->ptr++] = data;
	}
	
	template <class T>
	T List<T>::get(int ptr) {
		return this->data[ptr];
	}
	
}

#endif // COMPILER_LIST_H