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

/**
 * Widget is a variadic template which creates a member for each type in pack
 */
//forward declaration
template<class ...pack>
struct WidgetImpl;

template<class ...pack>
struct WidgetImpl{
	WidgetImpl(){
		std::cout << "WidgetImpl<class ...pack>::WidgetImpl() // empty pack" << std::endl;
	}
	void print(){
		std::cout << "WidgetImpl<class ...pack>::print()" << std::endl;
	}
};

template<class T, class ...pack>
struct WidgetImpl<T, pack...> : WidgetImpl<pack...>{
	T t;
	using base_type = WidgetImpl<pack...>;
	WidgetImpl(){
		std::cout << "WidgetImpl<T, pack...>::WidgetImpl() // Two ore more Types" << std::endl;
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
		std::cout << "WidgetImpl<T>::WidgetImpl() // one Type" << std::endl;
	}
	void print(){
		t.print();
	}
};

template<class ...pack>
struct CreateWidget{
	using type = WidgetImpl<pack...>;
};

template<class ...pack> // delegation by inheritance
struct CreateWidget<Typepack<pack...>> : CreateWidget<pack...>{};

template<class ...pack>
using Widget = typename CreateWidget<pack...>::type;

#endif /* WIDGET_H_ */
