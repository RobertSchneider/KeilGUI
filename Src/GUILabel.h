//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUILABEL
#define __GUILABEL

//-------------------------------------------------------------------

#include "GUIView.h"

class GUILabel : public GUIView
{
protected:
	int strLen;
	char *title;
	virtual void onDraw(Rect _r);
	
	virtual void destroy()
	{
		delete title;
		GUIView::destroy();
	}
public:
	COLOR textColor;
	GUIAlignment::Alignment alignment;

	GUILabel(Rect _rect, COLOR _color, const char *_title)
		: GUIView(_rect, _color),
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
