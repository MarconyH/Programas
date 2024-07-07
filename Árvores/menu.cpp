#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  // Create a widget to hold the menu items
  QWidget *window = new QWidget;
  window->setWindowTitle("Menu");

  // Create the layout for the menu
  QVBoxLayout *layout = new QVBoxLayout;

  // Create the buttons for the menu
  QPushButton *button1 = new QPushButton("Option 1");
  QPushButton *button2 = new QPushButton("Option 2");
  QPushButton *button3 = new QPushButton("Option 3");

  // Add the buttons to the layout
  layout->addWidget(button1);
  layout->addWidget(button2);
  layout->addWidget(button3);

  // Set the layout for the widget
  window->setLayout(layout);

  // Show the widget
  window->show();

  return app.exec();
}
