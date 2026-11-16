#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 按钮点击的处理函数，名字必须叫 on_对象名_clicked
    void on_btnExact_clicked();
    void on_btnBest_clicked();
    void on_btnLoad_clicked();


private:
    bool readInput(bool needValues);
    void findExact(int i, int sum);
    void findBest(int i, int sum, int val);
    QString stackText(const int *st, int n) const;

    Ui::MainWindow *ui;

    static const int MAXN = 100;
    int mT = 0;                     // 背包容量
    int mN = 0;                     // 物品件数
    int mW[MAXN] = {0};             // 各物品体积
    int mV[MAXN] = {0};             // 各物品价值
    int mSuffix[MAXN + 1] = {0};    // 上界剪枝用的后缀和
    int mStack[MAXN] = {0};         // 当前选择的物品下标（相当于你 C 版的 stack[]）
    int mTop = 0;                   // 相当于你 C 版的 top
    int mCount = 0;                 // 恰好装满的解数
    int mBestVal = 0;               // 最大价值
    int mBestStack[MAXN] = {0};     // 最优解
    int mBestTop = 0;
    QStringList mOut;               // 输出内容缓冲

};
#endif // MAINWINDOW_H
