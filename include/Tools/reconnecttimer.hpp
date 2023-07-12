#ifndef RECONNECTTIMER_H
#define RECONNECTTIMER_H

#include <QTimer>

class ReconnectTimer : public QObject {
    Q_OBJECT
public:
    explicit ReconnectTimer(QObject* parent = nullptr)
        : QObject { nullptr }
    {

    }

    void start(int ms)
    {
        timer.start(ms);
    }
    void stop()
    {
        timer.stop();
    }

//    template <typename... Args>
//    void CallOnTimeout(Args &&...args)
//    {
//#if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
//        timer.callOnTimeout(args...);

//#else
//        connect(&timer, &QTimer::timeout, std::forward<Args>(args)...);
//#endif
//    }

signals:

private:
    QTimer timer;
};

#endif // RECONNECTTIMER_H
