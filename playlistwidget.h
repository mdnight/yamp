#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H
#include <QTreeWidget>
#include <QEvent>
#include "yandexmusicapi.h"
#include "filedownloader.h"

class PlaylistWidget : public QTreeWidget
{
public:
  PlaylistWidget(QWidget *parent = 0);
  PlaylistWidget(const PlaylistWidget &playlistwidget);
  void setPlaylist(const QList<QList<QString> > &trackInfo);
  void clearPlaylist();
  void fillTracklist(const QString &name);
  void fillAlbumlist(const QString &name);
  void fillArtistlist(const QString &name);

protected:
  void mouseDoubleClickEvent(QMouseEvent *event);

private:
  YandexmusicApi *api;
  QTreeWidgetItem *upItem;
  QList<QTreeWidgetItem *> *outputData;
  QList<QList<QString> > *albumList;
  QList<QList<QString> > *artistList;
  QList<QList<QString> > *trackList;
};
#endif // PLAYLISTWIDGET_H
