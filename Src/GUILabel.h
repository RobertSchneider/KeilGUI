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
	virtual void onDraw(Rect _r);
public:
	char *title;
	COLOR textColor;

	GUILabel(Rect _rect, COLOR _color, char *_title)
		: View(_rect, _color),
			textColor(WHITE)
	{
		title = _title;
	}
};

#endif
//EOF
