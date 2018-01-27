//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIView.h"

void GUIView::destroy()
{
	IDrawable* ptr = (IDrawable*)children.getFirst();
	while(ptr)
	{
		delete ptr;
		ptr = (IDrawable*)ptr->getNext();
	}
}

bool GUIView::shouldDraw(Rect _r)
{
	return _r.intersects(rect);
}

void GUIView::draw(Rect _r)
{
	if (getIsHidden()) 
	{
		return;
	}
	
	if (_r.isValid() && shouldDraw(_r))
	{
		onDraw(_r);
	
		IDrawable* ptr = (IDrawable*)children.getFirst();
		while(ptr)
		{
			ptr->isHidden = false;
			ptr->draw(_r);
			ptr = (IDrawable*)ptr->getNext();
		}
		
		onLateDraw(_r);
	}
}

bool GUIView::getIsHidden()
{
	return isHidden || (parent != NULL && parent->getIsHidden());
}

void GUIView::redraw()
{
	if (getIsHidden()) 
	{
		return;
	}
	
	if (parent != NULL)
	{
		parent->draw(rect);
	}
	else
	{
		draw();
	}
}

void GUIView::onDraw(Rect _r)
{
	GUIHelper::drawRect(MINRECT(_r, rect), backgroundColor);
}

void GUIView::onLateDraw(Rect _r)
{
	
}

void GUIView::onEvent(GUIEvent::Event _e, Rect _finger)
{
	IDrawable* ptr = (IDrawable*)children.getFirst();
	while(ptr)
	{
		if (_e == GUIEvent::TouchUp || ptr->shouldDraw(_finger))
		{
			ptr->onEvent(_e, _finger);
		}
		ptr = (IDrawable*)ptr->getNext();
	}
}

//EOF
