/*
 * Typepack.h
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_GENERICTOOLS_PARAMETERPACK_H_
#define INCLUDE_GENERICTOOLS_PARAMETERPACK_H_

/**
 * No Definition is needed, it's just to specialize a template.
 * Primary:
 * template<class ...pack> class Widget{ Definition;};
 * Specialization:
 * template<class ...pack> class Widget<Parameterpack<pack...>
 * : Widget<pack...>{}; // Delegation by inheritance
 */
template<class ...>
struct Typepack;

#endif /* INCLUDE_GENERICTOOLS_PARAMETERPACK_H_ */
