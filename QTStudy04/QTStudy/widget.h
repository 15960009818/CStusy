#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton>
#include <QLineEdit>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QLabel *lab1,*lab2;
    QLineEdit *lEdit;
    QPushButton *qpbt;

private:
    void CalcCircleArea();
};
#endif // WIDGET_H
