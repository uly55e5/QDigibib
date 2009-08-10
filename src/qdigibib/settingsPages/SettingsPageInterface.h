/*!
 * \file SettingsPageInterface.h
 *
 *
 * \author uly55e5
 * \date 10.08.2009
 */

#ifndef SETTINGSPAGE_H_
#define SETTINGSPAGE_H_

#include <QWidget>

namespace QDigibib
{
/*! \brief Interface class for the settings dialog pages.
 *
 */
class SettingsPageInterface: public QWidget
{
Q_OBJECT
protected:
	SettingsPageInterface(QWidget * parent) :
		QWidget(parent)
	{
	}
	;
	virtual ~SettingsPageInterface()
	{
	}
	;
public:
	/*! \brief The icon for the settings dialog.
	 *
	 * @return An icon.
	 */
	virtual QIcon icon()=0;

	/*! \brief The name shown in the settings dialog.
	 *
	 * @return A name.
	 */
	virtual QString name()=0;
};
}

#endif /* SETTINGSPAGE_H_ */
