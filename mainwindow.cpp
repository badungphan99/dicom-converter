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
    const QString folderPath = QFileDialog::getOpenFileName(this, "Select file",QString(), tr("Images(*.png *.jpg)"));

    if(!folderPath.isEmpty()){
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();

        QImage image(folderPath);
        ui->label_pic->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
    }
}


void MainWindow::on_actionSave_Image_triggered()
{

    const QString fileName = QFileDialog::getSaveFileName(this, "Save file",QString(), "Images(*.png *.jpg)");

    const QPixmap* pixmap = ui->label_pic->pixmap();
    if (pixmap){
        QImage image1(pixmap -> toImage());
        if (!fileName.isEmpty()){
            image1.save(fileName);
        }
    }

}
