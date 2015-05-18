#include "datawidget.h"



DataWidget::DataWidget(QWidget *parent) : QWidget(parent)
{
  artistButton = new QPushButton(this);
  trackButton = new QPushButton(this);
  albumsButton = new QPushButton(this);
  listWidget = new QListWidget(this);
  vboxLayout = new QVBoxLayout(this);
  hboxLayout = new QHBoxLayout(this);
}

DataWidget::~DataWidget()
{

}

void DataWidget::clearWidget()
{
  artistButton->hide();
  trackButton->hide();
  albumsButton->hide();
  listWidget->hide();
}

void DataWidget::setMode(DataWidget::WidgetMode mode)
{
  switch(mode){
    case WidgetMode::search:
      clearWidget();
      hboxLayout->addStretch();
      hboxLayout->addWidget(artistButton);
      hboxLayout->addWidget(albumsButton);
      hboxLayout->addWidget(trackButton);
      hboxLayout->addStretch();
      vboxLayout->addLayout(hboxLayout);
      vboxLayout->addWidget(listWidget);
      this->setLayout(vboxLayout);
      break;

    case WidgetMode::recomend:
      break;

    case WidgetMode::genre:
      break;

    case WidgetMode::assign:
      break;

    case WidgetMode::mymusic:
      break;
    }

}
