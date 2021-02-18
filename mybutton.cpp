#include "mybutton.h"
#include "ui_mybutton.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>

Mybutton::Mybutton(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mybutton)
{
    ui->setupUi(this);

}

Mybutton::~Mybutton()
{
    delete ui;
}


void Mybutton::on_pushButton_clicked()
{
    ui->label->setText("                                           Welcome\n                        Guide to navigate in this Pamphlet               \nTo navegate in this website you just need a CLICK!\nThe tabs on top allow you to find what are you looking for.\nHere you can coustomized your search.\nWould you like to see the football teams by alphabetical order, take\na look just for NFL or AFL, even check the stadiums capacity and\ncharacteristics.\nIt is just one click on the tab!\nWe would love to hear you, if you want to contact us please fill up\nthe contact sheet.");
}

