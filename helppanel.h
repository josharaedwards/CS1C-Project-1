#ifndef HELPPANEL_H
#define HELPPANEL_H

#include <QWidget>

namespace Ui {
class HelpPanel;
}

class HelpPanel : public QWidget
{
    Q_OBJECT

public:
    explicit HelpPanel(QWidget *parent = nullptr);
    ~HelpPanel();

private:
    Ui::HelpPanel *ui;
};

#endif // HELPPANEL_H
