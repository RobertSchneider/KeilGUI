//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIPAGEDVIEW
#define __GUIPAGEDVIEW

//-------------------------------------------------------------------

#include "GUIView.h"
#include "GUIButton.h"

class GUIPagedView : public GUIView, public GUIEventHandler
{
protected:
	virtual void onDraw(Rect _r);
public:
	cList views;
	int selectedView;
	int viewCount;
	GUIButton *bLeft;
	GUIButton *bRight;

	GUIPagedView(Rect _rect, int _n, GUIView *_views,...)
		: GUIView(_rect, BLACK),
			selectedView(0)
	{
		va_list ptr;
		va_start(ptr, _views);
		
		GUIView *view = _views;
		
		for(int i = 0; i < _n; i++)
		{
			view->isHidden = i != 0;
			views.add(view);
			view = va_arg(ptr, GUIView*);
		}
		
		viewCount = _n;
		
		bLeft = new GUIButton(Rect(_rect.x, _rect.y + _rect.h - 50, _rect.w / 3, 50), BLACK, "<");
		bLeft->setCustomHandler(this);
		addChild(bLeft);
		
		bRight = new GUIButton(Rect(_rect.x + _rect.w / 3 * 2, _rect.y + _rect.h - 50, _rect.w / 3, 50), BLACK, ">");
		bRight->setCustomHandler(this);
		addChild(bRight);
		
		va_end(ptr);
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	virtual void onEventHandle(GUIEventCaller *_caller, GUIEvent::Event _e);
};

#endif
//EOF
