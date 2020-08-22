#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QNetworkRequest>
#include <QVideoWidget>
#include <QProgressBar>
#include <QSlider>


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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QVideoWidget* videoWidget;
    QMediaPlayer* player;
    QProgressBar* bar;
    QSlider* slider;
};
#endif // MAINWINDOW_H
