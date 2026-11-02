#include "tcpfileclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpFileClient w;
    w.show();

    return a.exec();
}