//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUISelect.h"

void GUISelect::onDraw(Rect _r)
{
	GUIView::onDraw(_r);
}

void GUISelect::onLateDraw(Rect _r)
{
	GUIView::onLateDraw(_r);
	
	updateSelected(GUIEvent::None);
}

void GUISelect::onEvent(GUIEvent::Event _e, Rect _finger)
{
	GUIView::onEvent(_e, _finger);
}

void GUISelect::onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchUp || _e == GUIEvent::TouchDown)
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
	
		updateSelected(_e);
	}
}

void GUISelect::updateSelected(GUIEvent::Event _e)
{
	//update selected
	GUIButton* ptr = (GUIButton*)children.getFirst();
	while(ptr)
	{
		GUIHelper::drawRectOutline(ptr->rect, ptr == selectedButton ? outlineColor : ptr->backgroundColor, 2);
		ptr = (GUIButton*)ptr->getNext();
	}
	
	callHandler(_e);
}

//EOF
