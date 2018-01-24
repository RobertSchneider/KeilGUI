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
#include "GUIMeasurement.h"
#include "GUIStepper.h"
#include "GUITitleView.h"

class SampleEventHandler : public IEventHandler
{
public:
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		GUIButton *b = (GUIButton*)_caller;
		if (_e == GUIEvent::TouchDown)
		{
			b->label->setTitle("click");
		}
		else if (_e == GUIEvent::TouchUp)
		{
			b->label->setTitle("test");
		}
	}
};

class SampleSelectEventHandler : public IEventHandler
{
public:
	GUILabel *statusLabel;
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		if (_e == GUIEvent::TouchUp)
		{
			GUISelect *select = (GUISelect*)_caller;
			statusLabel->setTitle(select->selectedButton->label->getTitle());
		}
	}
};

//*******************************************************************
int main(void)
{
	cDevDisplayGraphic graphics( dispHw );
	GUI::init(&graphics, 320, 240, 8);
	
	View *superView = new View(GUI::screenRect, CYAN);
	
	SampleEventHandler *sampleHandler = new SampleEventHandler();
	GUIButton *button = new GUIButton(Rect(30, 20, 100, 30), BLACK, "test");
	button->setCustomHandler(sampleHandler);
	superView->addChild(*button);
	
	GUILabel *label = new GUILabel(Rect(100, 100, 100, 30), BLACK, "label");
	superView->addChild(*label);
	
	SampleSelectEventHandler *selectEventHandler = new SampleSelectEventHandler();
	selectEventHandler->statusLabel = label;
	GUISelect *select = new GUISelect(Rect(50, 150, 200, 30), BLACK, 3, "b1", "b2", "b3");
	select->setCustomHandler(selectEventHandler);
	superView->addChild(*select);
	
	GUITitleView *secondView = new GUITitleView(GUI::screenRect, WHITE, "second");
	GUIMeasurement *measure = new GUIMeasurement(Rect(10, 10, 200, 30), BLACK, "t:", "s");
	measure->setValue(10);
	secondView->addChild(*measure);
	
	GUIStepper *stepper = new GUIStepper(Rect(40, 100, 240, 30), BLACK, 0, 1, 0.1f);
	secondView->addChild(*stepper);
	
	GUIPagedView *pagedView = new GUIPagedView(GUI::screenRect, 2, superView, secondView);
	
	GUIControls *controls = new GUIControls(pagedView, touch);
	
	pagedView->draw();
	
  while(1)
	{
		controls->update();
	}
}

//EOF
