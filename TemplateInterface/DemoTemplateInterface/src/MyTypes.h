/*
 * MyTypes.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */

#ifndef MYTYPES_H_
#define MYTYPES_H_

#include <iostream>

struct A{
	A(){
		std::cout << "A::A()" << std::endl;
	}
	virtual ~A(){
		std::cout << "A::~A()" << std::endl;
	}
	void print(){
		std::cout << "A::print()" << std::endl;
	}
};
struct B{
	B(){
		std::cout << "B::B()" << std::endl;
	}
	virtual ~B(){
		std::cout << "B::~B()" << std::endl;
	}
	void print(){
		std::cout << "B::print()" << std::endl;
	}
};
struct C{
	C(){
		std::cout << "C::C()" << std::endl;
	}
	virtual ~C(){
		std::cout << "C::~C()" << std::endl;
	}
	void print(){
		std::cout << "C::print()" << std::endl;
	}
};



#endif /* MYTYPES_H_ */
