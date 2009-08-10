#include "LibraryLocationSetting.h"

namespace QDigibib
{
LibraryLocationSetting::LibraryLocationSetting(QWidget *parent) :
	SettingsPageInterface(parent)
{
	ui.setupUi(this);
	FileSystemModel * model = new FileSystemModel(this);
	model->setRootPath(QDir::rootPath());
	model->setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::Drives);
	ui.treeView->setModel(model);
	ui.treeView->setRootIndex(model->index(QDir::rootPath()));
}

LibraryLocationSetting::~LibraryLocationSetting()
{
}

QIcon LibraryLocationSetting::icon()
{
	return QIcon(tr("Library"));
}

QString LibraryLocationSetting::name()
{
	return tr("Library");
}

FileSystemModel::FileSystemModel(QObject * parent) :
	QFileSystemModel(parent)
{

}

FileSystemModel::~FileSystemModel()
{

}

Qt::ItemFlags FileSystemModel::flags(const QModelIndex & index) const
{
	// items are checkable and tristate
	return (Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsTristate
			| Qt::ItemIsEnabled);
}

QVariant FileSystemModel::data(const QModelIndex & index, int role) const
{
	if (role == Qt::CheckStateRole)
	{
		// return unchecked for root index
		if (index == QModelIndex())
			return Qt::Unchecked;
		// return saved states if available
		if (_checkStates.contains(index))
			return _checkStates[index];
		// return same as parent if not saved
		else if (data(parent(index), role) != Qt::PartiallyChecked)
			return data(parent(index), role);
		// in other cases return unchecked
		return Qt::Unchecked;
	}
	// for other roles return parent method
	return QFileSystemModel::data(index, role);
}

bool FileSystemModel::setData(const QModelIndex & index,
		const QVariant & value, int role)
{
	// return if nothing changed
	if (index == QModelIndex() || value == data(index, role))
		return true;
	// accept only changes in CheckState
	if (role == Qt::CheckStateRole)
	{
		// save state value
		Qt::CheckState state = (Qt::CheckState) value.toInt();
		// save checked items in Map
		if (state != Qt::Unchecked)
		{
			_checkStates[index] = (Qt::CheckState) value.toInt();
			setData(parent(index), Qt::PartiallyChecked, role);
		}
		// remove unchecked items from map
		else if (_checkStates.contains(index) )
		{
			_checkStates.remove(index);
			// test for childrens and parents checkstate
			if(hasCheckedChildren(index))
				_checkStates[index]=Qt::PartiallyChecked;
			if(!hasCheckedChildren(parent(index)))
				setData(parent(index),Qt::Unchecked,role);
		}
		// update model
		emit layoutChanged();
		return true;
	}
	// return false if role was not checkstate
	return false;
}

bool FileSystemModel::hasCheckedChildren( const QModelIndex & ind ) const
{
	// check all Children of the index
	for (int r=0; r <= rowCount(ind)-1; r++)
	{
		// return on first (partially) checked item found
		if(data(index(r,0,ind),Qt::CheckStateRole) != Qt::Unchecked)
			return true;
	}
	// return false is all unchecked
	return false;
}

int FileSystemModel::columnCount(const QModelIndex & parent) const
{
	// use only the first column (name)
	return 1;
}

}
