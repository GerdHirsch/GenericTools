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
#include <GenericTools/Reverse.h>
#include <iostream>

using namespace std;

void demoTypelist2Typepack();
void demoTemplateInterface();

int main(){
	cout << "DemoTypelist" << endl;
	demoTypelist2Typepack();
}

void demoTypelist2Typepack(){
	cout << "=== demoTypelist2Typepack" << endl;

	cout << "--------- Empty ---" << endl;
	using packEmpty_1 = Typepack<>;
	using typelistEmpty = MakeTypelist<>;
	using packEmpty_2 = TList2TPack<typelistEmpty>;

	cout << "--- Widget<> widgetEmpty; // empty parameter pack" << endl;
	WidgetImpl<> widgetEmpty;
	cout << endl;
	cout << "--- Widget<packEmpty_1> widgetEmpty_1; // empty Parameterpack<>" << endl;
	WidgetImpl<packEmpty_1> widgetEmpty_1;
	cout << endl;
	cout << "--- Widget<packEmpty_2> widgetEmpty_2; // empty Parameterpack<> from MakeTypelist<>" << endl;
	WidgetImpl<packEmpty_2> widgetEmpty_2;
	cout << "--- widgetEmpty_2.print();" << endl;
	widgetEmpty_2.print();
	cout << endl;
	cout << "-------------------" << endl;

	cout << "--------- One Type ---" << endl;
	using packA_1 = Typepack<A>;
	using typelistA = MakeTypelist<A>;
//	using typelistA1 = MakeTypelist<packA_1>;
	using packA_2 = TList2TPack<typelistA>;

	cout << "--- Widget<A> widgetA; // parameter pack A" << endl;
	WidgetImpl<A> widgetA;
	cout << endl;
	cout << "--- Widget<packA_1> widgetA_1; // Parameterpack<A>" << endl;
	WidgetImpl<packA_1> widgetA_1;
	cout << endl;
	cout << "--- Widget<packA_2> widgetA_2; // Parameterpack<A> from MakeTypelist<A>" << endl;
	WidgetImpl<packA_2> widgetA_2;

	cout << "--- widgetA_2.print();" << endl;
	widgetA_2.print();
	cout << endl;
	cout << "-------------------" << endl;

	cout << "--------- ABC Type ---" << endl;
	using packABC_1 = Typepack<A, B, C>;
	using typelistABC = MakeTypelist<A, B, C>;
	using packABC_2 = TList2TPack<typelistABC>;


	cout << "--- Widget<ABC> widgetABC; // parameter pack A, B, C" << endl;
	WidgetImpl<A, B, C> widgetABC;
	cout << endl;
	cout << "--- Widget<packABC_1> widgetABC_1; // Parameterpack<A, B, C>" << endl;
	WidgetImpl<packABC_1> widgetABC_1;
	cout << endl;
	cout << "--- Widget<packABC_2> widgetABC_2; // Parameterpack<A, B, C> from MakeTypelist<A, B, C>" << endl;
	WidgetImpl<packABC_2> widgetABC_2;

	cout << "--- widgetABC_2.print();" << endl;
	widgetABC_2.print();

	cout << endl;
	cout << endl;
	cout << "-------------------" << endl;

	cout << "--------- CBA Type ---" << endl;
	using packCBA_1 = Reverse<A, B, C>;
	using packCBA_2 = Reverse<packABC_2>;
	cout << "--- Widget<packCBA_1> widgetCBA_1; // Reverse<A, B, C>" << endl;
	WidgetImpl<packCBA_1> widgetCBA_1;
	cout << endl;
	cout << "--- Widget<packCBA_2> widgetCBA_2; // Reverse from MakeTypelist<A, B, C>" << endl;
	WidgetImpl<packCBA_2> widgetCBA_2;

	cout << "--- widgetCBA_2.print();" << endl;
	widgetCBA_2.print();
	cout << endl;

	WidgetImpl<C, B, A> w(widgetCBA_2);
	widgetCBA_2 = widgetCBA_1;

	//Widget<packCBA_1> w2(w);

	cout << "=== end demoTypelist2Typepack" << endl;
}
