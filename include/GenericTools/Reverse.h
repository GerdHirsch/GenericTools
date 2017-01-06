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
struct ReverseImpl{
	using typelist = MakeTypelist<Pack...>;
	using reverseList = typename Loki::TL::Reverse<typelist>::Result;
	using type = TList2TPack<reverseList>;
};
template<class ...Pack>
struct ReverseImpl<Typepack<Pack...>> : ReverseImpl<Pack...>{};

/**
 * Reverse<..> is the interface to the type-function
 */
template<class ...pack>
using Reverse = typename ReverseImpl<pack...>::type;

#endif /* REVERSE_H_ */
