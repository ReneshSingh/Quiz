#ifndef ARSE_TEST_H
#define ARSE_TEST_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFile>
#include <QHBoxLayout>

class arse_test : public QWidget
{
    Q_OBJECT
public:
    explicit arse_test(QWidget *parent = 0);
    ~arse_test();
    QPushButton *tbut, *fbut, *qbut;
public slots:
    void tf();
    void ff();
private:
    void endf();
    QVBoxLayout *layout;
    QLabel *label;
    int qnum, tnum;
    QFile *stream;
    QHBoxLayout *hLayout;
};

#endif // ARSE_TEST_H
