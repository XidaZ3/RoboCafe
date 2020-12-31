#ifndef DEEPPTR_H
#define DEEPPTR_H
template <class T>
class DeepPtr {
  public:
    T* ptr;
    virtual ~DeepPtr();
    DeepPtr();
    DeepPtr(T* p);
    DeepPtr(const DeepPtr& p);
    DeepPtr& operator=(const DeepPtr& p);

    T& operator*() const;
    T* operator->() const;


  };
template <class T>
DeepPtr<T>::DeepPtr():ptr(nullptr){}

template <class T>
DeepPtr<T>::DeepPtr(T* p): ptr(p->clone()) {}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& p): ptr(p.ptr->clone()) {}

template<class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr& p)
{
    if(this != &p) {
        delete ptr;
        ptr = p.ptr->clone();
    }
    return *this;
 }

template <class T>
DeepPtr<T>::~DeepPtr() {delete ptr;}

template <class T>
T& DeepPtr<T>::operator*() const {
    return *ptr;
}

template <class T>
T* DeepPtr<T>::operator->() const {
    return &(*ptr);
}
#endif // DEEPPTR_H
