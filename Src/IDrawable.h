//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __IDRAWABLE
#define __IDRAWABLE

//-------------------------------------------------------------------

#include "lib.h"
#include "GUIHelper.h"

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
	bool isHidden;

	virtual bool getIsHidden()
	{
		return isHidden;
	}
	virtual void draw(Rect _r = GUIHelper::screenRect) = 0;
	virtual void onEvent(GUIEvent::Event _e, Rect _finger) = 0;
	virtual bool shouldDraw(Rect _r) = 0;
	virtual void redraw() = 0;
	virtual void onAddedToDrawable(IDrawable *_super)
	{
		
	}
	
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
