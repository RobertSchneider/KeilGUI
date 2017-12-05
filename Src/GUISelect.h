//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUISELECT
#define __GUISELECT

//-------------------------------------------------------------------

#include "View.h"
#include "GUIButton.h"

#include "GUISelect.h"

class GUISelect : public View
{
protected:
	int count;
	virtual void onDraw(Rect _r);
public:
	GUIButton *selectedButton;
	void (*onCustomEvent)(GUISelect*, GUIEvent::Event);

	GUISelect(Rect _rect, COLOR _color, int _n, char *_titles,...)
		: View(_rect, _color),
			count(_n),
			onCustomEvent(NULL)
	{
		va_list ptr;
		va_start(ptr, _titles);
		
		char *title = _titles;
		
		BYTE x = 0;
		for(int i = 0; i < count; i++)
		{
			GUIButton *btn = new GUIButton(Rect(x, _rect.y, _rect.w / count, _rect.h), _color, title);
			addChild(*btn);
			
			selectedButton = btn;
			
			x += _rect.w / count;
			title = va_arg(ptr, char*);
		}
		
		va_end(ptr);
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
};

#endif
//EOF
