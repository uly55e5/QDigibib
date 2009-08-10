#ifndef LIBRARYLOCATIONSETTING_H
#define LIBRARYLOCATIONSETTING_H

#include "SettingsPageInterface.h"
#include "ui_LibraryLocationSetting.h"

namespace QDigibib
{
/*! \brief This page allows to select the paths for the libraries.
 *
 */
class LibraryLocationSetting: public SettingsPageInterface
{
Q_OBJECT

public:
	LibraryLocationSetting(QWidget *parent = 0);
	~LibraryLocationSetting();

	// inheritetd from SettingsPageInterface
	virtual QIcon icon();
	virtual QString name();

private:
	Ui::LibraryLocationSettingClass ui; ///< The UI class
};
}
#endif // LIBRARYLOCATIONSETTING_H
