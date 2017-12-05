//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIBUTTON
#define __GUIBUTTON

//-------------------------------------------------------------------

#include "GUILabel.h"

class GUIButton : public View
{
protected:
	bool drawOutline;
	virtual void onDraw(Rect _r);
public:
	GUILabel label;
	COLOR outlineColor;
	void (*onCustomEvent)(GUIButton*, GUIEvent::Event);

	GUIButton(Rect _rect, COLOR _color, char *_title)
		: View(_rect, _color),
			label(_rect, _color, _title),
			outlineColor(RED),
			onCustomEvent(NULL)
	{
		drawOutline = false;
		addChild(label);
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
};

#endif
//EOF
