#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    int N = 8;
    int M = 8;

    QWidget window;
    window.setWindowTitle("Шахматная доска");
    window.resize(600, 600);

    QVBoxLayout *layout = new QVBoxLayout(&window);

    QLabel *lettersLabel = new QLabel(&window);
    QString letters = "ABCDEFGH";
    lettersLabel->setText("   " + letters.mid(0, M));
    layout->addWidget(lettersLabel);

    for (int i = 0; i < N; ++i) {
        QHBoxLayout *rowLayout = new QHBoxLayout;
        QLabel *numberLabel = new QLabel(&window);
        numberLabel->setText(QString::number(i + 1) + " ");
        rowLayout->addWidget(numberLabel);
        for (int j = 0; j < M; ++j) {
            QLabel *cell = new QLabel(&window);
            cell->setFixedSize(50, 50);
            if ((i + j) % 2 == 0) {
                cell->setStyleSheet("background-color: white;");
            } else {
                cell->setStyleSheet("background-color: gray;");
            }

            rowLayout->addWidget(cell);
        }
        layout->addLayout(rowLayout);
    }
    window.show();

    return app.exec();
}
