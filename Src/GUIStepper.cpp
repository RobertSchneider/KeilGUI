//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIStepper.h"

void GUIStepper::onDraw(Rect _r)
{
	GUIView::onDraw(_r);
}

void GUIStepper::onEvent(GUIEvent::Event _e, Rect _finger)
{
	GUIView::onEvent(_e, _finger);
}

void GUIStepper::onEventHandle(GUIEventCaller *_caller, GUIEvent::Event _e)
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
