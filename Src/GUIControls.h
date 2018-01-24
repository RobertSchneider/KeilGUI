//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUICONTROLS
#define __GUICONTROLS

//-------------------------------------------------------------------

#include "lib.h"
#include "View.h"
#include "Rect.h"

class GUIControls
{
private:
	View *superView;
	cHwTouch &touch;
	BYTE wasTouching;	
public:
	GUIControls(View *_superView, cHwTouch &_touch)
		: superView(_superView), touch(_touch)
	{
		superView->isHidden = false;
	}
	
	void update();
};

#endif
//EOF
