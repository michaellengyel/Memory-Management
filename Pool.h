#pragma once
#include <iostream>

template <typename T, size_t N> class Pool {
public:

	// FUNCTION: Contructor O(1)
	Pool() {
		block = new T[N];
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

	// FUNCTION: Allocate chuck O(1)
	T* allocate() {
		// Check if Block is full;
		if (used < N) {
			// If Block not full: Store t, increment used, return address of t
			T* ptrStoredInHead = reinterpret_cast<T*>(*head);
			T* addressOfObject = head;
			head = ptrStoredInHead;
			used++;
			return addressOfObject;
		}
		else {
			// If Block is full return nullptr
			return nullptr;
		}
	}

	// FUNCTION: Allocate n contignuous chucks O(n)
	T* allocate(unsigned int n) {

		// Initalize local variables
		int unused = N - used;
		int contigCtr = 0;
		T* contigPtr = head;

		T* addressOfObject = head;
		T* ptrStoredInHead = reinterpret_cast<T*>(*addressOfObject);

		// Check if there is enough free room in Block
		if (n <= unused) {

			// Iterate through the chain and look for n contignuous Block
			// (Currently can only find positive incremental segments)
			for (int i = 0; i < unused; i++) {

				//Discontinued logic: bool isContig = (ptrStoredInHead - addressOfObject) == sizeof(T);
				bool isContig = ((addressOfObject + 1) == ptrStoredInHead);
				bool isLastChuck = (ptrStoredInHead == nullptr);

				// Check two blocks are contignuous or block is last block.
				if (isContig || isLastChuck) {
					contigCtr++;
					used++;
					// If we find n-1 occurances of contignuity between blocks, return ptr to start of segment
					if (contigCtr == (n-1)) {
						return contigPtr;
					}
				}
				// If exists break in contignuity, reset counter, update ptr to new segement's start
				else {
					contigCtr = 0;
					contigPtr = reinterpret_cast<T*>(*addressOfObject);
				}
				// At the end of cycle, increment addressOfObject
				addressOfObject++;
				ptrStoredInHead = reinterpret_cast<T*>(*addressOfObject);
			}
			// If no adequate segment was found, return nullptr
			return nullptr;
		}
		else {
			// If not enought free room in Block, return nullptr
			return nullptr;
		}
	}

	// FUNCTION: deallocate T* ptr block O(1)
	void deallocate(T* ptr) {
		T* temp = head;
		head = ptr;
		T** reint_head = reinterpret_cast<T**>(head);
		*reint_head = temp;
		used--;
	}

	void deallocate(T* ptr, int n) {

		T* next = ptr + 1;
		T* current = ptr;

		// Case: ptr > head (head is changed) 
		if (ptr < head) {
			T* temp = head;
			head = ptr;
			for (int i = 0; i < (n - 1); i++) {
				T** reint_head = reinterpret_cast<T**>(current);
				*reint_head = next;
				next++;
				current++;
				used--;
			}
			T** reint_head = reinterpret_cast<T**>(current);
			*reint_head = temp;
			used--;
		}
		// Case: head > ptr (head is unchanged)
		else {
			//T* temp = head;
			T* temp = reinterpret_cast<T*>(*head);
			T** reint_head = reinterpret_cast<T**>(head);
			*reint_head = ptr;
			for (int i = 0; i < (n - 1); i++) {
				T** reint_head = reinterpret_cast<T**>(current);
				*reint_head = next;
				next++;
				current++;
				used--;
			}
			reint_head = reinterpret_cast<T**>(current);
			*reint_head = temp;
			used--;
		}


	}

	// FUNCTION: construct T t block O(1)
	T* construct(T t) {
		// Check if Block is full;
		if (used < N) {	
			// If Block not full: Store t, increment used, return address of t
			T* ptrStoredInHead = reinterpret_cast<T*>(*head);
			*head = t;
			T* addressOfObject = head;
			head = ptrStoredInHead;
			used++;
			return addressOfObject;
		}
		else {
			// If Block is full return nullptr
			return nullptr;
		}
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

	// Private variables
	T* block;
	T* begin;
	T* head;
	int used;
};