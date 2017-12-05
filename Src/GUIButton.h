//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIBUTTON
#define __GUIBUTTON

//-------------------------------------------------------------------

#include "View.h"

class GUIButton : public View
{
protected:
	bool drawOutline;
	virtual void onDraw(Rect _r);
public:
	char *title;
	COLOR textColor;
	COLOR outlineColor;
	void (*onCustomEvent)(GUIButton*, GUIEvent::Event);

	GUIButton(Rect _rect, COLOR _color, char *_title)
		: View(_rect, _color),
			textColor(WHITE),
			outlineColor(RED),
			onCustomEvent(NULL)
	{
		drawOutline = false;
		title = _title;
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
};

#endif
//EOF
