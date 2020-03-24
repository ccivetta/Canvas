#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class ScribbleArea;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

protected:
    //void closeEvent(QCloseEvent *event) override;

private slots:
    //void open();
    //void save();
    void penColor();
    void penWidth();
    //void about();
    //void test();
    void on_clearBtn_clicked();
    void on_colorBtn_clicked();
private:
    void createActions();
    void createMenus();
    bool maybeSave();
    bool saveFile(const QByteArray &fileFormat);

    ScribbleArea *scribbleArea{};
    Ui::MainWindow *ui{};

    QMenu *saveAsMenu{};
    QMenu *fileMenu{};
    QMenu *optionMenu{};
    QMenu *helpMenu{};

    QAction *openAct{};
    QList<QAction *> saveAsActs;
    QAction *exitAct{};
    QAction *penColorAct{};
    QAction *penWidthAct{};
    QAction *printAct{};
    QAction *clearScreenAct{};
    QAction *aboutAct{};
    QAction *aboutQtAct{};



};

#endif