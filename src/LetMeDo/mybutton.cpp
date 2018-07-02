#include "mybutton.h"


MyButton::MyButton()
{
    setStyleSheet("QPushButton{color:white；background:black}");
}

void MyButton::enterEvent(QEvent *)
{
    setIcon(*pix_blue);
}

void MyButton::leaveEvent(QEvent *)
{
    setIcon(*pix);
}
