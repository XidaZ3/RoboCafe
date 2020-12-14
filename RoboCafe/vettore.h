#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

template <class T> class vettore;

template <class T>
std::ostream& operator<< (std::ostream& os, const vettore<T>& val);

template <class T>
class vettore
{
    friend std::ostream& operator<< <T>(std::ostream& os, const vettore<T>& val);
    private:
    class iterator{
        friend class vettore<T>;
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
    T* first,* last;
    static T* copia(const T* other, unsigned int occupied, unsigned int available);
    static void distruggi(const T* other);
    static int spaceNeeded(const unsigned int k);

    public:
    vettore<T>(unsigned int k=0, const T& val= T());
    ~vettore<T>();
    vettore<T>(const vettore<T>& other);
    vettore<T>& operator=(const vettore<T>& other);
    vettore<T> operator+(const vettore<T>& other) const;
    bool operator==(const vettore<T>& other) const;
    bool operator<(const vettore<T>& other)const ;
    T& operator[](unsigned int k)const;
    vettore<T>& append(const vettore<T>& other);
    unsigned int getSize() const;
    unsigned int getAvailable() const;
    void push_back(const T& value);
    T& pop();
    T& erase(unsigned int index);
    void insert(T& value, unsigned int index);
    unsigned int find(const T& value)const;
    iterator begin() const;
    iterator end() const;
};



#endif // VETTORE_H
