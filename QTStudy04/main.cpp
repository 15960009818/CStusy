#include <QApplication>
#include <QPushButton>
#include "dialog.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    D
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
