#ifndef DEEPPTR_H
#define DEEPPTR_H
template <class T>
class DeepPtr {
  public:
    T* ptr;
    DeepPtr(T* p): ptr(p->clone()) {}
    DeepPtr(const DeepPtr& p): ptr(p.ptr->clone()) {}
    DeepPtr& operator=(const DeepPtr& p) {
      if(this != &p) {
            delete ptr;
            ptr = p.ptr->clone();
      }
      return *this;
    }

    T& operator*() const {
      return *ptr;
    }

    T* operator->() const{
      return &(*ptr);
    }

    ~DeepPtr() {delete ptr;}
  };

#endif // DEEPPTR_H
