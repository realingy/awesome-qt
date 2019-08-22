#include "mainwindow.h"

#include <QSortFilterProxyModel>
#include <QStringListModel>
#include <QDir>
#include <QDebug>
#include <QPainter>
#include <QHBoxLayout>
#include "searchfilter.h"
#include "imageviewer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_dir = tr("E:/media");

    QStringList filters;
    filters << "*.jpg";

    m_widget_search_filter = new SearchFilter();  //文件浏览
    m_widget_image_viewr = new ImageViewer();     //图片浏览

    m_widget_search_filter->setMinimumWidth(421);
    m_widget_search_filter->setMaximumWidth(421);

    QHBoxLayout* main_layout = new QHBoxLayout();
    main_layout->addWidget(m_widget_search_filter);
    main_layout->addWidget(m_widget_image_viewr);

    QWidget* main_widget = new QWidget(this);
    main_widget->setLayout(main_layout);

    this->setCentralWidget(main_widget);

    m_widget_search_filter->Init(m_dir, filters);

    connect(m_widget_search_filter, SIGNAL(signal_current_select_file(QString)), this, SLOT(on_signal_show_image(QString)));
    connect(m_widget_image_viewr, SIGNAL(signal_next()), this, SLOT(on_signal_next()));
    connect(m_widget_image_viewr, SIGNAL(signal_prev()), this, SLOT(on_signal_prev()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_signal_next()
{
    m_widget_search_filter->SetCurrentSelectFile_Next();
}

void MainWindow::on_signal_prev()
{
    m_widget_search_filter->SetCurrentSelectFile_Prev();
}

void MainWindow::on_signal_show_image(const QString &picture_path)
{
    m_widget_image_viewr->loadFile(picture_path);
}
