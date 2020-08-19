#ifndef DFONTPREVIEWPROXYMODEL_H
#define DFONTPREVIEWPROXYMODEL_H

#include <QStandardItemModel>
#include <QSortFilterProxyModel>

class DFontPreviewProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit DFontPreviewProxyModel(QObject *parent = nullptr);
    ~DFontPreviewProxyModel();
    //判断给定项是否包含在模型中
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;
    //获取行数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //设置当前字体组
    void setFilterGroup(int filterGroup);
    //根据字体的信息进行分组,决定各个界面显示的字体
    bool isCustomFilterAcceptsRow(const QModelIndex &modelIndex) const;
    //判断用户字体名是否含有用户输入的内容
    bool isFontNameContainsPattern(QString fontName) const;
    //根据输入内容设置比对的模板
    void setFilterFontNamePattern(const QString &pattern);
signals:

private:
    int m_filterGroup;
    bool m_useSystemFilter;
//    bool m_editStatus;
    QString m_fontNamePattern;
};

#endif  // DFONTPREVIEWPROXYMODEL_H
