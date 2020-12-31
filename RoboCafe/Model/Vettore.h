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

    unsigned int available;
    T *arr;
    unsigned int occupied;
    T* first,* last;
    static T* copia(const T* other, unsigned int occupied, unsigned int available);
    static void distruggi(const T* other);
    static int spaceNeeded(const unsigned int k);

    public:
    class iterator{
        friend class Vettore<T>;
        public:
            T* ptr;
            iterator();
            iterator(T* p);
            iterator(const iterator& other);
            iterator& operator++ ();
            iterator operator++ (int);
            iterator& operator-- ();
            iterator operator--(int);
            bool operator==(const iterator& other) const;
            bool operator!=(const iterator& other) const;
            const iterator &operator+(int i);
            iterator& operator= (const iterator& other);
            T& operator* ()const;
            T* operator-> ()const;

    };

    class const_iterator{
        friend class Vettore<T>;
        public:
            const T* ptr;
            const_iterator();
            const_iterator(T* p);
            const_iterator(const const_iterator& other);
            const_iterator(const iterator& other);
            const_iterator& operator++ ();
            const_iterator operator++ (int);
            const_iterator& operator-- ();
            const_iterator operator--(int);
            bool operator==(const const_iterator& other) const;
            bool operator!=(const const_iterator& other) const;
            const_iterator& operator+(int i);
            const_iterator& operator= (const const_iterator& other);
            const T& operator* ()const;
            const T* operator-> ()const;

    };



    Vettore<T>(unsigned int k=0);
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
    const T& back() const;
    const T& front() const;
    T& erase(unsigned int index);
    const T& erase(iterator &it);
    void clear();
    void insert(T& value, unsigned int index);
    unsigned int find(const T& value)const;

    T* data();
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
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
Vettore<T>::Vettore(unsigned int k) : available(spaceNeeded(k)),arr(k ? new T[available] : nullptr), occupied(0) {
    last = first = arr;
}

template <class T>
Vettore<T>::~Vettore() {
    if(arr) delete[] arr;
    first = last = nullptr;
}

template <class T>
Vettore<T>::Vettore(const Vettore& other) : available(other.available) ,arr(other.available != 0 ? new T[available] : nullptr), occupied(other.occupied){
    last =first = arr;
    for(unsigned int i=0;i<occupied; i++)
    {
        arr[i]=other[i];
        last++;
    }
}

