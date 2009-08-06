/*
 * DBLibraryHelper.h
 *
 *  Created on: 06.08.2009
 *      Author: uly55e5
 */

#ifndef DBLIBRARYHELPER_H_
#define DBLIBRARYHELPER_H_

#include <QObject>

namespace QDigibib
{

/*! Helper methods for Library management
 *
 * This class contains (mostly static) methodes for which help at management of
 * the DBLibrary.
 */
class DBLibraryHelper: public QObject
{
Q_OBJECT
	/*! Find files in a directory tree.

	 The method searches for all files with name fileName in a directory tree
	 starting at the rootDir. The search is not case sensitive. A list of
	 files with absolute paths is returned. If one of the arguments is an
	 empty string, an empty list is returned.

	 \param fileName file name to search for
	 \param startPath  path where to start searching
	 \param recursive if TRUE search in subdirectories
	 \return list of files with absolute paths
	 */
public:
	static QStringList
	findFiles(const QString & fileName, const QString & startPath,
			bool recursive = true);
};

}

#endif /* DBLIBRARYHELPER_H_ */
