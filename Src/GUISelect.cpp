//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUISelect.h"

void GUISelect::onDraw(Rect _r)
{
	View::onDraw(_r);
}

void GUISelect::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
	onCustomEvent(this, _e);
}

//EOF
