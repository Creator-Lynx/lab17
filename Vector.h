#ifndef _VECTOR_
#define _VECTOR_ 


template <class T>
class vector {
private:
	T* _head;
	size_t _size;
	size_t _capacity;
public:
	vector(size_t size = 0, const T& value = T());
	vector(vector<T>& r);
	~vector();                                         //a.operator=(b);
	vector<T>& operator=(const vector<T>& r);//a = b = c; a.operator=( b.operator=(c));
	void push_back(const T& value);
	size_t size() const; 
	//vector<T> a(50);
	int b = a.size();
	T& operator[](size_t i) const;   // vector<T> a(15); T b = a.at(3);
	T& at(size_t i) const;	//(бросает исключения)
	void insert(size_t i, const T& value); //(бросает исключения)
	void erase(size_t i); //(бросает исключения)
	
};

#endif // !_VECTOR_
