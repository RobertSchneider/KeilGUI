//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIButton.h"

void GUIButton::onDraw(Rect _r)
{
	View::onDraw(_r);
	GUI::drawString(rect, textColor, backgroundColor, title);
}

//EOF
