/*
 * main.cpp
 *
 *  Created on: 04.01.2017
 *      Author: Gerd
 */


#include "Widget.h"
#include "MyTypes.h"

#include <GenericTools/Typelist2Parameterpack.h>
#include <GenericTools/MakeTypelist.h>

#include <iostream>
using namespace std;

void demoTypelist2Typepack();

int main(){
	cout << "DemoTypelist" << endl;
	demoTypelist2Typepack();
}
void demoTypelist2Typepack(){
	cout << "=== demoTypelist2Typepack" << endl;

	cout << "--------- Empty ---" << endl;
	using packEmpty_1 = Parameterpack<>;
	using typelistEmpty = MakeTypelist<>;
	using packEmpty_2 = TL2PP<typelistEmpty>;

	cout << "--- Widget<> widgetEmpty; // empty parameter pack" << endl;
	Widget<> widgetEmpty;
	cout << endl;
	cout << "--- Widget<packEmpty_1> widgetEmpty_1; // empty Parameterpack<>" << endl;
	Widget<packEmpty_1> widgetEmpty_1;
	cout << endl;
	cout << "--- Widget<packEmpty_2> widgetEmpty_2; // empty Parameterpack<> from MakeTypelist<>" << endl;
	Widget<packEmpty_2> widgetEmpty_2;
	cout << "--- widgetEmpty_2.print();" << endl;
	widgetEmpty_2.print();
	cout << endl;
	cout << "-------------------" << endl;

	cout << "--------- One Type ---" << endl;
	using packA_1 = Parameterpack<A>;
	using typelistA = MakeTypelist<A>;
	using packA_2 = TL2PP<typelistA>;

	cout << "--- Widget<A> widgetA; // parameter pack A" << endl;
	Widget<A> widgetA;
	cout << endl;
	cout << "--- Widget<packA_1> widgetA_1; // Parameterpack<A>" << endl;
	Widget<packA_1> widgetA_1;
	cout << endl;
	cout << "--- Widget<packA_2> widgetA_2; // Parameterpack<A> from MakeTypelist<A>" << endl;
	Widget<packA_2> widgetA_2;

	cout << "--- widgetA_2.print();" << endl;
	widgetA_2.print();
	cout << endl;
	cout << "-------------------" << endl;

	cout << "--------- ABC Type ---" << endl;
	using packABC_1 = Parameterpack<A, B, C>;
	using typelistABC = MakeTypelist<A, B, C>;
	using packABC_2 = TL2PP<typelistABC>;

	cout << "--- Widget<ABC> widgetABC; // parameter pack A, B, C" << endl;
	Widget<A, B, C> widgetABC;
	cout << endl;
	cout << "--- Widget<packABC_1> widgetABC_1; // Parameterpack<A, B, C>" << endl;
	Widget<packABC_1> widgetABC_1;
	cout << endl;
	cout << "--- Widget<packABC_2> widgetABC_2; // Parameterpack<A, B, C> from MakeTypelist<A, B, C>" << endl;
	Widget<packABC_2> widgetABC_2;

	cout << "--- widgetABC_2.print();" << endl;
	widgetABC_2.print();
	cout << endl;
	cout << endl;
	cout << "-------------------" << endl;


	cout << "=== end demoTypelist2Typepack" << endl;
}
