#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QImage>
#include <QStringList>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    abt.push_back("Tran Thi An");
    abt.push_back("17/11/1958");
    abt.push_back("Nu");
    abt.push_back("Hoan Kiem, Ha Noi");
    abt.push_back("800px");
    abt.push_back("1200px");

    ui->label_namepatient->setText(QString::fromUtf8(abt[0].c_str()));
    ui->label_birthpatient->setText(QString::fromUtf8(abt[1].c_str()));
    ui->label_genderpatient->setText(QString::fromUtf8(abt[2].c_str()));
    ui->label_addresspatient->setText(QString::fromUtf8(abt[3].c_str()));
    ui->label_heightimagepatient->setText(QString::fromUtf8(abt[4].c_str()));
    ui->label_widthimagepatient->setText(QString::fromUtf8(abt[5].c_str()));
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

void MainWindow::on_actionLoad_Image_triggered()
{
    listFolderPath = QFileDialog::getExistingDirectory(this, "Select file","/home",QFileDialog::ShowDirsOnly);

    std::cout << listFolderPath.toStdString() << std::endl;

    QDir directory(listFolderPath);
    images = directory.entryList(QStringList() << "*.jpg" << "*.JPG",QDir::Files);

    foreach(QString filename, images) {
            std::cout << filename.toStdString() << std::endl;
    }
}

void MainWindow::on_pushButton_previous_clicked()
{
    QDir directory(listFolderPath);
    index = max(0, index-1);
    if (index >= 0){
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        QString path = directory.filePath(images.at(index));
        std::cout << path.toStdString() << std::endl;
        QImage image(path);
        ui->label_pic->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
    }
}

void MainWindow::on_pushButton_next_clicked()
{
    QDir directory(listFolderPath);
    index = min(index+1, images.size()-1);
    if (index < images.size()){
        int w = ui->label_pic->width();
        int h = ui->label_pic->height();
        QString path = directory.filePath(images.at(index));
        std::cout << path.toStdString() << std::endl;
        QImage image(path);
        ui->label_pic->setPixmap(QPixmap::fromImage(image.scaled(w, h, Qt::KeepAspectRatio)));
    }

}
