#ifndef LIBRARYLOCATIONSETTING_H
#define LIBRARYLOCATIONSETTING_H

#include "SettingsPageInterface.h"
#include "ui_LibraryLocationSetting.h"

#include <QFileSystemModel>
#include <QMap>

namespace QDigibib
{
/**
 * \brief This page allows to select the paths for the libraries.
 */
class LibraryLocationSetting: public SettingsPageInterface
{
Q_OBJECT

public:
	/**
	 * \brief Constructs a new page of library location settings.
	 *
	 * \param parent The parent widget
	 */
	LibraryLocationSetting(QWidget *parent = 0);

	/**
	 * \brief Destroys the page.
	 */
	~LibraryLocationSetting();

	// inherited from SettingsPageInterface
	virtual QIcon icon();
	virtual QString name();

private:
	Ui::LibraryLocationSettingClass ui; ///< The UI class
};

/**
 * \brief A file system model with checkable items.
 */
class FileSystemModel: public QFileSystemModel
{
Q_OBJECT
public:
	/**
	 * \brief Constructs a new model
	 *
	 * @param parent The parent object
	 */
	FileSystemModel(QObject * parent = 0);

	/**
	 * \brief Destroys the model.
	 */
	virtual ~FileSystemModel();

	// inherited from QFileSystemModel
	Qt::ItemFlags flags(const QModelIndex & index) const;
	QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex & index, const QVariant & value, int role =
			Qt::EditRole);
	int columnCount(const QModelIndex & parent = QModelIndex()) const;

private:
	/**
	 *  \brief Checks if any of the children are (partially) checked
	 *
	 * @param index The index of the parent item
	 * @return True if at least one item is checked
	 */
	bool hasCheckedChildren(const QModelIndex & index) const;

	QMap<QModelIndex, Qt::CheckState> _checkStates; ///< saved check states
};
}

#endif // LIBRARYLOCATIONSETTING_H
