/**
 *  @file adminpanel.h
 *  @brief GUI controls for admin tab
 */

#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QWidget>

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

    QString getFileName();

signals:
    void newFileLoaded(QString newFileName);

private slots:
    void adminPasswordAuth();
    void adminPasswordClear();
    void loadFileName();
    void closeAdminPanel();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
