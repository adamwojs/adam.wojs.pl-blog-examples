#include <QApplication>
#include "themeiconsdemo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ThemeIconsDemo demo;
    demo.show();
    
    return app.exec();
}
