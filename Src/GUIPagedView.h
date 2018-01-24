//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIPAGEDVIEW
#define __GUIPAGEDVIEW

//-------------------------------------------------------------------

#include "View.h"
#include "GUIButton.h"

class GUIPagedView : public View, public IEventHandler
{
protected:
	virtual void onDraw(Rect _r);
public:
	cList views;
	int selectedView;
	int viewCount;
	GUIButton *bLeft;
	GUIButton *bRight;

	GUIPagedView(Rect _rect, int _n, View *_views,...)
		: View(_rect, BLACK),
			selectedView(0)
	{
		va_list ptr;
		va_start(ptr, _views);
		
		View *view = _views;
		
		for(int i = 0; i < _n; i++)
		{
			view->isHidden = i != 0;
			views.add(view);
			view = va_arg(ptr, View*);
		}
		
		viewCount = _n;
		
		bLeft = new GUIButton(Rect(_rect.x, _rect.y + _rect.h - 50, 50, 50), BLACK, "<");
		bLeft->setCustomHandler(this);
		addChild(*bLeft);
		
		bRight = new GUIButton(Rect(_rect.x + _rect.w - 50, _rect.y + _rect.h - 50, 50, 50), BLACK, ">");
		bRight->setCustomHandler(this);
		addChild(*bRight);
		
		va_end(ptr);
	}
	
	~GUIPagedView()
	{
		GUIButton* ptr = (GUIButton*)children.getFirst();
		while(ptr)
		{
			delete ptr;
			ptr = (GUIButton*)ptr->getNext();
		}
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e);
};

#endif
//EOF
