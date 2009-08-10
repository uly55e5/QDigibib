/*!
 * \file main.cpp
 *
 *
 * \author uly55e5
 * \date 09.08.2009
 */

#include "MainWindow.h"

// for all QDigibib classes
using namespace QDigibib;

/*! \brief The main function for the QDigibib GUI application.
 *
 * @param argc Number of arguments
 * @param argv Vector of Arguments
 * @return Status
 */
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// Instantiate and show the main window
	MainWindow mw;
	mw.show();

	// start event loop
	return app.exec();
}
