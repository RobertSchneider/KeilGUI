//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"

//*******************************************************************
#if defined _MCU_TYPE_LPC17XX
  #include "configLPC17xx.h"
#elif defined _MCU_TYPE_STM32L1XX
  #include "configSTM32L1xx.h"
#elif defined _MCU_TYPE_VIRTUAL
  #include "configVirtual.h"
#else
  #error "Device type not defined"
#endif

#include "IDrawable.h"
#include "GUIButton.h"
#include "GUILabel.h"
#include "GUI.h"
#include "View.h"
#include "GUIControls.h"
#include "GUISelect.h"
#include "GUIPagedView.h"

class SampleEventHandler : public IEventHandler
{
public:
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		GUIButton *b = (GUIButton*)_caller;
		if (_e == GUIEvent::TouchDown)
		{
			b->label.title = "click";
			b->redraw();
		}
		else if (_e == GUIEvent::TouchUp)
		{
			b->label.title = "test";
			b->redraw();
		}
	}
};

class SampleSelectEventHandler : public IEventHandler
{
public:
	GUILabel *statusLabel;
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		GUISelect *select = (GUISelect*)_caller;
		statusLabel->title = select->selectedButton->label.title;
		statusLabel->redraw();
	}
};

//*******************************************************************
int main(void)
{
	cDevDisplayGraphic graphics( dispHw );
	GUI::init(&graphics, 320, 240);
	
	View superView(GUI::screenRect, CYAN);
	
	SampleEventHandler sampleHandler;
	GUIButton button(Rect(30, 20, 100, 30), BLACK, "test");
	button.customHandler = &sampleHandler;
	superView.addChild(button);
	
	GUILabel label(Rect(100, 100, 100, 30), BLACK, "label");
	superView.addChild(label);
	
	SampleSelectEventHandler selectEventHandler;
	selectEventHandler.statusLabel = &label;
	GUISelect select(Rect(50, 150, 200, 30), BLACK, 3, "b1", "b2", "b3");
	select.customHandler = &selectEventHandler;
	superView.addChild(select);
	
	GUIPagedView pagedView = GUIPagedView(GUI::screenRect, 1, &superView);
	
	pagedView.draw();
	
	GUIControls controls(pagedView, touch);
	
  while(1)
	{
		controls.update();
	}
}

//EOF
