#ifndef DATAWIDGET_H
#define DATAWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QScrollBar>

class DataWidget : public QWidget
{
  Q_OBJECT
public:
  enum class WidgetMode{search = 1, recomend, genre, assign, mymusic};
  explicit DataWidget(QWidget *parent = 0);
  ~DataWidget();
  void setMode(DataWidget::WidgetMode);

signals:

public slots:

private:
  void clearWidget();

  QPushButton *artistButton, *trackButton, *albumsButton;
  QListWidget *listWidget;
  QVBoxLayout *vboxLayout;
  QHBoxLayout *hboxLayout;
};

#endif // DATAWIDGET_H
