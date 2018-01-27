//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIPagedView.h"

void GUIPagedView::onDraw(Rect _r)
{
	GUIView* current = (GUIView*)views[selectedView];
	current->draw(_r);
}

void GUIPagedView::onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchUp)
	{
		int prev = selectedView;
		
		((GUIView*)views[selectedView])->isHidden = true;
		
		if (_caller == bLeft)
		{
			selectedView--;
		}else if (_caller == bRight)
		{
			selectedView++;
		}
		
		selectedView = selectedView < 0 ? 0 : (selectedView >= viewCount ? viewCount-1 : selectedView);
		((GUIView*)views[selectedView])->isHidden = false;
		if (prev != selectedView)
		{
			redraw();
		}
	}
}

void GUIPagedView::onEvent(GUIEvent::Event _e, Rect _finger)
{
	GUIView::onEvent(_e, _finger);
	
	GUIView* current = (GUIView*)views[selectedView];
	current->onEvent(_e, _finger);
}

//EOF
