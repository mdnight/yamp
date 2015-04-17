#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "volumebutton.h"
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), volButton(0),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  this->setWindowTitle(tr("Yamp"));
  ui->widget->setFixedHeight(80);

  searchLine = new QLineEdit(this);
  prevButton = new QPushButton(this);
  playlistButton = new QPushButton(this);
  ppButton = new QPushButton(this);
  nextButton = new QPushButton(this);
  likeButton = new QPushButton(this);
  addButton = new QPushButton(this);
  assignButton = new QPushButton(this);
  genreButton = new QPushButton(this);
  recomButton = new QPushButton(this);
  trackLabel = new QLabel(tr("Трек"), this);
  artistLabel = new QLabel(tr("Исполнитель"), this);
  playSlider = new QSlider(Qt::Horizontal, this);
  widgetLayout = new QVBoxLayout(this);
  artistTrackLayout = new QVBoxLayout(this);
  subWidgetLayout = new QHBoxLayout(this);
  volButton = new VolumeButton(this);

  searchLine->addAction(QIcon(":/icons/magnifier"), QLineEdit::ActionPosition::TrailingPosition);
  searchLine->setPlaceholderText(tr("Трек, альбом, исполнитель"));
//  connect(action, &QAction::triggered);

  ppButton->setIcon(QIcon(":/icons/play"));
  ppButton->setIconSize(ppButton->size());
  ppButton->setMaximumWidth(ppButton->height());

  prevButton->setIcon(QIcon(":/icons/prev"));
  prevButton->setIconSize(prevButton->size());
  prevButton->setMaximumWidth(prevButton->height());

  nextButton->setIcon(QIcon(":/icons/next"));
  nextButton->setIconSize(nextButton->size());
  nextButton->setMaximumWidth(nextButton->height());

  likeButton->setIcon(QIcon(":/icons/like"));
  likeButton->setIconSize(nextButton->size());
  likeButton->setMaximumWidth(likeButton->height());

  addButton->setIcon(QIcon(":/icons/add"));
  addButton->setIconSize(addButton->size());
  addButton->setMaximumWidth(nextButton->height());

  volButton->setIcon(QIcon(":/icons/volume_high"));
  volButton->setIconSize(volButton->size());
  volButton->setMaximumWidth(volButton->height());
//  QObject::connect(ui->volButton, &QToolButton::clicked)

  playlistButton->setIcon(QIcon(":/icons/playlist"));
  playlistButton->setIconSize(playlistButton->size());
  playlistButton->setMaximumWidth(playlistButton->height());

  recomButton->setText(tr("Рекомендации"));
  genreButton->setText(tr("Жанры"));
  assignButton->setText(tr("Подборки"));

  ui->topLayout->addWidget(searchLine);
  ui->topLayout->addWidget(recomButton);
  ui->topLayout->addWidget(genreButton);
  ui->topLayout->addWidget(assignButton);

  widgetLayout->addWidget(playSlider);
  widgetLayout->addLayout(subWidgetLayout);

  artistTrackLayout->addWidget(trackLabel);
  artistTrackLayout->addWidget(artistLabel);

  subWidgetLayout->addWidget(prevButton);
  subWidgetLayout->addWidget(ppButton);
  subWidgetLayout->addWidget(nextButton);
  subWidgetLayout->addWidget(playlistButton);
  subWidgetLayout->addLayout(artistTrackLayout);
  subWidgetLayout->addStretch();
  subWidgetLayout->addWidget(likeButton);
  subWidgetLayout->addWidget(addButton);
  subWidgetLayout->addWidget(volButton);
  ui->widget->setLayout(widgetLayout);


  QFile file(":/css/styles");
  file.open(QFile::ReadOnly);
  QString StyleSheet = QLatin1String(file.readAll());
  this->setStyleSheet(StyleSheet);

}

MainWindow::~MainWindow()
{
  delete ui;
}
