#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QImage>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSelect_Image_triggered()
{
    const QString folderPath = QFileDialog::getOpenFileName(this, "Select file", "Images(*.png, *.jpg)");

    if(!folderPath.isEmpty()){
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        QImage image(folderPath);
        ui->label_pic->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
    }
}
