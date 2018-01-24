//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __IEVENTHANDLER
#define __IEVENTHANDLER

//-------------------------------------------------------------------

#include "lib.h"
#include "IDrawable.h"

class IEventCaller;

class IEventHandler
{
public:
	virtual void onEventHandle(IEventCaller *_c, GUIEvent::Event _e) = 0;
};

class IEventCaller
{
protected:
	IEventHandler *customHandler;
	virtual void onHandlerSet()
	{
		
	}
public:
	void setCustomHandler(IEventHandler *_handler)
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
