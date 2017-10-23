//#include "DynamicArray.h"
//
//DynamicVector::DynamicVector(int capacity)
//{
//	this->length = 0;
//	this->capacity = capacity;
//	this->elems = new TElement[capacity];
//}
//
//DynamicVector::DynamicVector(const DynamicVector & v)
//{
//	this->length = v.length;
//	this->capacity = v.capacity;
//	this->elems = new TElement[this->capacity];
//	for (int i = 0; i < this->length; i++)
//	{
//		this->elems[i] = v.elems[i];
//	}
//}
//
//DynamicVector::~DynamicVector()
//{
//	delete[] this->elems;
//}
//
//DynamicVector & DynamicVector::operator=(const DynamicVector & v)
//{
//	if (this == &v)
//	{
//		return *this;
//	}
//	this->length = v.length;
//	this->capacity = v.capacity;
//	delete[] this->elems;
//	this->elems = new TElement[this->capacity];
//	for (int i = 0; i < this->length; i++)
//	{
//		this->elems[i] = v.elems[i];
//	}
//	return *this;
//}
//
//void DynamicVector::add(const TElement & e)
//{
//	if (this->length == this->capacity)
//	{
//		this->resize();
//	}
//	this->elems[this->length] = e;
//	this->length++;
//}
//
//int DynamicVector::getLength() const
//{
//	return this->length;
//}
//
//TElement * DynamicVector::getAllElems() const
//{
//	return this->elems;
//}
//
//void DynamicVector::resize(double factor)
//{
//	this->capacity *= static_cast<int>(factor);
//	TElement* els = new TElement[this->capacity];
//	for (int i = 0; i < this->length; i++)
//		els[i] = this->elems[i];
//	delete[] this->elems;
//	this->elems = els;
//}
