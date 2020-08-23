#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Super Nova Stream Viewer");

    ui->filePathText->setText("");

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);

    player->setVideoOutput(videoWidget);

    ui->horizontalLayout->addWidget(videoWidget);

    connect(player, &QMediaPlayer::durationChanged, ui->durationSlider, &QSlider::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, ui->durationSlider, &QSlider::setValue);
    connect(ui->durationSlider, &QSlider::sliderMoved, player, &QMediaPlayer::setPosition);

    connect(player, &QMediaPlayer::durationChanged, ui->durationProgressBar, &QProgressBar::setMaximum);
    connect(player, &QMediaPlayer::positionChanged, ui->durationProgressBar, &QProgressBar::setValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRtspServerPath(const QString& path)
{
    ui->filePathText->setText(path);

    const QUrl url = QUrl(path);

    const QNetworkRequest requestRtsp1(url);

    player->setMedia(requestRtsp1);
}

void MainWindow::setMediaFilePath(const QString& path)
{
    ui->filePathText->setText(path);

    const QUrl url = QUrl::fromLocalFile(path);

    player->setMedia(url);
}

void MainWindow::on_playButton_clicked()
{
    player->play();
    ui->volumeSlider->setSliderPosition(player->volume());
}

void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    player->stop();
    ui->volumeSlider->setSliderPosition(0);
}

void MainWindow::on_muteUnmuteButton_clicked()
{
    if (player->isMuted())
    {
        player->setMuted(false);
        ui->muteUnmuteButton->setText("Mute");
    }
    else
    {
        player->setMuted(true);
        ui->muteUnmuteButton->setText("UnMute");
    }
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}

void MainWindow::on_actionOpenNetworkStream_triggered()
{
    QString serverPath = QInputDialog::getText(this, "Rtsp Server","Rtsp Server Address");
    setRtspServerPath(serverPath);
}

void MainWindow::on_actionOpenFile_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open Media File", "", "Video files (*.mp4)");

    setMediaFilePath(file);
}

void MainWindow::on_forwardButton_clicked()
{
    player->setPlaybackRate(2.0);
}

void MainWindow::on_backwardButton_clicked()
{
    player->setPlaybackRate(-1.0);
}
