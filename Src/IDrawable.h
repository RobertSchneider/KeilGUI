//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __IDRAWABLE
#define __IDRAWABLE

//-------------------------------------------------------------------

#include "lib.h"
#include "GUI.h"

namespace GUIEvent
{
	enum Event
	{
		None = 0,
		TouchDown = 1,
		Touch = 2,
		TouchUp = 3,
	};
};

class IDrawable : public cList::Item
{
public:
	IDrawable *parent;
	
	virtual void draw(Rect _r = GUI::screenRect) = 0;
	virtual void onEvent(GUIEvent::Event _e, Rect _finger) = 0;
	virtual bool shouldDraw(Rect _r) = 0;
	virtual void redraw() = 0;
	
protected:
	virtual void update()
	{
		
	}
	
	virtual void onDraw(Rect _r)
	{
		update();
	}
};

#endif

//EOF
