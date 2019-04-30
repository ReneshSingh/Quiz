#include <QApplication>
#include "arse_test.cpp"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    arse_test *a = new arse_test;
    QObject::connect(a->tbut, SIGNAL(clicked()), a, SLOT(tf()));
    QObject::connect(a->fbut, SIGNAL(clicked()), a, SLOT(ff()));
    QObject::connect(a->qbut, SIGNAL(clicked()), &app, SLOT(quit()));
    return app.exec();
}
