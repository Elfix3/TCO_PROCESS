#include "control.h"

Control::Control(QWidget *parent) : QMainWindow(parent), ui(new Ui::CONTROL) {
    ui->setupUi(this);
}

Control::~Control() {
    delete ui;
}
