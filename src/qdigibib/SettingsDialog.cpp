#include "SettingsDialog.h"
#include "LibraryLocationSetting.h"

#include <QTreeWidgetItem>

namespace QDigibib
{
SettingsDialog::SettingsDialog(QWidget *parent) :
	QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.treeWidget,
			SIGNAL(currentItemChanged(QTreeWidgetItem *, QTreeWidgetItem*)),
			this, SLOT(changePage(QTreeWidgetItem*,QTreeWidgetItem*)));
	populateDialog();
}

SettingsDialog::~SettingsDialog()
{

}

void SettingsDialog::registerPage(SettingsPageInterface * page,
		SettingsPageInterface * parent)
{
	int index = ui.pagesWidget->addWidget(page);
	QTreeWidgetItem * twi = new QTreeWidgetItem(ui.treeWidget);
	twi->setIcon(0, page->icon());
	twi->setText(0, page->name());
	twi->setData(0, Qt::UserRole, index);
}

void SettingsDialog::changePage(QTreeWidgetItem * ctwi, QTreeWidgetItem * ptwi)
{
	ui.pagesWidget->setCurrentIndex((ctwi->data(0, Qt::UserRole)).toInt());
}

void SettingsDialog::populateDialog()
{
	LibraryLocationSetting * lls = new LibraryLocationSetting();
	registerPage(lls);
}
}
