/*!
 * \file main.cpp
 *
 *
 * \author uly55e5
 * \date 09.08.2009
 */

#include "MainWindow.h"

using namespace QDigibib;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow mw;
	mw.show();
	return app.exec();
}
