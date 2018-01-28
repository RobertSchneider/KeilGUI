//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIEVENTHANDLER
#define __GUIEVENTHANDLER

//-------------------------------------------------------------------

#include "lib.h"
#include "IDrawable.h"

class GUIEventCaller;

class GUIEventHandler
{
public:
	virtual void onEventHandle(GUIEventCaller *_c, GUIEvent::Event _e) = 0;
};

#endif

//EOF
