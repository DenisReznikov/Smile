
#include <QWidget>

namespace Ui {
class pass;
}

class Ui::pass : public QWidget
{
    Q_OBJECT

public:
    explicit pass(QWidget *parent = nullptr);
    ~pass();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();

private:
    Ui::pass *ui;
};

