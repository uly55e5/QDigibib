#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtGui/QDialog>
#include "ui_SettingsDialog.h"

namespace QDigibib
{

class SettingsPageInterface;

/*! \brief The settings dialog of QDigibib
 *
 * The dialog is populated by calling registerPage().
 */
class SettingsDialog: public QDialog
{
Q_OBJECT

public:
	/*! \brief Constructs a new SettingsDialog as child of parent.
	 *
	 * @param parent The parent widget.
	 * @return A new settings dialog.
	 */
	SettingsDialog(QWidget *parent = 0);

	/*! \brief Destroys the settings dialog.
	 *
	 */
	~SettingsDialog();

	/*! \brief Add a page to the settings dialog.
	 *
	 * Each Page should implement the SettingsPageInterface interface. Name and icon for the
	 * current page will be added automatically via this interface. The dialog only
	 * supplies an Ok and a Cancel button, if you want to have a button for default
	 * values or to immidately apply the changes, you have to add these buttons to
	 * your page.
	 *
	 * @param page The new page.
	 * @param parent The parent page, if the page is a subpage.
	 */
	void registerPage(SettingsPageInterface * page,
			SettingsPageInterface * parent = 0);

public slots:
	/*! \brief Change the settings page.
	 *
	 *  This slot is normally called on changing the item in the treewidget.
	 *
	 *  \param ctwi The current (new) item
	 *  \param ptwi The previous (old) item
	 */
	void changePage(QTreeWidgetItem * ctwi, QTreeWidgetItem * ptwi);
private:
	/*! \brief Populate the dialog by calling with setting pages.
	 *
	 */
	void populateDialog();
	Ui::SettingsDialogClass ui; ///< The UI class for the dialog
};

#endif // SETTINGS_H
}
