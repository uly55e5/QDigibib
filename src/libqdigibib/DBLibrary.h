/*
 * DBLibrary.h
 *
 *  Created on: 06.08.2009
 *      Author: uly55e5
 */

#ifndef DBLIBRARY_H_
#define DBLIBRARY_H_

#include <QObject>
#include <QStringList>



namespace QDigibib
{
class DBVolume;

	typedef QList<DBVolume *> DBVolumeList; ///< A List of volumes
/*! \brief Manages a set of volumes from the "Digitale Bibliothek"
 *
 * A library is defined by a set of paths to folders, which are searched
 * recursively for the volumes. Use setPaths(), addPath() and removePath() to
 * manage these folders. Get the folders with paths().
 *
 */
class DBLibrary: public QObject
{
Q_OBJECT
public:
	DBLibrary();
	virtual ~DBLibrary();

	/*! \brief List of paths used for at library creation.
	 *
	 * \sa addPath(), removePath(), setPaths()
	 *
	 * \return A list of absolute paths
	 */
	QStringList paths();

	/*! \brief Set the paths for the current library.
	 *
	 * The paths should be absolute canonical paths of folders.
	 *
	 * \sa paths(), addPath()
	 *
	 * \param paths A list of absolute paths
	 */
	void setPaths(const QStringList & paths);

	/*! \brief Add a path to the library paths.
	 *
	 * The path should be a canonical path of a folder.
	 *
	 * \sa removePath(), setPaths()
	 * \param path An absolute path
	 */
	void addPath(const QString & path);

	/*! \brief Remove a path from the library paths.
	 *
	 *  First the method tries to match the path against the list of paths
	 *  by string comparison. If this fails the canonical path is used.
	 *
	 *  \sa addPath(), paths()
	 *
	 * \param path An absolute path
	 * \return True on success
	 */
	bool removePath(const QString & path);

private:
	/*! \brief Find DB Volumes in the library paths.
	 *
	 * The methods searches for \c digibib.txt files in the paths set
	 * by _libraryPaths. Then a DBVolume instance is created for every file.
	 */
	void findVolumes();

	QStringList _libraryPaths; ///< The paths where to search for volumes \sa paths()
	DBVolumeList _volumeList;  ///< List of Volumes in the Library
};

}

#endif /* DBLIBRARY_H_ */
