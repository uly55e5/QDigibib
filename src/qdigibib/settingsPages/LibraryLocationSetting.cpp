#include "LibraryLocationSetting.h"

namespace QDigibib
{
LibraryLocationSetting::LibraryLocationSetting(QWidget *parent) :
	SettingsPageInterface(parent)
{
	ui.setupUi(this);
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
}
