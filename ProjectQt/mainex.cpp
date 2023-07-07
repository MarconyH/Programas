#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QLabel ola("<center> Sla, funciona vai </center>");
	ola.setWindowTitle("Acreditooo");
	ola.resize(600, 400);
	ola.show();
	return app.exec();
}
