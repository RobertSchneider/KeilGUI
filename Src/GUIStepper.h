//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUISTEPPER
#define __GUISTEPPER

//-------------------------------------------------------------------

#include "GUIView.h"
#include "GUIButton.h"
#include "GUIMeasurement.h"

class GUIStepper : public GUIView, public IEventHandler, public IEventCaller
{
protected:
	virtual void onDraw(Rect _r);
public:
	GUIButton *btnUp;
	GUIButton *btnDown;
	GUIMeasurement *label;	
	float max;
	float min;
	float current;
	float stepSize;

	GUIStepper(Rect _rect, COLOR _color, float _min, float _max, float _stepSize, float _current = 0)
		: GUIView(_rect, _color)
	{
		max = _max;
		min = _min;
		stepSize = _stepSize;
		current = _current < min ? min : _current;
		
		float btnWidth = 30;
		
		btnUp = new GUIButton(Rect(_rect.x + _rect.w - btnWidth, _rect.y, btnWidth, _rect.h), _color, "+");
		btnUp->setCustomHandler(this);
		addChild(btnUp);
		
		btnDown = new GUIButton(Rect(_rect.x, _rect.y, btnWidth, _rect.h), _color, "-");
		btnDown->setCustomHandler(this);
		addChild(btnDown);
		
		label = new GUIMeasurement(Rect(_rect.x + btnWidth, _rect.y, _rect.w - btnWidth * 2, _rect.h), _color, "", "");
		label->setValue(current);
		addChild(label);
	}
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	virtual void onEventHandle(IEventCaller *_caller, GUIEvent::Event _e);
};

#endif
//EOF
