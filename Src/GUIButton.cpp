//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIButton.h"

void GUIButton::onDraw(Rect _r)
{
	View::onDraw(_r);
}

void GUIButton::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
	onCustomEvent(this, _e);
	
	if (_e == GUIEvent::TouchDown || (_e == GUIEvent::TouchUp && drawOutline))
	{
		drawOutline = _e == GUIEvent::TouchDown;
		GUI::drawRectOutline(rect, drawOutline ? outlineColor : backgroundColor, 2);
	}
}

//EOF
