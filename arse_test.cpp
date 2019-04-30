#include "arse_test.h"
#include <QString>

arse_test::arse_test(QWidget *parent) :
    QWidget(parent)
{
    stream =new QFile(":/arse_quis.txt");
    stream->open(QIODevice::ReadOnly);
    qnum = 0;
    tnum = 0;
    label = new QLabel(stream->readLine());
    tbut = new QPushButton("True");
    fbut = new QPushButton("Next");
    qbut = new QPushButton("Quit");
    layout = new QVBoxLayout;
    hLayout = new QHBoxLayout;
    qbut->setAccessibleName("Quit");
    fbut->setAccessibleName("Next");
    layout->addWidget(label);
    hLayout->addWidget(tbut);
    hLayout->addWidget(qbut);
    hLayout->addWidget(fbut);
    layout->addLayout(hLayout);
    label->setWordWrap(true);
    label->setTextFormat(Qt::RichText);
    tbut->setEnabled(false);
    setLayout(layout);
    show();
}
void arse_test::tf(){
    tnum++;
    ff();
}
void arse_test::endf(){
    QString str;
    tbut->setEnabled(false);
    fbut->setEnabled(false);
    if (tnum <= 5)
        str = " You don't sound like a certified asshole, unless you are fooling yourself.";
    else if (tnum <= 15)
        str = " You sound like a borderline certified asshole, perhaps it's time to start changing your behavior before it gets worse.";
    else
        str = " You sound like a full-blown certified asshole to me get help immediately. But, please, don’t come to me for help, as I would rather not meet you";
    label->setText(QString("Your score is: %1. %2").arg(tnum).arg(str));
}
void arse_test::ff(){
    qnum++;
    fbut->setText("False");
    tbut->setEnabled(true);
    fbut->setAccessibleName("False");
    tbut->setAccessibleName("True");
    if (qnum <= 24)
        label->setText(stream->readLine());
    else
        endf();
}
arse_test::~arse_test(){
    stream->close();
    delete stream;
    delete label;
    delete tbut;
    delete fbut;
    delete qbut;
    delete layout;
}
