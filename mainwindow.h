#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

class VolumeButton;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  VolumeButton *volButton;
  QPushButton *prevButton, *ppButton, *playlistButton, *nextButton,
        *likeButton, *addButton, *assignButton, *genreButton, *recomButton;
  QLineEdit *searchLine;
  QLabel *trackLabel, *artistLabel;
  QSlider *playSlider;
  QVBoxLayout *widgetLayout, *artistTrackLayout;
  QHBoxLayout *subWidgetLayout;


};

#endif // MAINWINDOW_H
