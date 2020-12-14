#include <iostream>
#include "vettore.h"
#include <math.h>

template <class T>
unsigned int vettore<T>::getAvailable() const{
    return available;
}

template <class T>
int vettore<T>::spaceNeeded(const unsigned int k){
    return pow(2,ceil(log2(k)));
}

template <class T>
vettore<T>::vettore(unsigned int k, const T& init) : available(spaceNeeded(k)),arr(k ? new T[available] : nullptr), occupied(k) {
    first = arr;
    for(int i=0;i<occupied; i++)
    {
        arr[i]=init;
    }
    last = &(arr[occupied]);
}

template <class T>
vettore<T>::~vettore() {
    if(arr) delete[] arr;
    first = last = nullptr;
}

template <class T>
vettore<T>::vettore(const vettore& other) : available(other.available) , occupied(other.occupied){
    delete[] arr;
    arr = other.occupied? new T[other.available]:nullptr;
    first = arr;
    for(int i=0;i<occupied; i++)
    {
        arr[i]=other[i];
    }
    last = &(arr[occupied]);
}

template <class T>
vettore<T>& vettore<T>::operator=(const vettore& other) {
    if(this  != &other)
    {
        delete [] arr;
        occupied = other.occupied;
        available = other.available;
        arr = (occupied ? new T[available]: nullptr);
        first = arr;
        for(int i=0;i<occupied; i++)
        {
            arr[i]=other[i];
        }
        last = &(arr[occupied]);
    }
    return *this;
}

template <class T>
vettore<T> vettore<T>::operator+(const vettore& other) const {
    vettore<T> aux(*this);
    aux.append(other);
    return aux;
}

template <class T>
bool vettore<T>::operator==(const vettore<T>& other)const {
    if(this == &other) return true;
    if(occupied != other.occupied || available != other.available) return false;
    for(int i=0; i<occupied; i++){
        if(arr[i]!=other[i]) return false;
    } return true;
}

template <class T>
T& vettore<T>::operator[](unsigned int k)const {
    return *(arr+k);
}

template <class T>
vettore<T>& vettore<T>::append(const vettore<T>& other){
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
        last = &(arr+occupied);
    }
    return *this;
}

template <class T>
T* vettore<T>::copia(const T* other, unsigned int occupied, unsigned int available){
    if(other !=nullptr)
    {
        T* ret = new T[available];
        for(unsigned int i = 0; i<occupied; i++)
            ret[i] = other[i];
        return ret;
    }else return nullptr;
}

template <class T>
void vettore<T>::distruggi(const T* other){
    delete[] other;
}

template <class T>
unsigned int vettore<T>::getSize()const {return occupied;}

template <class T>
std::ostream& operator<< (std::ostream& os, const vettore<T>& val){
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
vettore<T>::iterator::iterator():ptr(nullptr){}
template <class T>
vettore<T>::iterator::iterator(T* p):ptr(p){}
template <class T>
vettore<T>::iterator::iterator(const vettore<T>::iterator& other):ptr(other.ptr){}
template <class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator++ (){
    if(ptr!= nullptr) {
        ptr++;
        return *this;
    }

}
template <class T>
typename vettore<T>::iterator vettore<T>::iterator::operator++ (int){
    if(ptr!= nullptr){
        auto ret = vettore<T>::iterator(*this);
        ptr++;
        return ret;
    }

}
template <class T>
bool vettore<T>::iterator::operator==(const vettore<T>::iterator& other)const{
    return (ptr == other.ptr);
}
template <class T>
typename vettore<T>::iterator& vettore<T>::iterator::operator= (const vettore<T>::iterator& other){
    if(this != &other)
    {
        ptr = other.ptr;
    }return *this;
}
template <class T>
T& vettore<T>::iterator::operator* ()const{
    return *ptr;
}
template <class T>
T* vettore<T>::iterator::operator-> ()const{
    return &(*ptr);
}

template <class T>
void vettore<T>::push_back(const T& value){
    if(occupied <available){
        arr[occupied]=value;
        occupied++;
    }
}
template <class T>
T& vettore<T>::pop(){
    return arr[occupied];
    occupied--;
}
template <class T>
T& vettore<T>::erase(unsigned int index){
    T* ret = new T(arr[index]);
    for(unsigned int i= index; i<occupied; i++){
        arr[i]=arr[i+1];
    }
    occupied --;
    return *ret;
}
template <class T>
void vettore<T>::insert(T& value, unsigned int index){
    if(occupied<available)
        arr[occupied+1]=arr[occupied];
    for(unsigned int i = occupied; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = value;
}
template <class T>
unsigned int vettore<T>::find(const T& value)const{
    for(unsigned int i=0; i<occupied; i++)
        if(arr[i]== value) return i;
    return -1;
}
template <class T>
typename vettore<T>::iterator vettore<T>::begin() const{
    return new iterator(first);
}
template <class T>
typename vettore<T>::iterator vettore<T>::end() const {
    if(!last) return iterator();
    return iterator(last+1);
}
