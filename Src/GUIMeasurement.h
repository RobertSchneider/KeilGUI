//*******************************************************************
// IDrawable
//*******************************************************************

#ifndef __GUIMEASUREMENT
#define __GUIMEASUREMENT

//-------------------------------------------------------------------

#include "GUILabel.h"
#include "IEventHandler.h"

class GUIMeasurement : public GUILabel
{
protected:
	char *desc;
	char *unit;
	
	virtual void destroy()
	{
		delete title;
		delete desc;
		delete unit;
		View::destroy();
	}
public:

	GUIMeasurement(Rect _rect, COLOR _color, char *_desc, char *_unit)
		: GUILabel(_rect, _color, "---")
	{
		desc = (char*)malloc(sizeof(char) * strlen(_desc) + 1);
		unit = (char*)malloc(sizeof(char) * strlen(_unit) + 1);
		
		memcpy(desc, _desc, sizeof(char) * strlen(_desc) + 1);
		memcpy(unit, _unit, sizeof(char) * strlen(_unit) + 1);
		
		setValue("--");
	}
	
	void setText(char *_desc, char *_unit, const char *_data);
	void setText(const char *_data);
	
	virtual void onEvent(GUIEvent::Event _e, Rect _finger);
	void setValue(float _val);
	void setValue(int _val);
	void setValue(const char* _val);
};

#endif
//EOF
