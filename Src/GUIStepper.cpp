//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIStepper.h"

void GUIStepper::onDraw(Rect _r)
{
	View::onDraw(_r);
}

void GUIStepper::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
}

void GUIStepper::onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchUp)
	{
		if (_caller == btnUp)
		{
			current += stepSize;
		}
		if (_caller == btnDown)
		{
			current -= stepSize;
		}
		current = current < min ? min : (current > max ? max : current);
		label->setValue(current);
		
		callHandler(_e);
	}
}

//EOF
