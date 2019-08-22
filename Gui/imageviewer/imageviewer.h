#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QWidget>
#include <QImage>

class QLabel;
class QScrollArea;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;

class ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = 0);

    bool loadFile(const QString& fileName);

private:
    void setImage(const QImage &newImage);

signals:
    void signal_prev();
    void signal_next();

private slots:
    void on_click_btn_zoom_out();
    void on_click_btn_zoom_in();
    void on_click_btn_prev();
    void on_click_btn_next();

private:
    void zoomOut();
    void zoomIn();
    void scaleImage(double factor);

private:
    double scaleFactor;
    QImage image;
    QLabel* image_label; //显式图片

    //主界面layout
    QVBoxLayout* main_layout;

    //按钮工具
    QHBoxLayout* tool_layout;
    QPushButton* btn_prev;
    QPushButton* btn_next;
};

#endif // IMAGEVIEWER_H
