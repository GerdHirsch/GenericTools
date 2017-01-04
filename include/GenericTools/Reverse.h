/*
 * DemoInterfaceParameterpack.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */

#ifndef REVERSE_H_
#define REVERSE_H_


#include <GenericTools/Typelist2Parameterpack.h>
#include <GenericTools/Parameterpack.h>
#include <GenericTools/MakeTypelist.h>


template<class ...Pack>
struct Reverse_{
	using typelist = MakeTypelist<Pack...>;
	using reverseList = typename Loki::TL::Reverse<typelist>::Result;
	using type = TL2PP<reverseList>;
};
template<class ...Pack>
struct Reverse_<Parameterpack<Pack...>> : Reverse_<Pack...>{};

template<class ...pack>
using Reverse = typename Reverse_<pack...>::type;

#endif /* REVERSE_H_ */
