//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __VIEW
#define __VIEW

//-------------------------------------------------------------------

#include "IDrawable.h"
#include "Rect.h"

class View : public IDrawable
{
protected:
	cList children;
	virtual void onDraw(Rect _r);
	virtual bool shouldDraw(Rect _r);
public:
	COLOR backgroundColor;
	Rect rect;

	View(Rect _rect, COLOR _color)
		: backgroundColor(_color), rect(_rect)
	{
		
	}
	
	void addChild(IDrawable &_child)
	{
		_child.parent = this;
		children.add(&_child);
	}
	
	virtual void draw(Rect _r = GUI::screenRect);
};

#endif
//EOF
