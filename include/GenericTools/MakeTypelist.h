/*
 * MakeTypelist.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_GENERICTOOLS_MAKETYPELIST_H_
#define INCLUDE_GENERICTOOLS_MAKETYPELIST_H_

#include "Parameterpack.h"

#include <loki/Typelist.h>

// empty typelist
template<class ...pack>
struct MakeTypelist_{
	typedef typename Loki::Typelist<Loki::NullType, Loki::NullType> type;
};

template<class ...pack> // enables usage with Parameterpack<..>
struct MakeTypelist_<Typepack<pack...>> : MakeTypelist_<pack...>{};

// more than one type
template<class T, class ...List>
struct MakeTypelist_<T, List...>{
	typedef typename MakeTypelist_<List...>::type tail;
	typedef Loki::Typelist<T, tail> type;
};
// one type
template<class T>
struct MakeTypelist_<T>
{
	typedef Loki::Typelist<T, Loki::NullType> type;
};
template<class ...pack>
using MakeTypelist = typename MakeTypelist_<pack...>::type;

#endif /* INCLUDE_GENERICTOOLS_MAKETYPELIST_H_ */
