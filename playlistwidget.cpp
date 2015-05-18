#include "playlistwidget.h"
#include <QHeaderView>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QDebug>

PlaylistWidget::PlaylistWidget(QWidget *)
{
  api = new YandexmusicApi;
  outputData = new QList<QTreeWidgetItem *>;
  albumList = new QList<QList<QString> >;
  artistList = new QList<QList<QString> >;
  trackList = new QList<QList<QString> >;

  setColumnCount(5);
  setHeaderHidden(true);
  setSelectionMode(QAbstractItemView::SingleSelection);
  setEditTriggers( QAbstractItemView::NoEditTriggers );
  setIndentation(0);

  upItem = new QTreeWidgetItem({"", ".."});
  upItem->setSizeHint(0,QSize(30,30));
  upItem->setIcon(0, QIcon(":/icons/up"));

  addTopLevelItem(upItem);


}

void PlaylistWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
  if(event->type() == QEvent::MouseButtonDblClick)
    QMessageBox::warning(this, "oeuu", "oeuoeu", QMessageBox::Ok, QMessageBox::NoButton);
}

void PlaylistWidget::fillAlbumlist(const QString &name)
{
  setColumnCount(4);
  header()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  header()->resizeSection(0, 30);

  setIconSize(QSize(80, 80));
  QStringList lst;
  FileDownloader fd;
  QPixmap p;
  albumList->clear();
  *albumList = api->getAlbumInfo(name);

  if(!outputData->isEmpty())
    {
      for(auto i: *outputData)
        delete i;
      outputData->clear();
    }

  for(auto i: albumList->mid(1))
    {
      lst.append("");
      lst.append(i.at(static_cast<int>(YandexmusicApi::albumParameter::Title)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::albumParameter::ArtistName)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::albumParameter::Year)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::albumParameter::CoverUri)));

      outputData->append(nullptr);
      outputData->last() = new QTreeWidgetItem(lst);

      if(i[4] == "")
        outputData->last()->setIcon(0, QIcon(":/icons/blank"));
      else
        {
          fd.clearData();
          i[4].chop(2);
          fd.getData(QUrl(QString(QString("https://") + i[4] + QString("80x80"))));
          p.detach();
          p.loadFromData(fd.downloadedData(), "JPE");
          outputData->last()->setSizeHint(0, QSize(80, 80));
          outputData->last()->setIcon(0, QIcon(p));
        }

      lst.clear();
    }
  addTopLevelItems(*outputData);

  for(int i = 0; i < header()->count(); i++)
    resizeColumnToContents(i);
}

void PlaylistWidget::fillArtistlist(const QString &name)
{
  setColumnCount(3);
  header()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  header()->resizeSection(0, 30);

  setIconSize(QSize(80, 80));
  QStringList lst;
  FileDownloader fd;
  QPixmap p;
  artistList->clear();
  *artistList = api->getArtistInfo(name);

  if(!outputData->isEmpty())
    {
      for(auto i: *outputData)
        delete i;
      outputData->clear();
    }


  for(auto i: artistList->mid(1))
    {
      lst.append("");
      lst.append(i.at(static_cast<int>(YandexmusicApi::artistParameter::Genre)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::artistParameter::Name)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::artistParameter::CoverUri)));


      outputData->append(nullptr);
      outputData->last() = new QTreeWidgetItem(lst);

      if(i[2] == "")
        outputData->last()->setIcon(0, QIcon(":/icons/blank"));
      else
        {
          fd.clearData();
          i[2].chop(2);
          fd.getData(QUrl(QString(QString("https://") + i[2] + QString("80x80"))));
          p.detach();
          p.loadFromData(fd.downloadedData(), "JPE");
          outputData->last()->setSizeHint(0, QSize(80, 80));
          outputData->last()->setIcon(0, QIcon(p));
        }

      lst.clear();
    }
  addTopLevelItems(*outputData);

  for(int i = 0; i < header()->count(); i++)
    resizeColumnToContents(i);
}

void PlaylistWidget::fillTracklist(const QString &name)
{
  setIconSize(QSize(30, 30));
  setColumnCount(5);
  header()->setSectionResizeMode(QHeaderView::ResizeMode::Stretch);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  header()->resizeSection(0, 30);

  QStringList lst;
  QPixmap p;
  FileDownloader fd;
  trackList->clear();
  *trackList = api->getTrackInfo(name);

  if(!outputData->isEmpty())
    {
      for(auto i: *outputData)
        delete i;
      outputData->clear();
    }

  for(auto i: trackList->mid(1))
    {
      lst.append("");
      lst.append(i.at(static_cast<int>(YandexmusicApi::trackParameter::Title)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::trackParameter::AlbumTitle)));
      lst.append(i.at(static_cast<int>(YandexmusicApi::trackParameter::ArtistName)));
      quint32 msec = i.at(static_cast<int>(YandexmusicApi::trackParameter::DurationSec)).toUInt();
      lst.append(QString("%1:%2").arg(QString::number(msec/60000)).arg(msec/1000 % 60, 2, 10, QLatin1Char('0')));
      lst.append(i.at(static_cast<int>(YandexmusicApi::trackParameter::CoverUrl)));

      outputData->append(nullptr);
      outputData->last() = new QTreeWidgetItem(lst);

      if(i[7] == "")
        outputData->last()->setIcon(0, QIcon(":/icons/blank"));
      else
        {
          fd.clearData();
          i[7].chop(2);
          fd.getData(QUrl(QString(QString("https://") + i[7] + QString("30x30"))));
          p.detach();
          p.loadFromData(fd.downloadedData(), "JPE");
          outputData->last()->setSizeHint(0, QSize(30, 30));
          outputData->last()->setIcon(0, QIcon(p));
        }

      lst.clear();
    }
  addTopLevelItems(*outputData);

}
