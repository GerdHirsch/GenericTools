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
struct WidgetImpl{
	WidgetImpl(){
		std::cout << "Widget<class ...pack>::Widget() // empty pack" << std::endl;
	}
	void print(){
		std::cout << "Widget<class ...pack>::print()" << std::endl;
	}
};

template<class T, class ...pack>
struct WidgetImpl<T, pack...> : WidgetImpl<pack...>{
	T t;
	using base_type = WidgetImpl<pack...>;
	WidgetImpl(){
		std::cout << "Widget<T, pack...>::Widget() // Two ore more Types" << std::endl;
	}
	void print(){
		base_type::print();
		t.print();
	}
};
template<class T>
struct WidgetImpl<T>{
	T t;
	WidgetImpl(){
		std::cout << "Widget<T>::Widget() // one Type" << std::endl;
	}
	void print(){
		t.print();
	}
};
// standard implementation to enable Parameterpack
template<class ...pack>
struct WidgetImpl<Typepack<pack...>> : WidgetImpl<pack...>{};

#endif /* WIDGET_H_ */
