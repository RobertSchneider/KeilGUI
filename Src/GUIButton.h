//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIBUTTON
#define __GUIBUTTON

//-------------------------------------------------------------------

#include "GUILabel.h"
#include "IEventHandler.h"

class GUIButton : public GUIView, public IEventCaller
{
protected:
	virtual void onDraw(Rect _r);
public:
	bool drawOutline;
	GUILabel *label;
	COLOR outlineColor;

	GUIButton(Rect _rect, COLOR _color, char *_title)
		: GUIView(_rect, _color),
			outlineColor(RED)
	{
		label = new GUILabel(_rect, _color, _title);
		drawOutline = false;
		addChild(label);
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
};

#endif
//EOF
