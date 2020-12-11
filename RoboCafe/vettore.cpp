#include <iostream>
#include "vettore.h"
#include <math.h>

template <class T>
unsigned int vector<T>::getAvailable() const{
    return available;
}

template <class T>
int vector<T>::spaceNeeded(const unsigned int k){
    return pow(2,ceil(log2(k)));
}

template <class T>
vector<T>::vector(unsigned int k, const T& init) : available(spaceNeeded(k)),arr(k ? new T[available] : nullptr), occupied(k) {
    for(int i=0;i<occupied; i++)
    {
        arr[i]=init;
    }
}

template <class T>
vector<T>::~vector() {
    if(arr) delete[] arr;
}

template <class T>
vector<T>::vector(const vector& other) : available(other.available), arr( other.occupied? new T[other.available]:nullptr) , occupied(other.occupied){
    for(int i=0;i<occupied; i++)
    {
        arr[i]=other[i];
    }
}

template <class T>
vector<T>& vector<T>::operator=(const vector& other) {
    if(this  != &other)
    {
        delete [] arr;
        occupied = other.occupied;
        available = other.available;
        arr = (occupied ? new T[available]: nullptr);
        for(int i=0;i<occupied; i++)
        {
            arr[i]=other[i];
        }
    }
    return *this;
}

template <class T>
vector<T> vector<T>::operator+(const vector& other) const {
    vector<T> aux(*this);
    aux.append(other);
    return aux;
}

template <class T>
bool vector<T>::operator==(const vector<T>& other)const {
    if(this == &other) return true;
    if(occupied != other.occupied || available != other.available) return false;
    for(int i=0; i<occupied; i++){
        if(arr[i]!=other[i]) return false;
    } return true;
}

template <class T>
T& vector<T>::operator[](unsigned int k)const {
    return *(arr+k);
}

template <class T>
vector<T>& vector<T>::append(const vector<T>& other){
    if(other.occupied != 0){
        T* ret = new T[available = spaceNeeded(occupied+other.occupied)];
        for(unsigned int i=0; i<occupied; ++i){
            ret[i] = arr[i];
        }
        for(unsigned int i=0; i<other.occupied; ++i){
            ret[occupied+i] = other[i];
        }
        occupied +=other.occupied;
        delete [] arr;
        arr = ret;
    }
    return *this;
}

template <class T>
T* vector<T>::copia(const T* other, unsigned int occupied, unsigned int available){
    if(other !=nullptr)
    {
        T* ret = new T[available];
        for(unsigned int i = 0; i<occupied; i++)
            ret[i] = other[i];
        return ret;
    }else return nullptr;
}

template <class T>
void vector<T>::distruggi(const T* other){
    delete[] other;
}

template <class T>
unsigned int vector<T>::getSize()const {return occupied;}

template <class T>
std::ostream& operator<< (std::ostream& os, const vector<T>& val){
    if(val.getSize() == 0) return os<< "[]";
    else{
        os<< "[";
        for(int i=0;i<val.getSize();++i)
        {
            os<<val[i]<< (i != val.getSize()-1 ? ',': ']');
        }
        return os;
    }
}

template <class T>
vector<T>::iterator::iterator():ptr(nullptr){}
template <class T>
vector<T>::iterator::iterator(T* p):ptr(p){}
template <class T>
vector<T>::iterator::iterator(const vector<T>::iterator& other):ptr(other.ptr){}
template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator++ (){
    if(ptr!= nullptr) {
        ptr++;
        return *this;
    }

}
template <class T>
typename vector<T>::iterator vector<T>::iterator::operator++ (int){
    if(ptr!= nullptr){
        auto ret = vector<T>::iterator(*this);
        ptr++;
        return ret;
    }

}
template <class T>
bool vector<T>::iterator::operator==(const vector<T>::iterator& other)const{
    return (ptr == other.ptr);
}
template <class T>
typename vector<T>::iterator& vector<T>::iterator::operator= (const vector<T>::iterator& other){
    if(this != &other)
    {
        ptr = other.ptr;
    }return *this;
}
template <class T>
T& vector<T>::iterator::operator* ()const{
    return *ptr;
}
template <class T>
T* vector<T>::iterator::operator-> ()const{
    return &(*ptr);
}

template <class T>
void vector<T>::push_back(const T& value){
    if(occupied <available){
        arr[occupied]=value;
        occupied++;
    }
}
template <class T>
T& vector<T>::pop(){
    return arr[occupied];
    occupied--;
}
template <class T>
T& vector<T>::erase(unsigned int index){
    T* ret = new T(arr[index]);
    for(unsigned int i= index; i<occupied; i++){
        arr[i]=arr[i+1];
    }
    occupied --;
    return *ret;
}
template <class T>
void vector<T>::insert(T& value, unsigned int index){
    if(occupied<available)
        arr[occupied+1]=arr[occupied];
    for(unsigned int i = occupied; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = value;
}
template <class T>
unsigned int vector<T>::find(const T& value)const{
    for(unsigned int i=0; i<occupied; i++)
        if(arr[i]== value) return i;
    return -1;
}
template <class T>
typename vector<T>::first =
template <class T>
static typename vector<T>::iterator begin(){

}
template <class T>
static typename vector<T>::iterator end(){

}
