#include "canvas_tabs.h"
#include "ui_canvas_tabs.h"

Canvas_tabs::Canvas_tabs(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas_tabs)
{
    ui->setupUi(this);
}

Canvas_tabs::~Canvas_tabs()
{
    delete ui;
}
