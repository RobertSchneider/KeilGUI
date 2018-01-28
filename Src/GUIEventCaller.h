//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIEVENTCALLER
#define __GUIEVENTCALLER

//-------------------------------------------------------------------

#include "lib.h"
#include "IDrawable.h"
#include "GUIEventHandler.h"

class GUIEventCaller
{
protected:
	GUIEventHandler *customHandler;
	virtual void onHandlerSet()
	{
		
	}
public:
	void setCustomHandler(GUIEventHandler *_handler)
	{
		customHandler = _handler;
		onHandlerSet();
	}
	void callHandler(GUIEvent::Event _e)
	{
		if (customHandler != NULL)
		{
			customHandler->onEventHandle(this, _e);
		}
	}
};

#endif

//EOF
