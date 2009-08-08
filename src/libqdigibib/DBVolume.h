/*!
 * \file DBVolume.h
 *
 *
 * \author uly55e5
 * \date 08.08.2009
 */

#ifndef DBVOLUME_H_
#define DBVOLUME_H_

#include <QObject>

/*!
 *
 */
namespace QDigibib
{

class DBVolume: public QObject
{
	Q_OBJECT
public:
	/*! \brief Constructor with absolute path.
	 *
	 * @param path Path of digibib.txt file
	 * @return A new instance of class DBVolume
	 */
	DBVolume(const QString & digibibTxtPath);

	virtual ~DBVolume();
private:
	QString _digibibTxtPath; ///< Location of the volume's digibib.txt file
};

}

#endif /* DBVOLUME_H_ */
