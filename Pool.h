#pragma once
#include <iostream>

template<typename T, int N> class Pool {
public:

    // FUNCTION: Contructor O(1)
    Pool() {
        T* block = new T[N];
        begin = block;
        head = block;
        used = 0;

        // Create Link
		link(begin);
    }

    // FUNCTION: Destructor O(1)
    ~Pool() {
        delete[] block;
    }

    T* allocate() {
        return nullptr;
    }

    T* allocate(unsigned int n) {
        return nullptr;
    }

    void deallocate(T* ptr) {

    }

    void deallocate(T* ptr, int n) {

    }

    T* construct(T t) {
        return nullptr;
    }

private:

    // FUNCTION: link blocks O(1) (since only runs ones in lifetime of)
	void link(T* begin) {

		T* next = begin + 1;
		T* current = begin;

		for (int i = 0; i < (N - 1); i++) {
			T** reint_head = reinterpret_cast<T**>(current);
			*reint_head = next;
			next++;
			current++;
 		}

		T** reint_current = reinterpret_cast<T**>(current);
		*reint_current = nullptr;

		// Logging code
		std::cout << "T Address" << "\t" << "Ptr in T" << std::endl;
		for (int i = 0; i < (N); i++) {
			std::cout << begin << "\t" << *begin << std::endl;
			begin++;
		}
	}

    T* block;
    T* begin;
    T* head;
    int used;

};