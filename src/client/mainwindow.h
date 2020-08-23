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
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

    void on_muteUnmuteButton_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_actionOpenNetworkStream_triggered();

    void on_actionOpenFile_triggered();

    void on_forwardButton_clicked();

    void on_backwardButton_clicked();

private:
    void setRtspServerPath(const QString& path);

    void setMediaFilePath(const QString& path);

    Ui::MainWindow *ui;

    QVideoWidget* videoWidget;
    QMediaPlayer* player;
};
#endif // MAINWINDOW_H
