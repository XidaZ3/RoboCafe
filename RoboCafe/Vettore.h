#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <math.h>

template <class T> class Vettore;

template <class T>
std::ostream& operator<< (std::ostream& os, const Vettore<T>& val);

template <class T>
class Vettore
{
    friend std::ostream& operator<< <T>(std::ostream& os, const Vettore<T>& val);
    private:
    class iterator{
        friend class Vettore<T>;
        public:
            T* ptr;
            iterator();
            iterator(T* p);
            iterator(const iterator& other);
            iterator& operator++ ();
            iterator operator++ (int);
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;
            iterator& operator= (const iterator& other);
            T& operator* ()const;
            T* operator-> ()const;

    };
    unsigned int available;
    T *arr;
    unsigned int occupied;
    T* first,* last;
    static T* copia(const T* other, unsigned int occupied, unsigned int available);
    static void distruggi(const T* other);
    static int spaceNeeded(const unsigned int k);

    public:
    Vettore<T>(unsigned int k=0, const T& val= T());
    ~Vettore<T>();
    Vettore<T>(const Vettore<T>& other);
    Vettore<T>& operator=(const Vettore<T>& other);
    Vettore<T> operator+(const Vettore<T>& other) const;
    bool operator==(const Vettore<T>& other) const;
    bool operator<(const Vettore<T>& other)const ;
    T& operator[](unsigned int k)const;
    Vettore<T>& append(const Vettore<T>& other);
    void resize(unsigned int value);
    unsigned int getSize() const;
    unsigned int getCapacity() const;
    void push_back(const T& value);
    T& pop();
    T& erase(unsigned int index);
    void insert(T& value, unsigned int index);
    unsigned int find(const T& value)const;
    iterator begin() const;
    iterator end() const;
};

template <class T>
unsigned int Vettore<T>::getCapacity() const{
    return available;
}

template <class T>
int Vettore<T>::spaceNeeded(const unsigned int k){
    return pow(2,ceil(log2(k)));
}

template <class T>
Vettore<T>::Vettore(unsigned int k, const T& init) : available(spaceNeeded(k)),arr(k ? new T[available] : nullptr), occupied(k) {
    first = arr;
    for(unsigned int i=0;i<occupied; i++)
    {
        arr[i]=init;
    }
    last = first ? &(arr[occupied]) : nullptr;
}

template <class T>
Vettore<T>::~Vettore() {
    if(arr) delete[] arr;
    first = last = nullptr;
}

template <class T>
Vettore<T>::Vettore(const Vettore& other) : available(other.available) , occupied(other.occupied){
    delete[] arr;
    arr = other.occupied? new T[other.available]:nullptr;
    first = arr;
    for(int i=0;i<occupied; i++)
    {
        arr[i]=other[i];
    }
    last = first ? &(arr[occupied]) : nullptr;
}

template <class T>
Vettore<T>& Vettore<T>::operator=(const Vettore& other) {
    if(this  != &other)
    {
        delete [] arr;
        occupied = other.occupied;
        available = other.available;
        arr = (occupied ? new T[available]: nullptr);
        first = arr;
        for(unsigned int i=0;i<occupied; i++)
        {
            arr[i]=other[i];
        }
        last = first ? &(arr[occupied]) : nullptr;
    }
    return *this;
}

template <class T>
Vettore<T> Vettore<T>::operator+(const Vettore& other) const {
    Vettore<T> aux(*this);
    aux.append(other);
    return aux;
}

template <class T>
bool Vettore<T>::operator==(const Vettore<T>& other)const {
    if(this == &other) return true;
    if(occupied != other.occupied || available != other.available) return false;
    for(int i=0; i<occupied; i++){
        if(arr[i]!=other[i]) return false;
    } return true;
}

template <class T>
T& Vettore<T>::operator[](unsigned int k)const {
    return *(arr+k);
}

