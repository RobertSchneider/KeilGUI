//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUISELECT
#define __GUISELECT

//-------------------------------------------------------------------

#include "GUIView.h"
#include "GUIButton.h"

class GUISelect : public GUIView, public GUIEventHandler, public GUIEventCaller
{
protected:
	int count;
	virtual void onDraw(Rect _r);
	virtual void onLateDraw(Rect _r);
	virtual void onHandlerSet()
	{
		callHandler(GUIEvent::TouchUp);
	}
public:
	GUIButton *selectedButton;
	int selectedIndex;
	COLOR outlineColor;

	GUISelect(Rect _rect, COLOR _color, int _n, char *_titles,...)
		: GUIView(_rect, _color),
			count(_n),
			outlineColor(YELLOW)
	{
		va_list ptr;
		va_start(ptr, _titles);
		
		char *title = _titles;
		
		BYTE x = 0;
		for(int i = 0; i < count; i++)
		{
			GUIButton *btn = new GUIButton(Rect(_rect.x + x, _rect.y, _rect.w / count, _rect.h), _color, title);
			btn->setCustomHandler(this);
			addChild(btn);
			
			selectedIndex = i;
			selectedButton = btn;
			
			x += _rect.w / count;
			title = va_arg(ptr, char*);
		}
		
		va_end(ptr);
	}
	
	void onButtonSelected(GUIButton *_b, GUIEvent::Event _e);
	void updateSelected(GUIEvent::Event _e);
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	virtual void onEventHandle(GUIEventCaller *_caller, GUIEvent::Event _e);
};

#endif
//EOF
