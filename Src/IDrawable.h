//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __IDRAWABLE
#define __IDRAWABLE

//-------------------------------------------------------------------

#include "lib.h"
#include "GUI.h"

class IDrawable : public cList::Item
{
public:
	IDrawable *parent;
	
	virtual void draw(Rect _r = GUI::screenRect) = 0;
	
protected:
	virtual void update()
	{
		
	}
	
	virtual void onDraw(Rect _r)
	{
		update();
	}
	
	virtual bool shouldDraw(Rect _r) = 0;
};

#endif

//EOF
