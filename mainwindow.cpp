#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setWindowTitle(tr("Yamp"));
  ui->frame->setFixedHeight(80);
  action = ui->searchLine->addAction(QIcon(":/icons/magnifier"), QLineEdit::ActionPosition::TrailingPosition);
//  connect(action, &QAction::triggered);

  ui->ppButton->setIcon(QIcon(":/icons/play"));
  ui->ppButton->setIconSize(ui->ppButton->size());
  ui->ppButton->setMaximumWidth(ui->ppButton->height());

  ui->prevButton->setIcon(QIcon(":/icons/prev"));
  ui->prevButton->setIconSize(ui->prevButton->size());
  ui->prevButton->setMaximumWidth(ui->prevButton->height());

  ui->nextButton->setIcon(QIcon(":/icons/next"));
  ui->nextButton->setIconSize(ui->nextButton->size());
  ui->nextButton->setMaximumWidth(ui->nextButton->height());

  ui->likeButton->setIcon(QIcon(":/icons/like"));
  ui->likeButton->setIconSize(ui->nextButton->size());
  ui->likeButton->setMaximumWidth(ui->likeButton->height());

  ui->addButton->setIcon(QIcon(":/icons/add"));
  ui->addButton->setIconSize(ui->addButton->size());
  ui->addButton->setMaximumWidth(ui->nextButton->height());

  ui->volButton->setIcon(QIcon(":/icons/volume_high"));
  ui->volButton->setIconSize(ui->volButton->size());
  ui->volButton->setMaximumWidth(ui->volButton->height());
//  QObject::connect(ui->volButton, &QToolButton::clicked)

  ui->playlistButton->setIcon(QIcon(":/icons/playlist"));
  ui->playlistButton->setIconSize(ui->playlistButton->size());
  ui->playlistButton->setMaximumWidth(ui->playlistButton->height());

  ui->recomButton->setText(tr("Рекомендации"));
  ui->genreButton->setText(tr("Жанры"));
  ui->assignButton->setText(tr("Подборки"));



  QFile file(":/css/styles");
  file.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(file.readAll());
  this->setStyleSheet(StyleSheet);

  ui->searchLine->setPlaceholderText(tr("Трек, альбом, исполнитель"));
}

MainWindow::~MainWindow()
{
  delete ui;
  delete icon;
}
