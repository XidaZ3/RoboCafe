#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Model/Vettore.h"
#include <stdlib.h>
#include <iostream>

template <class T>
class CustomListWidget : public QWidget
{
private:
    QVBoxLayout* mainLayout;
    Vettore<T> vettoreItemWidget;
    T* first, *last;

    void aggiungiWidget();
    void pulisciLayout();
public:
    explicit CustomListWidget(QWidget *parent = nullptr);
    ~CustomListWidget();
    CustomListWidget(const CustomListWidget& other);
    CustomListWidget& operator= (const CustomListWidget& other);
    void addItem(T value);
    T& getItem(int index);
    unsigned int getSize()const;
    void resize(int value);

    class iterator{
        friend class CustomListWidget;
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
    iterator begin() const;
    iterator end() const;
    unsigned int iteratorToIndex(iterator it) const;

};
template <class T>
void CustomListWidget<T>::aggiungiWidget()
{
    //pulisciLayout();
    for(auto i : vettoreItemWidget)
    {
        mainLayout->addWidget(i);
        last++;
    }
}
template <class T>
void CustomListWidget<T>::pulisciLayout()
{
    QLayoutItem* item;
    while ( ( item = mainLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
        last--;
    }
}
template <class T>
CustomListWidget<T>::CustomListWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    setLayout(mainLayout);
    vettoreItemWidget = Vettore<T>();
    first = last = vettoreItemWidget.data();
}
template <class T>
CustomListWidget<T>::~CustomListWidget()
{
    if(mainLayout)
        delete mainLayout;
    first = nullptr;
    last = nullptr;
}
template <class T>
CustomListWidget<T>::CustomListWidget(const CustomListWidget &other):QWidget(other.parentWidget()),vettoreItemWidget(other.vettoreItemWidget){
    first = last =vettoreItemWidget.data();
    pulisciLayout();
    aggiungiWidget();
}
template <class T>
CustomListWidget<T> &CustomListWidget<T>::operator=(const CustomListWidget<T> &other)
{
    if(this != & other){
        vettoreItemWidget = Vettore<T>(other.vettoreItemWidget);
        first = last = vettoreItemWidget.data();
        pulisciLayout();
        aggiungiWidget();
    }
    return *this;
}
template <class T>
unsigned int CustomListWidget<T>::getSize() const
{
    return vettoreItemWidget.getSize();
}
template <class T>
void CustomListWidget<T>::resize(int value)
{
    vettoreItemWidget.resize(value);
    first = vettoreItemWidget.data();
    last = getSize()? &vettoreItemWidget[getSize()-1]:first;
}
template <class T>
void CustomListWidget<T>::addItem(T value)
{
    vettoreItemWidget.push_back(value);
    aggiungiWidget();
}
template <class T>
T& CustomListWidget<T>::getItem(int index)
{
    return vettoreItemWidget[index];
}
template <class T>
CustomListWidget<T>::iterator::iterator():ptr(nullptr){}
template <class T>
CustomListWidget<T>::iterator::iterator(T* p):ptr(p){}
template <class T>
CustomListWidget<T>::iterator::iterator(const CustomListWidget<T>::iterator& other):ptr(other.ptr){}
template <class T>
typename CustomListWidget<T>::iterator& CustomListWidget<T>::iterator::operator++ (){
    if(ptr!= nullptr) {
        ptr++;
        return *this;
    }

}
template <class T>
typename CustomListWidget<T>::iterator CustomListWidget<T>::iterator::operator++ (int){
    if(ptr!= nullptr){
        auto ret = CustomListWidget<T>::iterator(*this);
        ptr++;
        return ret;
    }
}
template <class T>
bool CustomListWidget<T>::iterator::operator==(const CustomListWidget<T>::iterator& other)const{
    return (ptr == other.ptr);
}
template <class T>
bool CustomListWidget<T>::iterator::operator!=(const CustomListWidget<T>::iterator& other)const{
    return (ptr != other.ptr);
}
template <class T>
typename CustomListWidget<T>::iterator& CustomListWidget<T>::iterator::operator= (const CustomListWidget<T>::iterator& other){
    if(this != &other)
    {
        ptr = other.ptr;
    }return *this;
}
template <class T>
T& CustomListWidget<T>::iterator::operator* ()const{
    return *ptr;
}
template <class T>
T* CustomListWidget<T>::iterator::operator-> ()const{
    return &(*ptr);
}
template<class T>
unsigned int CustomListWidget<T>::iteratorToIndex(CustomListWidget<T>::iterator it) const
{
    return it.ptr - first;
}
template <class T>
typename CustomListWidget<T>::iterator CustomListWidget<T>::begin() const{
    return iterator(first);
}
template <class T>
typename CustomListWidget<T>::iterator CustomListWidget<T>::end() const {
    if(!last) return iterator();
    return iterator(last);
}

#endif // CUSTOMLISTWIDGET_H
