/*
 * DBLibrary.cpp
 *
 *  Created on: 06.08.2009
 *      Author: uly55e5
 */

#include "DBLibrary.h"
#include "DBLibraryHelper.h"
#include "DBVolume.h"

#include <QDir>

namespace QDigibib
{

DBLibrary::DBLibrary()
{
	// TODO Auto-generated constructor stub

}

DBLibrary::~DBLibrary()
{
	// TODO Auto-generated destructor stub
}

void DBLibrary::addPath(const QString & path)
{
	if (!_libraryPaths.contains(path))
		_libraryPaths.append(path);
}

QStringList DBLibrary::paths()
{
	return _libraryPaths;
}

void DBLibrary::setPaths(const QStringList & paths)
{
	_libraryPaths = paths;
}

bool DBLibrary::removePath(const QString & path)
{
	if (_libraryPaths.contains(path))
		return _libraryPaths.removeOne(path);
	else
	{
		QDir dir(path);
		QString cPath = dir.canonicalPath();
		if (_libraryPaths.contains(cPath))
			return _libraryPaths.removeOne(cPath);
	}
	return false;
}

void DBLibrary::findVolumes()
{
	_volumeList.clear();
	QStringList digibibTxtList;
	foreach(QString path, _libraryPaths)
		{

			digibibTxtList.append(DBLibraryHelper::findFiles("digibib.txt",
					path));
		}
	digibibTxtList.removeDuplicates();
	foreach(QString file, digibibTxtList)
		{
			_volumeList.append(new DBVolume(file));
		}
}
}
