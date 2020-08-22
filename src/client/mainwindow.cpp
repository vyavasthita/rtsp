#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Super Nova Stream Viewer");

    videoWidget = new QVideoWidget(this);
    player = new QMediaPlayer(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->setCentralWidget(videoWidget);
    player->setVideoOutput(videoWidget);

    // Links de RTSP e Videos
    const QUrl url1 = QUrl(ui->lineEdit->text());

    // O NetworkRequest para os links
    const QNetworkRequest requestRtsp1(url1);

    // Adicionandos os links para o conteudo
    player->setMedia(requestRtsp1);

    // Da play para iniciar o Streaming
    player->play();
}
