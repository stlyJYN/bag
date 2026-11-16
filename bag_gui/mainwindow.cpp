#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnExact_clicked()
{
    if (!readInput(false)) return;      // 输入有错，直接返回（错误信息已显示）

    mOut.clear();                       // 清空上次的输出
    mTop = 0;                           // 栈清空
    mCount = 0;                         // 解数清零

    findExact(0, 0);                    // 开始搜索

    if (mCount == 0)
        mOut << "无解";
    else
        mOut << QString("共找到 %1 组解").arg(mCount);

    ui->textOutput->setPlainText(mOut.join("\n"));   // 一次性显示
}


void MainWindow::on_btnBest_clicked()
{
    if (!readInput(true)) return;          // 注意：传 true，必须读价值

    mOut.clear();
    mTop = 0;
    mBestVal = 0;
    mBestTop = 0;

    // 算后缀和，剪枝要用（对应你 C 版 main 里那段循环）
    mSuffix[mN] = 0;
    for (int i = mN - 1; i >= 0; i--)
        mSuffix[i] = mSuffix[i + 1] + mV[i];

    findBest(0, 0, 0);

    if (mBestTop == 0) {
        mOut << "无解：一件物品都装不下";
    } else {
        mOut << QString("最优解：%1").arg(stackText(mBestStack, mBestTop));
        mOut << QString("最大价值：%1").arg(mBestVal);
    }

    ui->textOutput->setPlainText(mOut.join("\n"));
}


bool MainWindow::readInput(bool needValues)
{
    bool ok = false;

    // ---- 1. 读容量 T ----
    mT = ui->editT->text().trimmed().toInt(&ok);
    if (!ok || mT <= 0) {
        ui->textOutput->setPlainText("背包容量 T 必须是正整数");
        return false;
    }

    // ---- 2. 读体积 ----
    QStringList ws;
    if (!ui->editW->text().trimmed().isEmpty())
        ws = ui->editW->text().simplified().split(' ');

    if (ws.isEmpty()) {
        ui->textOutput->setPlainText("请至少输入一件物品的体积");
        return false;
    }
    if (ws.size() > MAXN) {
        ui->textOutput->setPlainText(QString("物品件数不能超过 %1").arg(MAXN));
        return false;
    }

    mN = ws.size();
    for (int i = 0; i < mN; i++) {
        mW[i] = ws[i].toInt(&ok);
        if (!ok || mW[i] <= 0) {
            ui->textOutput->setPlainText(QString("第 %1 件物品的体积不是正整数").arg(i + 1));
            return false;
        }
    }

    // ---- 3. 按需读价值 ----
    if (needValues) {
        QStringList vs;
        if (!ui->editV->text().trimmed().isEmpty())
            vs = ui->editV->text().simplified().split(' ');

        if (vs.size() != mN) {
            ui->textOutput->setPlainText(
                QString("价值个数(%1)必须和物品件数(%2)一致").arg(vs.size()).arg(mN));
            return false;
        }
        for (int i = 0; i < mN; i++) {
            mV[i] = vs[i].toInt(&ok);
            if (!ok) {
                ui->textOutput->setPlainText(QString("第 %1 件物品的价值不是整数").arg(i + 1));
                return false;
            }
        }
    } else {
        for (int i = 0; i < mN; i++) mV[i] = 0;
    }

    return true;
}

QString MainWindow::stackText(const int *st, int n) const
{
    QStringList parts;
    for (int i = 0; i < n; i++)
        parts << QString::number(mW[st[i]]);
    return "(" + parts.join(",") + ")";
}

void MainWindow::findExact(int i, int sum)
{
    if (sum == mT) {
        mCount++;
        mOut << stackText(mStack, mTop);
        return;
    }
    if (i >= mN) return;

    for (int k = i; k < mN; k++) {
        if (sum + mW[k] <= mT) {
            mStack[mTop++] = k;
            findExact(k + 1, sum + mW[k]);
            mTop--;
        }
    }
}

void MainWindow::findBest(int i, int sum, int val)
{
    if (val > mBestVal) {                  // ← 区别1：每个状态都可能更优
        mBestVal = val;
        mBestTop = mTop;
        for (int k = 0; k < mTop; k++)
            mBestStack[k] = mStack[k];
    }
    if (i >= mN) return;
    if (val + mSuffix[i] <= mBestVal) return;   // ← 区别2：上界剪枝

    for (int k = i; k < mN; k++) {
        if (sum + mW[k] <= mT) {
            mStack[mTop++] = k;
            findBest(k + 1, sum + mW[k], val + mV[k]);   // ← 区别3：多传了 val
            mTop--;
        }
    }
}

void MainWindow::on_btnLoad_clicked()
{
    // 弹出文件选择对话框，返回用户选的文件路径
    QString path = QFileDialog::getOpenFileName(
        this, "选择数据文件", "", "文本文件 (*.txt);;所有文件 (*)");

    if (path.isEmpty())
        return;                 // 用户点了取消

    QFile f(path);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textOutput->setPlainText("无法打开文件：" + path);
        return;
    }

    QTextStream in(&f);
    QString all = in.readAll();     // 一次读完全部内容
    f.close();

    // 按空格/换行切成一个个数字
    QStringList tok = all.simplified().split(' ');
    if (tok.size() < 2) {
        ui->textOutput->setPlainText("文件格式错误：至少需要 T 和件数 n");
        return;
    }

    // 第1个是容量 T，第2个是件数 n
    int n = tok[1].toInt();
    if (n <= 0 || tok.size() < 2 + n) {
        ui->textOutput->setPlainText("文件格式错误：物品数量不足");
        return;
    }

    // 接下来 n 个数是体积
    QStringList vols;
    for (int i = 0; i < n; i++)
        vols << tok[2 + i];

    // 如果还有 n 个数，就是价值
    QStringList vals;
    if (tok.size() >= 2 + 2 * n) {
        for (int i = 0; i < n; i++)
            vals << tok[2 + n + i];
    }

    // 填到界面上
    ui->editT->setText(tok[0]);
    ui->editW->setText(vols.join(' '));
    ui->editV->setText(vals.join(' '));

    ui->textOutput->setPlainText(
        QString("已读取：%1\n共 %2 件物品%3")
            .arg(path).arg(n)
            .arg(vals.isEmpty() ? "（无价值）" : "（含价值）"));
}
