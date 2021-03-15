#ifndef LOGINERRORPROMPT_H
#define LOGINERRORPROMPT_H

#include <QWidget>

namespace Ui {
class LoginErrorPrompt;
}

class LoginErrorPrompt : public QWidget
{
    Q_OBJECT

public:
    explicit LoginErrorPrompt(QWidget *parent = nullptr);
    ~LoginErrorPrompt();

private slots:
    void closeLoginErrorPrompt();

private:
    Ui::LoginErrorPrompt *ui;
};

#endif // LOGINERRORPROMPT_H
