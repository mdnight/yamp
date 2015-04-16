#ifndef VOLUMEBUTTON_H
#define VOLUMEBUTTON_H


#include <QToolButton>

QT_FORWARD_DECLARE_CLASS(QMenu)
QT_FORWARD_DECLARE_CLASS(QLabel)
QT_FORWARD_DECLARE_CLASS(QSlider)

class VolumeButton : public QToolButton
{
//  Q_OBJECT
  Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
    VolumeButton(QWidget *parent = 0);
    int volume() const;

public slots:
    void increaseVolume();
    void descreaseVolume();
    void setVolume(int volume);

signals:
    void volumeChanged(int volume);

private:
  QSlider *slider;
  QMenu *menu;
  QLabel *label;
};

#endif // VOLUMEBUTTON_H
