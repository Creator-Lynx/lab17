#ifndef _VECTOR_
#define _VECTOR_ 
typedef unsigned int size_t;

template <class T>
class vector {
private:
	T* _head;
	size_t _size;
	size_t _capacity;
public:
	vector();

	vector(size_t size);
	vector(size_t size, const T& value);
	vector(vector<T>& r);
	~vector();                                         //a.operator=(b);
	vector<T>& operator=(const vector<T>& r);//a = b = c; a.operator=( b.operator=(c));
	void push_back(const T& value);
	size_t size(); 
	const T& operator[](size_t i) const;  
	const T& at(size_t i) const;	//(бросает исключения)
	void insert(size_t i, const T& value); //(бросает исключения)
	void erase(size_t i); //(бросает исключения)
	
};

#include "Vector.ipp"



#endif // !_VECTOR_
