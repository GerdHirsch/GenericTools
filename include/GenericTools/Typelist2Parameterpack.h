/*
 * Typelist2Typepack.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 * this (TL2PP<..>) function belongs to Loki and should be defined
 * in namespace Loki::TL
 */

#ifndef INCLUDE_GENERICTOOLS_TYPELIST2PARAMETERPACK_H_
#define INCLUDE_GENERICTOOLS_TYPELIST2PARAMETERPACK_H_

#include "Parameterpack.h"

#include <loki/Typelist.h>
//=============================
// primary template without definition
template<
	class list,
	class ...pack
	>
struct Typelist2Parameterpack;
//=============================
//Interface for type-function TL2PP:=Typelist2Parameterpack
template<class List, class ...Pack>
using TL2PP = typename Typelist2Parameterpack<List, Pack...>::type;
//=============================
// specialization for Typelist = 0 first call
// using emptyTypelist = MakeTypelist<>::type;
// using emptyPack = Typelist2Typepack<emptyTypelist>::type;
template<>
struct Typelist2Parameterpack<Loki::Typelist<Loki::NullType, Loki::NullType>>
{
	using type = Typepack<>;
};
// specialization for Typelist = 1 first call
// using typelist = MakeTypelist<A>::type;
// using pack = Typelist2Typepack<typelist>::type;
template<
	class T1
	>
struct Typelist2Parameterpack<Loki::Typelist<T1, Loki::NullType>>
{
	using type = Typepack<T1>;
};
// specialization for Typelist = 1 second call below
// using type = Typelist2Typepack<Tail, pack_>::type;
template<
	class T1,
	class ...pack
	>
struct Typelist2Parameterpack<Loki::Typelist<T1, Loki::NullType>, Typepack<pack...>>
{
	using type = Typepack<pack..., T1>;
};
// specialization for Typelist > 1 first call
// using pack = Typelist2Typepack<typelist>::type;
template<
	class T1,
	class Tail
	>
struct Typelist2Parameterpack<Loki::Typelist<T1, Tail>>
{
	using pack_ = Typepack<T1>;
	using type = typename Typelist2Parameterpack<Tail, pack_>::type;

};
// specialization for Typelist > 1 second call above
// using type = Typelist2Typepack<Tail, pack_>::type;
template<
	class T1,
	class Tail,
	class ...pack
	>
struct Typelist2Parameterpack<Loki::Typelist<T1, Tail>, Typepack<pack...>>
{
	using pack_ = Typepack<pack..., T1>;
	using type = typename Typelist2Parameterpack<Tail, pack_>::type;

};

#endif // INCLUDE_GENERICTOOLS_TYPELIST2PARAMETERPACK_H_
