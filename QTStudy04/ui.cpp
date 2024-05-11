//
// Created by 1 on 2024/4/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ui.h" resolved

#include "ui.h"
#include "ui_ui.h"


ui::ui(QWidget *parent) :
        QWidget(parent), ui(new Ui::ui) {
    ui->setupUi(this);
}

ui::~ui() {
    delete ui;
}
