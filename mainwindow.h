#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QDir>
#include "include/core.h"
#include "include/dicom.h"
#include "include/dicom_extract.h"
#include "include/system_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSelect_Image_triggered();

    void on_actionSave_Image_triggered();

    void on_actionLoad_Image_triggered();

    void on_pushButton_previous_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::MainWindow *ui;
    QStringList listImage;
    int index = -1;
    QStringList images;
//    QDir directory;
    QString listFolderPath;
};
#endif // MAINWINDOW_H
