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
public:
	COLOR textColor;
	virtual void setTitle(const char *_title);

	GUILabel(Rect _rect, COLOR _color, const char *_title)
		: View(_rect, _color),
			textColor(WHITE)
	{
		title = NULL;
		strLen = strlen(_title);
		setTitle(_title);
	}
	
	char *getTitle()
	{
		return title;
	}
	
	~GUILabel()
	{
		delete title;
	}
};

#endif
//EOF
