//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIPagedView.h"

void GUIPagedView::onDraw(Rect _r)
{
	View* current = (View*)views[selectedView];
	current->draw(_r);
}

void GUIPagedView::onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchUp)
	{
		int prev = selectedView;
		
		((View*)views[selectedView])->isHidden = true;
		
		if (_caller == bLeft)
		{
			selectedView--;
		}else if (_caller == bRight)
		{
			selectedView++;
		}
		
		selectedView = selectedView < 0 ? 0 : (selectedView >= viewCount ? viewCount-1 : selectedView);
		((View*)views[selectedView])->isHidden = false;
		if (prev != selectedView)
		{
			redraw();
		}
	}
}

void GUIPagedView::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
	
	View* current = (View*)views[selectedView];
	current->onEvent(_e, _finger);
}

//EOF
