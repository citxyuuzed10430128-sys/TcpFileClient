#ifndef TCPFILECLIENT_H
#define TCPFILECLIENT_H

#include <QDialog>
#include <QtNetwork>
#include <QtWidgets>

class TcpFileClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileClient(QWidget *parent = nullptr);
    ~TcpFileClient() override;

public slots:
    void start();                              // 使用者按下開始Button[cite: 7]
    void startTransfer();                      // TCP end-point connection 連線成功[cite: 7]
    void updateClientProgress(qint64 numBytes);// TCP end-point 持續可傳輸事件[cite: 7]
    void openFile();                           // 使用者按下開檔button[cite: 7]

private:
    QProgressBar *clientProgressBar;
    QLabel *clientStatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket tcpClient;

    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QString fileName;
    QFile *localFile;
    QByteArray outBlock;
};

#endif // TCPFILECLIENT_H