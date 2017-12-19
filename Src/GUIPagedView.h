//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIPAGEDVIEW
#define __GUIPAGEDVIEW

//-------------------------------------------------------------------

#include "View.h"
#include "GUIButton.h"

class GUIPagedView : public View
{
protected:
	virtual void onDraw(Rect _r);
public:
	cList views;
	int selectedView;

	GUIPagedView(Rect _rect, int _n, View *_views,...)
		: View(_rect, BLACK),
			selectedView(0)
	{
		va_list ptr;
		va_start(ptr, _views);
		
		View *view = _views;
		
		for(int i = 0; i < _n; i++)
		{
			views.add(view);
			view = va_arg(ptr, View*);
		}
		
		GUIButton *bLeft = new GUIButton(Rect(_rect.x, _rect.y + _rect.h - 50, 50, 50), BLACK, "<");
		addChild(*bLeft);
		
		GUIButton *bRight = new GUIButton(Rect(_rect.x + _rect.w - 50, _rect.y + _rect.h - 50, 50, 50), BLACK, ">");
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
};

#endif
//EOF
