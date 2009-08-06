/*
 * DBLibraryHelper.cpp
 *
 *  Created on: 06.08.2009
 *      Author: uly55e5
 */

#include "DBLibraryHelper.h"

#include <QDir>
#include <QStringList>

namespace QDigibib
{
QStringList DBLibraryHelper::findFiles(const QString & fileName,
		const QString & startPath, bool recursive)
{
	if (fileName.isEmpty() || startPath.isEmpty())
		return QStringList();

	QStringList result;
	QDir dir(startPath);
	// get List of matching files
	QStringList fileList = dir.entryList(QStringList(fileName), QDir::Files);
	// and add to result
	foreach (QString file , fileList)
			result.append(dir.absoluteFilePath(file));

	if (recursive)
	{
		// find files in subdirectories
		QStringList dirList = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
		foreach (QString dirName , dirList)
				result.append(DBLibraryHelper::findFiles(fileName,
						dir.absoluteFilePath(dirName)));
	}
	return result;
}
}

