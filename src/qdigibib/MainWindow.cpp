#include "MainWindow.h"
#include "SettingsDialog.h"

namespace QDigibib
{
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent)
{
	ui.setupUi(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::showSettingsDialog()
{
	SettingsDialog sd;
	sd.exec();
}

}

