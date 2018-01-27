//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUICONTROLS
#define __GUICONTROLS

//-------------------------------------------------------------------

#include "lib.h"
#include "IDrawable.h"
#include "Rect.h"

class GUIControls
{
private:
	IDrawable *superDrawable;
	cHwTouch &touch;
	BYTE wasTouching;	
	int xAvg;
	int yAvg;
	int avgCount;
public:
	GUIControls(IDrawable *_superDrawable, cHwTouch &_touch)
		: superDrawable(_superDrawable), touch(_touch)
	{
		superDrawable->isHidden = false;
	}
	
	void update();
};

#endif
//EOF
