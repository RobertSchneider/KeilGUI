//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "View.h"


void View::destroy()
{
	IDrawable* ptr = (IDrawable*)children.getFirst();
	while(ptr)
	{
		delete ptr;
		ptr = (IDrawable*)ptr->getNext();
	}
}

bool View::shouldDraw(Rect _r)
{
	return _r.intersects(rect);
}

void View::draw(Rect _r)
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

bool View::getIsHidden()
{
	return isHidden || (parent != NULL && parent->getIsHidden());
}

void View::redraw()
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

void View::onDraw(Rect _r)
{
	GUI::drawRect(MINRECT(_r, rect), backgroundColor);
}

void View::onLateDraw(Rect _r)
{
	
}

void View::onEvent(GUIEvent::Event _e, Rect _finger)
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
