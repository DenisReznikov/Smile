#ifndef ABSTRACT_WINDOWS_H
#define ABSTRACT_WINDOWS_H

#include <QMainWindow>

  class Abstract_Windows : public QMainWindow
  {
    Q_OBJECT

  public:
    Abstract_Windows(QString login,QWidget *parent = nullptr);
    ~Abstract_Windows();
    static QString name_Person;

  protected:
    virtual void closeWindow() = 0;
    virtual void nextWindow() = 0;

  private:


  };

#endif // ABSTRACT_WINDOWS_H
