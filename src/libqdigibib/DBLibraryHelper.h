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

/*! \brief Helper methods for Library management
 *
 * This class contains (mostly static) methods for which help at management of
 * the DBLibrary.
 */
class DBLibraryHelper: public QObject
{
Q_OBJECT
public:
	/*! \brief Find files in a directory tree.

	 The method searches for all files with name fileName in a directory tree
	 starting at the rootDir. The search is not case sensitive. A list of
	 files with absolute paths is returned. If one of the arguments is an
	 empty string, an empty list is returned.

	 \param fileName File name to search for
	 \param startPath  Path where to start searching
	 \param recursive If TRUE search in subdirectories
	 \return A List of files with absolute paths
	 */
	static QStringList
	findFiles(const QString & fileName, const QString & startPath,
			bool recursive = true);
};

}

#endif /* DBLIBRARYHELPER_H_ */
