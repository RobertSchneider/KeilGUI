//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUILABEL
#define __GUILABEL

//-------------------------------------------------------------------

#include "View.h"

class GUILabel : public View
{
protected:
	int strLen;
	char *title;
	virtual void onDraw(Rect _r);
	
	virtual void destroy()
	{
		delete title;
		View::destroy();
	}
public:
	COLOR textColor;
	GUIAlignment::Alignment alignment;

	GUILabel(Rect _rect, COLOR _color, const char *_title)
		: View(_rect, _color),
			textColor(WHITE)
	{
		alignment = GUIAlignment::Center;
		title = NULL;
		strLen = strlen(_title);
		setTitle(_title);
	}
	
	virtual void setAlignment(GUIAlignment::Alignment _a)
	{
		alignment = _a;
		redraw();
	}
	virtual void setTitle(const char *_title);
	
	char *getTitle()
	{
		return title;
	}
};

#endif
//EOF
