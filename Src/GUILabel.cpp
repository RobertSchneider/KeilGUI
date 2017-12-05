//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUILabel.h"

void GUILabel::onDraw(Rect _r)
{
	View::onDraw(_r);
	GUI::drawString(rect, textColor, backgroundColor, title);
}

//EOF
