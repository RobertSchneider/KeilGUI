//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIBUTTON
#define __GUIBUTTON

//-------------------------------------------------------------------

#include "View.h"
#include "Rect.h"

class GUIButton : public View
{
protected:
	virtual void onDraw(Rect _r);
public:
	char *title;
	COLOR textColor;

	GUIButton(Rect _rect, COLOR _color, char *_title)
		: View(_rect, _color),
			textColor(WHITE)
	{
		title = _title;
	}
};

#endif
//EOF
