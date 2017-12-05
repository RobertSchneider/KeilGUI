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

void onButtonTestEvent(GUIButton *_b, GUIEvent::Event _e)
{
	if (_e == GUIEvent::TouchDown)
	{
		_b->label.title = "click";
		_b->redraw();
	}
	else if (_e == GUIEvent::TouchUp)
	{
		_b->label.title = "test";
		_b->redraw();
	}
}

//*******************************************************************
int main(void)
{
	cDevDisplayGraphic graphics( dispHw );
	GUI::init(&graphics, 320, 240);
	
	View superView(GUI::screenRect, CYAN);
	
	View subView(Rect(10, 10, 10, 10), BLACK);
	superView.addChild(subView);
	
	GUIButton button(Rect(30, 20, 100, 30), BLACK, "test");
	button.onCustomEvent = &onButtonTestEvent;
	superView.addChild(button);
	
	GUILabel label(Rect(100, 100, 100, 20), BLACK, "label");
	superView.addChild(label);
	
	GUISelect select(Rect(0, 200, 320, 20), BLACK, 3, "b1", "b2", "b3");
	superView.addChild(select);
	
	superView.draw();
	
	GUIControls controls(superView, touch);
	
  while(1)
	{
		controls.update();
	}
}

//EOF
