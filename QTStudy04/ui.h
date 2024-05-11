//
// Created by 1 on 2024/4/9.
//

#ifndef QTSTUDY04_UI_H
#define QTSTUDY04_UI_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ui; }
QT_END_NAMESPACE

class ui : public QWidget {
    Q_OBJECT

public:
    explicit ui(QWidget *parent = nullptr);

    ~ui() override;

private:
    Ui::ui *ui;
};


#endif //QTSTUDY04_UI_H
