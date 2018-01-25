//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUISelect.h"

void GUISelect::onDraw(Rect _r)
{
	View::onDraw(_r);
}

void GUISelect::onLateDraw(Rect _r)
{
	View::onLateDraw(_r);
	
	updateSelected(GUIEvent::None);
}

void GUISelect::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
}

void GUISelect::onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchUp)
	{
		selectedIndex = 0;
		IDrawable* ptr = (IDrawable*)children.getFirst();
		while(ptr)
		{
			if (ptr == (GUIButton*)_caller)
				break;
			selectedIndex++;
			ptr = (IDrawable*)ptr->getNext();
		}
		
		selectedButton = (GUIButton*)_caller;
	}
	
	updateSelected(_e);
}

void GUISelect::updateSelected(GUIEvent::Event _e)
{
	//update selected
	GUIButton* ptr = (GUIButton*)children.getFirst();
	while(ptr)
	{
		GUI::drawRectOutline(ptr->rect, ptr == selectedButton ? outlineColor : ptr->backgroundColor, 2);
		ptr = (GUIButton*)ptr->getNext();
	}
	
	callHandler(_e);
}

//EOF
