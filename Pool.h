#pragma once

template<typename T, int N> class Pool {
public:

    Pool() {
        T* block = new T[N];
        begin = block;
        head = block;
        used = 0;
    }

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
    T* block;
    T* begin;
    T* head;
    int used;

};