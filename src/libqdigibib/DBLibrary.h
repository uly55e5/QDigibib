/*
 * DBLibrary.h
 *
 *  Created on: 06.08.2009
 *      Author: dave
 */

#ifndef DBLIBRARY_H_
#define DBLIBRARY_H_

#include <QObject>

namespace QDigibib
{
/*! This class manages a set of volumes from the "Digitale Bibliothek"
 *
 */
class DBLibrary:public QObject
{
	Q_OBJECT
public:
	DBLibrary();
	virtual ~DBLibrary();
private:
	QStringList _libraryPaths; ///< the paths where to search for volumes
};

}

#endif /* DBLIBRARY_H_ */
