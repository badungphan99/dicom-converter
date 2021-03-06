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

    QDir dir("/tmp/dungpbhoangnvcucntkhanhptt");
    if (dir.exists("/tmp/dungpbhoangnvcucntkhanhptt")){
        dir.removeRecursively();
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

    QDir dir("/tmp/dungpbhoangnvcucntkhanhptt");
    if (dir.exists("/tmp/dungpbhoangnvcucntkhanhptt")){
        dir.removeRecursively();
    }
}

void MainWindow::on_actionLoad_Image_triggered()
{
    folderPath = QFileDialog::getExistingDirectory(this, "Select file","/home",QFileDialog::ShowDirsOnly);
    index=-1;


    std::cout << folderPath.toStdString() << std::endl;
    // duong dan thu muc out
    std::string pathOut;
    // cac thong tin tra ve, hien tai khong co gi dau
    std::vector<Dicom> dicoms;

    QDir dir("/tmp/dungpbhoangnvcucntkhanhptt");
    if (dir.exists("/tmp/dungpbhoangnvcucntkhanhptt")){
        dir.removeRecursively();
    }


    dicom_extract::extract_info(folderPath.toStdString(), pathOut, dicoms);


    std::cout << "extract xong\n";


        ui->label_file_namepatient->setText(QString::fromUtf8(dicoms[0].getFileName().c_str()));
        ui->label_positionpatient->setText(QString::fromUtf8(dicoms[0].getPatientPosition().c_str()));
        ui->label_uidpatient->setText(QString::fromUtf8(dicoms[0].getUid().c_str()));
        ui->label_sexpatient->setText(QString::fromUtf8(dicoms[0].getSex().c_str()));
        ui->labe_idpatient->setText(QString::fromUtf8(dicoms[0].getPatientId().c_str()));
        ui->label_photometric_nterpretationpatient->setText(QString::fromUtf8(dicoms[0].getPhotometricNterpretation().c_str()));
        ui->label_bits_allocatedpatient->setText(QString::fromUtf8(dicoms[0].getBitsAllocated().c_str()));
        ui->label_bits_storedpatient->setText(QString::fromUtf8(dicoms[0].getBitsStored().c_str()));
        ui->label_hight_bitpatient->setText(QString::fromUtf8(dicoms[0].getHighBit().c_str()));


    folderPath = QString::fromUtf8(pathOut.c_str());

    QDir directory(folderPath);
    images = directory.entryList(QStringList() << "*.png" << "*.PNG",QDir::Files);

    foreach(QString filename, images) {
            std::cout << filename.toStdString() << std::endl;
    }


}

void MainWindow::on_pushButton_previous_clicked()
{
    QDir directory(folderPath);
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
    QDir directory(folderPath);
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
