#ifndef CHECKBOXDELEGATE_H
#define CHECKBOXDELEGATE_H

#include <QItemDelegate>

#include <QCheckBox>

#include <QPainter>



class CheckBoxDelegate: public QItemDelegate
{
  Q_OBJECT
public:
  CheckBoxDelegate(QObject *parent ,int checkColumnIx);
  void commitAndCloseEditor();
  void paint( QPainter *painter,const QStyleOptionViewItem &option,const QModelIndex &index ) const;//
  QWidget *createEditor( QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index ) const;
  void setEditorData( QWidget *editor,const QModelIndex &index ) const;
  void setModelData( QWidget *editor,QAbstractItemModel *model,const QModelIndex &index ) const;
  void updateEditorGeometry( QWidget *editor, const QStyleOptionViewItem &option,const QModelIndex &index ) const;
  mutable QCheckBox * theCheckBox;
  int checkBoxColumnIx;

};

#endif // CHECKBOXDELEGATE_H
