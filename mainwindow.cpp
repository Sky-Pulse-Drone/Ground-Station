#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QBluetoothAddress>
#include <QBluetoothDeviceInfo>
#include <QBluetoothUuid>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , discoveryAgent(new QBluetoothDeviceDiscoveryAgent(this))
    , socket(new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol))
{
    ui->setupUi(this);

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &MainWindow::deviceDiscovered);
    connect(socket, &QBluetoothSocket::readyRead, this, &MainWindow::readData);

    startDeviceDiscovery();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startDeviceDiscovery(){
    discoveryAgent->start();
    qDebug() << "Scanning for Bluetooth devices...";

}

void MainWindow::deviceDiscovered(const QBluetoothDeviceInfo &info){

}

void MainWindow::readData(){

}
