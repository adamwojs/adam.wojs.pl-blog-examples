#ifndef THEMEICONSDEMO_H
#define THEMEICONSDEMO_H

#include <QtGui>

class ThemeIconsDemo : public QDialog
{
    Q_OBJECT
    
public:
    explicit ThemeIconsDemo(QWidget *parent = 0);
    virtual ~ThemeIconsDemo();

public slots:
    void iconSizeChanged(int value);

protected:
    void setupUI();

private:
    QSlider     *m_iconSize;
    QListView   *m_view;
};

#endif // THEMEICONSDEMO_H
