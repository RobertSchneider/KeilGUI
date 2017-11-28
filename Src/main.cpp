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
#include "GUI.h"
#include "View.h"

//*******************************************************************
int main(void)
{
	cDevDisplayGraphic graphics( dispHw );
	GUI::init(&graphics, 320, 240);
	
	View superView(GUI::screenRect, CYAN);
	
	View subView(Rect(10, 10, 10, 10), BLACK);
	superView.addChild(subView);
	
	GUIButton button(Rect(30, 20, 100, 30), BLACK, "test");
	superView.addChild(button);
	
	superView.draw();
	
  while(1)
	{
		
	}
}

//EOF
