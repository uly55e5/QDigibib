#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtGui/QWidget>
#include "ui_SettingsDialog.h"
namespace QDigibib
{
class SettingsDialog : public QWidget
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private:
    Ui::SettingsClass ui;
};

#endif // SETTINGS_H
}
