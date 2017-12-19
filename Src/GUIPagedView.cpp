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

void GUIPagedView::onEvent(GUIEvent::Event _e, Rect _finger)
{
	View::onEvent(_e, _finger);
	
	View* current = (View*)views[selectedView];
	current->onEvent(_e, _finger);
}

//EOF
