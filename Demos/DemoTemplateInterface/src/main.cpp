/*
 * main.cpp
 *
 *  Created on: 06.01.2017
 *      Author: Gerd
 */

#include "Widget.h"
#include "MyTypes.h"


#include <iostream>
using namespace std;

void demoTemplateInterface();

int main(){
	cout << "DemoTemplateInterface" << endl;
	demoTemplateInterface();
}

void demoTemplateInterface(){
	using pack = Typepack<A, B>;
	{
		cout << "begin block demoTemplateInterface()" << endl;
		cout << "Widget<pack> w1;" << endl;
		cout << "Widget<pack> w1;" << endl;
		Widget<pack> w1;
		cout << "w1.print();" << endl;
		w1.print();

		Widget<A, B> w2(w1);
		cout << "w2.print();" << endl;
		w2.print();

		Widget<pack> w11(w2);
		cout << "w11.print();" << endl;
		w11.print();

		w11 = w1;
		w2 = w11;
		w1 = w2;
		cout << "end block demoTemplateInterface()" << endl;
	}
}
