# Memory-Management
Heap memory pool allocator in cpp

Current commands required to execute:  

$ g++ -o main main.cpp -g -Werror  
$ ./main  

*Fix Notes:*  
-Segmentation fault fixed (destructor was delete[]-ing wrong T* block pointer)
