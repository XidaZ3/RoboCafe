#ifndef VETTORE_H
#define VETTORE_H

#include <iostream>
#include <math.h>

template <class T> class vector;

template <class T>
std::ostream& operator<< (std::ostream& os, const vector<T>& val);

template <class T>
class vector
{
    friend std::ostream& operator<< <T>(std::ostream& os, const vector<T>& val);
    private:
    class iterator{
        friend class vector<T>;
        public:
            T* ptr;
            iterator();
            iterator(T* p);
            iterator(const iterator& other);
            iterator& operator++ ();
            iterator operator++ (int);
            bool operator==(const iterator& other) const;
            iterator& operator= (const iterator& other);
            T& operator* ()const;
            T* operator-> ()const;

    };
    unsigned int occupied, available;
    T *arr;
    iterator first, last;
    static T* copia(const T* other, unsigned int occupied, unsigned int available);
    static void distruggi(const T* other);
    static int spaceNeeded(const unsigned int k);

    public:
    vector<T>(unsigned int k=0, const T& val= T());
    ~vector<T>();
    vector<T>(const vector<T>& other);
    vector<T>& operator=(const vector<T>& other);
    vector<T> operator+(const vector<T>& other) const;
    bool operator==(const vector<T>& other) const;
    bool operator<(const vector<T>& other)const ;
    T& operator[](unsigned int k)const;
    vector<T>& append(const vector<T>& other);
    unsigned int getSize() const;
    unsigned int getAvailable() const;
    void push_back(const T& value);
    T& pop();
    T& erase(unsigned int index);
    void insert(T& value, unsigned int index);
    unsigned int find(const T& value)const;
    static iterator begin();
    static iterator end();
};



#endif // VETTORE_H
