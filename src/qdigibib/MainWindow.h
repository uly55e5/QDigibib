#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_MainWindow.h"

namespace QDigibib
{
/*! \brief The main window of the QDigibib GUI application.
 *
 */
class MainWindow: public QMainWindow
{
Q_OBJECT

public:
	/*! \brief Constructs a MainWindow as child of parent.
	 *
	 * @param parent The parent widget
	 * @return A new Mainwindow
	 */
	MainWindow(QWidget *parent = 0);

	/*! \brief Destroys the main window
	 *
	 */
	~MainWindow();

public slots:

	/*! \brief Show the settings dialog for QDigibib
	 *
	 */
	void showSettingsDialog();

private:
	Ui::MainWindowClass ui; ///< The UI class for MainWindow
};
}

#endif // MAINWINDOW_H
