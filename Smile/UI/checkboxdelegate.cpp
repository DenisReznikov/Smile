#include "checkboxdelegate.h"
CheckBoxDelegate::CheckBoxDelegate(QObject *parent, int checkColumnIx) :
    QItemDelegate(parent)
{
    checkBoxColumnIx = checkColumnIx;
}

QWidget *CheckBoxDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem &option,
                      const QModelIndex &index) const
{
    if (index.column() == checkBoxColumnIx)
    {
        QCheckBox* chb = new QCheckBox(parent);
        connect(chb, SIGNAL(toggled(bool)), this, SLOT(commitAndCloseEditor()));
        return chb;
    } else {
        return QItemDelegate::createEditor(parent, option, index);
    }
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (index.column() == checkBoxColumnIx)
    {
        int checked = index.model()->data(index, Qt::DisplayRole).toInt();
        QCheckBox* chb = qobject_cast<QCheckBox*>(editor);
        chb->setChecked(checked == 1);
    } else {
        QItemDelegate::setEditorData(editor, index);
    }
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if (index.column() == checkBoxColumnIx)
    {

    } else {
        QItemDelegate::setModelData(editor, model, index);
    }
}

void CheckBoxDelegate::commitAndCloseEditor()
{
    QCheckBox* editor = qobject_cast<QCheckBox*>(sender());
    emit commitData(editor);
    emit closeEditor(editor);
}

void CheckBoxDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex & index ) const
{
    editor->setGeometry(option.rect);
}
void CheckBoxDelegate::paint(QPainter * painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    if (index.column() == checkBoxColumnIx)
    {
        QWidget *w = dynamic_cast<QWidget *>(painter->device());
        if (w)
        {
            QItemDelegate::drawBackground( painter, option, index );
            QItemDelegate::drawCheck( painter, option, option.rect, index.data(Qt::EditRole).toBool() ? Qt::Checked : Qt::Unchecked );
            drawFocus(painter, option, option.rect);
        }
    } else {
        QItemDelegate::paint(painter, option, index);
    }
}
