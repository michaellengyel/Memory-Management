#include "Pool.h"


int main() {

	// Testing construct function (Currently Broken)
	/*
	{
		Pool<int, 10> pool;

		int* a = pool.construct(22);
		std::cout << "Address of a: " << a << " Value of a: "<< *a << std::endl;
		int* b = pool.construct(423);
		std::cout << "Address of b: " << b << " Value of b: " << *b << std::endl;
		int* c = pool.construct(83);
		std::cout << "Address of c: " << c << " Value of c: " << *c << std::endl;
		int* d = pool.construct(63);
		std::cout << "Address of d: " << d << " Value of d: " << *d << std::endl;
		int* e = pool.construct(77);
		std::cout << "Address of e: " << e << " Value of e: " << *e << std::endl;

		pool.deallocate(c);

		int* f = pool.construct(99);
		std::cout << "Address of f: " << f << " Value of f: " << *f << std::endl;

		pool.deallocate(e);

		int* g = pool.construct(25);
		std::cout << "Address of g: " << g << " Value of g: " << *g << std::endl;

		int* h = pool.allocate();
		std::cout << "Address of h: " << h << " Value of h: " << *h << std::endl;
		*h = 11;
		std::cout << "Address of h: " << h << " Value of h: " << *h << std::endl;
	}
	
	{
		Pool<int, 9> pool;

		int* a = pool.construct(22);
		std::cout << "Address of a: " << a << " Value of a: " << *a << std::endl;
		int* b = pool.construct(423);
		std::cout << "Address of b: " << b << " Value of b: " << *b << std::endl;
		int* c = pool.construct(83);
		std::cout << "Address of c: " << c << " Value of c: " << *c << std::endl;
		int* d = pool.construct(63);
		std::cout << "Address of d: " << d << " Value of d: " << *d << std::endl;
		int* e = pool.construct(77);
		std::cout << "Address of e: " << e << " Value of e: " << *e << std::endl;

		int* f = pool.allocate(5);
	}
	
	{
		Pool<long int, 7> pool;

		long int* a = pool.construct(22);
		std::cout << "Address of a: " << a << " Value of a: " << *a << std::endl;
		long int* b = pool.construct(423);
		std::cout << "Address of b: " << b << " Value of b: " << *b << std::endl;
		long int* c = pool.construct(83);
		std::cout << "Address of c: " << c << " Value of c: " << *c << std::endl;
		long int* d = pool.construct(63);
		std::cout << "Address of d: " << d << " Value of d: " << *d << std::endl;
		long int* e = pool.construct(77);
		std::cout << "Address of e: " << e << " Value of e: " << *e << std::endl;

		
		pool.deallocate(d);
		pool.deallocate(c);
		pool.deallocate(e);
		
		long int* f = pool.allocate(3);
	}
	*/
	{
		Pool<long int, 7> pool;
	}


	// Testing pool.deallocate(b, 3) Case: ptr > head (head is changed) 
	{
		Pool<long int, 7> pool;

		long int* a = pool.construct(22);
		std::cout << "Address of a: " << a << " Value of a: " << *a << std::endl;
		long int* b = pool.construct(423);
		std::cout << "Address of b: " << b << " Value of b: " << *b << std::endl;
		long int* c = pool.construct(83);
		std::cout << "Address of c: " << c << " Value of c: " << *c << std::endl;
		long int* d = pool.construct(63);
		std::cout << "Address of d: " << d << " Value of d: " << *d << std::endl;
		long int* e = pool.construct(77);
		std::cout << "Address of e: " << e << " Value of e: " << *e << std::endl;


		pool.deallocate(b, 3);

		long int* f = pool.allocate();

		long int* g = pool.construct(63);
		std::cout << "Address of g: " << g << " Value of g: " << *d << std::endl;
		long int* h = pool.construct(77);
		std::cout << "Address of h: " << h << " Value of h: " << *e << std::endl;
		long int* i = pool.construct(63);
		std::cout << "Address of j: " << i << " Value of i: " << *i << std::endl;
		long int* j = pool.construct(77);
		std::cout << "Address of j: " << j << " Value of j: " << *j << std::endl;
	}
	

	// Testing pool.deallocate(b, 3) Case: ptr < head (head is changed) 
	{
		Pool<long int, 7> pool;

		long int* a = pool.construct(22);
		std::cout << "Address of a: " << a << " Value of a: " << *a << std::endl;
		long int* b = pool.construct(423);
		std::cout << "Address of b: " << b << " Value of b: " << *b << std::endl;
		long int* c = pool.construct(83);
		std::cout << "Address of c: " << c << " Value of c: " << *c << std::endl;
		long int* d = pool.construct(63);
		std::cout << "Address of d: " << d << " Value of d: " << *d << std::endl;
		long int* e = pool.construct(77);
		std::cout << "Address of e: " << e << " Value of e: " << *e << std::endl;


		pool.deallocate(b);

		pool.deallocate(d, 3);

		long int* f = pool.allocate();

		long int* g = pool.construct(63);
		std::cout << "Address of g: " << g << " Value of g: " << *d << std::endl;
		long int* h = pool.construct(77);
		std::cout << "Address of h: " << h << " Value of h: " << *e << std::endl;
		long int* i = pool.construct(63);
		std::cout << "Address of j: " << i << " Value of i: " << *i << std::endl;
		long int* j = pool.construct(77);
		std::cout << "Address of j: " << j << " Value of j: " << *j << std::endl;
	}


	return 0;
}
