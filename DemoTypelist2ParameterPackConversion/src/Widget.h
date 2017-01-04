/*
 * Widget.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */

#ifndef WIDGET_H_
#define WIDGET_H_


#include <GenericTools/Parameterpack.h>
#include <iostream>

template<class ...pack>
struct Widget{
	Widget(){
		std::cout << "Widget<class ...pack>::Widget() // empty pack" << std::endl;
	}
	void print(){
		std::cout << "Widget<class ...pack>::print()" << std::endl;
	}
};

template<class T, class ...pack>
struct Widget<T, pack...> : Widget<pack...>{
	T t;
	using base_type = Widget<pack...>;
	Widget(){
		std::cout << "Widget<T, pack...>::Widget() // Two ore more Types" << std::endl;
	}
	void print(){
		base_type::print();
		t.print();
	}
};
template<class T>
struct Widget<T>{
	T t;
	Widget(){
		std::cout << "Widget<T>::Widget() // one Type" << std::endl;
	}
	void print(){
		t.print();
	}
};
// standard implementation to enable Parameterpack
template<class ...pack>
struct Widget<Parameterpack<pack...>> : Widget<pack...>{};



#endif /* WIDGET_H_ */
