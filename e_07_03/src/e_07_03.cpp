/* 演習07-03 main
 * 左上直角二等辺三角形と右下直角２等辺三角形を作成する
 * 作成日：６月６日
 * 作成者：成田修之
 */

#include <iostream>
#include"Shape.h"
#include"TwoDimensional.h"
#include"Rectangle.h"
#include"RectEquilTriangle.h"

using namespace std;

int main()
{
	Shape* s[] = {
			new Rectangle(4,5),
			new RectEquilTriangleLB(5),
			new RectEquilTriangleLU(6),
			new RectEquilTriangleRB(7),
			new RectEquilTriangleRU(8),
	};

	for(unsigned int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		cout  << "s[" << i << "]\n";
		s[i]->print();

		if(TwoDimensional* t = dynamic_cast<TwoDimensional*>(s[i])) {
			cout << "面積は" << t->get_area() << "です。\n";
		}

		cout << "\n";
	}

	for(unsigned int i = 0; i < sizeof(s) / sizeof(s[0]); i++) {
		delete s[i];
	}
}
