#ifndef TAB_H
#define TAB_H

#include <QWidget>

namespace Ui {
class Tab;
}

class Tab : public QWidget
{
    Q_OBJECT

public:
    explicit Tab(QWidget *parent = nullptr);
    ~Tab();

private:
    Ui::Tab *ui;

private slots:
    void addStar2();

};

#endif // TAB_H