template <class T>
void Vettore<T>::resize(unsigned int value){
    if(value){
        Vettore<T>* aux = new Vettore<T>(*this);
        aux->available = spaceNeeded(value);
        *this = *aux;
    }
}

template <class T>
Vettore<T>& Vettore<T>::append(const Vettore<T>& other){
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
        first = arr;
        last = arr+occupied;
    }
    return *this;
}

template <class T>
T* Vettore<T>::copia(const T* other, unsigned int occupied, unsigned int available){
    if(other !=nullptr)
    {
        T* ret = new T[available];
        for(unsigned int i = 0; i<occupied; i++)
            ret[i] = other[i];
        return ret;
    }else return nullptr;
}

template <class T>
void Vettore<T>::distruggi(const T* other){
    delete[] other;
}

template <class T>
unsigned int Vettore<T>::getSize()const {return occupied;}

template <class T>
std::ostream& operator<< (std::ostream& os, const Vettore<T>& val){
    if(val.getSize() == 0) return os<< "[]";
    else{
        os<< "[";
        for(unsigned int i=0;i<val.getSize();++i)
        {
            os<<val[i]<< (i != val.getSize()-1 ? ',': ']');
        }
        return os;
    }
}

template <class T>
Vettore<T>::iterator::iterator():ptr(nullptr){}
template <class T>
Vettore<T>::iterator::iterator(T* p):ptr(p){}
template <class T>
Vettore<T>::iterator::iterator(const Vettore<T>::iterator& other):ptr(other.ptr){}
template <class T>
typename Vettore<T>::iterator& Vettore<T>::iterator::operator++ (){
    if(ptr!= nullptr) {
        ptr++;
        return *this;
    }

}
template <class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator++ (int){
    if(ptr!= nullptr){
        auto ret = Vettore<T>::iterator(*this);
        ptr++;
        return ret;
    }

}
template <class T>
bool Vettore<T>::iterator::operator==(const Vettore<T>::iterator& other)const{
    return (ptr == other.ptr);
}
template <class T>
bool Vettore<T>::iterator::operator!=(const Vettore<T>::iterator& other)const{
    return (ptr != other.ptr);
}
template <class T>
typename Vettore<T>::iterator& Vettore<T>::iterator::operator= (const Vettore<T>::iterator& other){
    if(this != &other)
    {
        ptr = other.ptr;
    }return *this;
}
template <class T>
T& Vettore<T>::iterator::operator* ()const{
    return *ptr;
}
template <class T>
T* Vettore<T>::iterator::operator-> ()const{
    return &(*ptr);
}

template <class T>
void Vettore<T>::push_back(const T& value){
    if(occupied <available){
        arr[occupied]=value;
        occupied++;
    }
}
template <class T>
T& Vettore<T>::pop(){
    T* ret = new T();
    if(occupied){
        occupied--;
        ret = &(arr[occupied]);
    }
    return *ret;
}
template <class T>
T& Vettore<T>::erase(unsigned int index){
    T* ret = new T(arr[index]);
    for(unsigned int i= index; i<occupied; i++){
        arr[i]=arr[i+1];
    }
    occupied --;
    return *ret;
}
template <class T>
void Vettore<T>::insert(T& value, unsigned int index){
    if(occupied<available)
        arr[occupied+1]=arr[occupied];
    for(unsigned int i = occupied; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = value;
}
template <class T>
unsigned int Vettore<T>::find(const T& value)const{
    for(unsigned int i=0; i<occupied; i++)
        if(arr[i]== value) return i;
    return -1;
}
template <class T>
typename Vettore<T>::iterator Vettore<T>::begin() const{
    std::cout<<"Begin: "<<&first<<"  "<<first<<std::endl;
    return iterator(first);
}
template <class T>
typename Vettore<T>::iterator Vettore<T>::end() const {
    if(!last) return iterator();
    return iterator(last+1);
}


#endif // VETTORE_H
