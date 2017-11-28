//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "View.h"

bool View::shouldDraw(Rect _r)
{
	return _r.intersects(rect);
}

void View::draw(Rect _r)
{
	if (_r.isValid() && shouldDraw(_r))
	{
		onDraw(_r);
	
		IDrawable* ptr = (IDrawable*)children.getFirst();
		while(ptr)
		{
			ptr->draw(_r);
			ptr = (IDrawable*)ptr->getNext();
		}
	}
}

void View::onDraw(Rect _r)
{
	GUI::drawRect(MINRECT(_r, rect), backgroundColor);
}

//EOF