template <class T>
Vettore<T>& Vettore<T>::operator=(const Vettore& other) {
    if(this  != &other)
    {
        delete [] arr;
        occupied = other.occupied;
        available = other.available;
        arr = (available ? new T[available]: nullptr);
        last = first = arr;
        for(unsigned int i=0;i<occupied; i++)
        {
            arr[i]=other[i];
            last++;
        }
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
        available = spaceNeeded(value);
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
typename Vettore<T>::iterator& Vettore<T>::iterator::operator+(int i)
{
    ptr=ptr+i;
    return *this;
}
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
template<class T>
typename Vettore<T>::iterator &Vettore<T>::iterator::operator--()
{
    if(ptr!= nullptr) {
        ptr--;
        return *this;
    }
}

template<class T>
typename Vettore<T>::iterator Vettore<T>::iterator::operator--(int)
{
    if(ptr!= nullptr){
        auto ret = Vettore<T>::iterator(*this);
        ptr--;
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
Vettore<T>::const_iterator::const_iterator():ptr(nullptr){}
template <class T>
Vettore<T>::const_iterator::const_iterator(T* p):ptr(p){}
template <class T>
Vettore<T>::const_iterator::const_iterator(const Vettore<T>::const_iterator& other):ptr(other.ptr){}
template<class T>
Vettore<T>::const_iterator::const_iterator(const Vettore<T>::iterator &other):ptr(other.ptr){}
template <class T>
typename Vettore<T>::const_iterator& Vettore<T>::const_iterator::operator+(int i)
{
    ptr=ptr+i;
    return *this;
}
template <class T>
typename Vettore<T>::const_iterator& Vettore<T>::const_iterator::operator++ (){
    if(ptr!= nullptr) {
        ptr++;
        return *this;
    }

}
template <class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator++ (int){
    if(ptr!= nullptr){
        auto ret = Vettore<T>::const_iterator(*this);
        ptr++;
        return ret;
    }
}
template<class T>
typename Vettore<T>::const_iterator &Vettore<T>::const_iterator::operator--()
{
    if(ptr!= nullptr) {
        ptr--;
        return *this;
    }
}

template<class T>
typename Vettore<T>::const_iterator Vettore<T>::const_iterator::operator--(int)
{
    if(ptr!= nullptr){
        auto ret = Vettore<T>::const_iterator(*this);
        ptr--;
        return ret;
    }
}


template <class T>
bool Vettore<T>::const_iterator::operator==(const Vettore<T>::const_iterator& other)const{
    return (ptr == other.ptr);
}
template <class T>
bool Vettore<T>::const_iterator::operator!=(const Vettore<T>::const_iterator& other)const{
    return (ptr != other.ptr);
}
template <class T>
typename Vettore<T>::const_iterator& Vettore<T>::const_iterator::operator= (const Vettore<T>::const_iterator& other){
    if(this != &other)
    {
        ptr = other.ptr;
    }return *this;
}
template <class T>
const T& Vettore<T>::const_iterator::operator* ()const{
    return *ptr;
}
template <class T>
const T* Vettore<T>::const_iterator::operator-> ()const{
    return &(*ptr);
}

template <class T>
void Vettore<T>::push_back(const T& value){
    if(occupied <available){
        arr[occupied]=value;
        occupied++;
        last++;
    }else{
        resize(available+1);
        arr[occupied]=value;
        occupied++;
        last++;
    }
}
template <class T>
T& Vettore<T>::pop(){
    T* ret;
    if(occupied){
        ret = new T(arr[occupied-1]);
        occupied--;
        last--;
    }
    return *ret;
}

template<class T>
const T &Vettore<T>::back() const
{
    return *(last-1);
}

template<class T>
const T &Vettore<T>::front() const
{
    return *first;
}

template <class T>
T& Vettore<T>::erase(unsigned int index){
    if(index<occupied){
        T* ret = new T(arr[index]);
        for(unsigned int i= index; i<occupied-1; i++){
            arr[i]=arr[i+1];
        }
        occupied --;
        last --;
        return *ret;
    }
}

template<class T>
const T &Vettore<T>::erase(Vettore::iterator &it)
{
    occupied --;
    last --;
    for(Vettore<T>::iterator i= it; i!=end(); i++){
        *(i.ptr)=*(i.ptr+1);
    }
}

template<class T>
void Vettore<T>::clear()
{
    if(arr){
        while(occupied){
            pop();
        }
        last = first = arr;
    }
}
template <class T>
void Vettore<T>::insert(T& value, unsigned int index){
    if(occupied<available)
        arr[occupied+1]=arr[occupied];
    for(unsigned int i = occupied; i>index; i--)
        arr[i] = arr[i-1];
    arr[index] = value;
    last ++;
}
template <class T>
unsigned int Vettore<T>::find(const T& value)const{
    for(unsigned int i=0; i<occupied; i++)
        if(arr[i]== value) return i;
    return -1;
}

template<class T>
T *Vettore<T>::data()
{
    return arr;
}
template <class T>
typename Vettore<T>::const_iterator Vettore<T>::begin() const{
    return const_iterator(first);
}
template <class T>
typename Vettore<T>::const_iterator Vettore<T>::end() const {
    if(!last) return const_iterator();
    return const_iterator(last);
}
template <class T>
typename Vettore<T>::iterator Vettore<T>::begin(){
    return iterator(first);
}
template <class T>
typename Vettore<T>::iterator Vettore<T>::end() {
    if(!last) return iterator();
    return iterator(last);
}

#endif // VETTORE_H




