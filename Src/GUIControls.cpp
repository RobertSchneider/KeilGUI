//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIControls.h"

#define AVGMAX 10

void GUIControls::update()
{
	touch.update();
	int t = touch.isTouched();

	int x = touch.getPosX();
	int y = touch.getPosY();
	
	xAvg += x;
	yAvg += y;
	avgCount++;
	if (avgCount >= AVGMAX)
	{
		xAvg /= AVGMAX;
		yAvg /= AVGMAX;
				
		Rect finger(xAvg-10, yAvg-10, 5, 10);
		
		if (wasTouching != t)
		{
			wasTouching = t;
			superDrawable->onEvent(t ? GUIEvent::TouchDown : GUIEvent::TouchUp, finger);
		}
		else if (t)
		{
			superDrawable->onEvent(GUIEvent::Touch, finger);
		}
		
		xAvg = 0;
		yAvg = 0;
		avgCount = 0;
	}
}

//EOF
