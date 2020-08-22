#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Super Nova Stream Viewer");

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

void MainWindow::on_pushButton_3_clicked()
{
    const QUrl url = QUrl(ui->lineEdit->text());

    const QNetworkRequest requestRtsp1(url);

    player->setMedia(requestRtsp1);
}

void MainWindow::on_playButton_clicked()
{
    player->play();
}

void MainWindow::on_pauseButton_clicked()
{
    player->pause();
}

void MainWindow::on_stopButton_clicked()
{
    player->stop();
}

void MainWindow::on_muteUnmuteButton_clicked()
{
    if (ui->muteUnmuteButton->text() == "Mute")
    {
        player->setMuted(true);
        ui->muteUnmuteButton->setText("UnMute");
    }
    else
    {
        player->setMuted(false);
        ui->muteUnmuteButton->setText("Mute");
    }
}

void MainWindow::on_volumeSlider_valueChanged(int value)
{
    player->setVolume(value);
}
