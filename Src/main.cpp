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

#include "GUI.h"

#include <math.h>

class LedToggleEventHandler : public IEventHandler
{
public:
	bool toggled;
	cDevDigital *digital;

	LedToggleEventHandler(cDevDigital &_digital)
	{
		digital = &_digital;
	}

	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		GUIButton *b = (GUIButton*)_caller;
		if (_e == GUIEvent::TouchUp)
		{
			toggled = !toggled;
			digital->set(toggled);
			b->label->setTitle(toggled ? "LED1: on" : "LED1: off");
		}
	}
};

class LedSelectEventHandler : public IEventHandler
{
public:
	cDevDigital *digitalLed1;
	cDevDigital *digitalLed2;
	cDevDigital *digitalLed3;

	LedSelectEventHandler(cDevDigital *_l1, cDevDigital *_l2, cDevDigital *_l3)
	{
		digitalLed1 = _l1;
		digitalLed2 = _l2;
		digitalLed3 = _l3;
	}

	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e)
	{
		if (_e == GUIEvent::TouchUp)
		{
			GUISelect *select = (GUISelect*)_caller;
			digitalLed1->set(select->selectedIndex == 0);
			digitalLed2->set(select->selectedIndex == 1);
			digitalLed3->set(select->selectedIndex == 2);
		}
	}
};

class SampleTimer : public cList::Item
{
public:
	float time;
	float cycle;
	GUIStepper *stepper;

	SampleTimer(float _cycle)
	{
		cycle = _cycle;
	}

	virtual void update()
	{
		time += 1.0f / cycle;
		float f = sin(2 * 3.141 * time * stepper->current);
		f = (f + 1) * 100.0f / 3000.0f * 0xFFFF;
		dac.set(f);
	}
};

SampleTimer sampleTimer(1000);

//*******************************************************************
int main(void)
{
	cDevDisplayGraphic graphics( dispHw );
	GUIHelper::init(&graphics, 320, 240, 8);
	
	//setup
	adc0.enable(2);
	timer.add(&sampleTimer);
	
	//======LEDS
	GUITitleView *firstView = new GUITitleView(GUIHelper::screenRect, WHITE, "LED");
	
	LedToggleEventHandler *handler = new LedToggleEventHandler(led1);
	GUIButton *ledToggle = new GUIButton(Rect(40, 80, 240, 30), BLACK, "LED1: off");
	ledToggle->setCustomHandler(handler);
	firstView->addChild(ledToggle);
	
	LedSelectEventHandler *selectEventHandler = new LedSelectEventHandler(&led2, &led3, &led4);
	GUISelect *select = new GUISelect(Rect(40, 120, 240, 30), BLACK, 3, "LED2", "LED3", "LED4");
	select->setCustomHandler(selectEventHandler);
	firstView->addChild(select);
	
	//======POTI
	GUITitleView *secondView = new GUITitleView(GUIHelper::screenRect, WHITE, "POTI");
	
	GUIMeasurement *measure = new GUIMeasurement(Rect(40, 80, 240, 30), BLACK, "poti:", " mV");
	measure->setAlignment(GUIAlignment::Left);
	secondView->addChild(measure);
	
	//======SOUND
	GUITitleView *thirdView = new GUITitleView(GUIHelper::screenRect, WHITE, "SOUND");
	
	GUILabel *label = new GUILabel(Rect(40, 80, 240, 30), BLACK, "frequency");
	thirdView->addChild(label);
	
	GUIStepper *stepper = new GUIStepper(Rect(40, 120, 240, 30), BLACK, 0, 1000, 100);
	sampleTimer.stepper = stepper;
	thirdView->addChild(stepper);
	
	GUIPagedView *pagedView = new GUIPagedView(GUIHelper::screenRect, 3, firstView, secondView, thirdView);
	GUIControls *controls = new GUIControls(pagedView, touch);
	pagedView->draw();
	
	int skipFrames = 0;
	
  while(1)
	{
		controls->update();
		
		if (skipFrames++ == 100)
		{
			adc0.update();
			measure->setValue(adc0.get(2));
			skipFrames = 0;
		}
	}
}

//EOF
