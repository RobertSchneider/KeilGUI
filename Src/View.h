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
	virtual void onLateDraw(Rect _r);
	virtual bool shouldDraw(Rect _r);
	virtual void destroy();
public:
	COLOR backgroundColor;
	Rect rect;

	View(Rect _rect, COLOR _color)
		: backgroundColor(_color), rect(_rect)
	{
		isHidden = true;
	}
	
	void addChild(IDrawable &_child)
	{
		_child.parent = this;
		_child.onAddedToDrawable(this);
		children.add(&_child);
	}
	
	~View()
	{
		destroy();
	}
	
	virtual bool getIsHidden();
	virtual void draw(Rect _r = GUI::screenRect);
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	virtual void redraw();
};

#endif
//EOF
