//*******************************************************************
// IDrawable
//*******************************************************************

//-------------------------------------------------------------------

#include "GUIMeasurement.h"
#include <stdio.h>

void GUIMeasurement::setText(char *_desc, char *_unit, const char *_data)
{
	char *text = (char*)malloc(sizeof(char) * (strlen(_desc) + strlen(_unit) + strlen(_data) + 1));
	sprintf(text, "%s%s%s", _desc, _data, _unit);
	setTitle(text);
	delete text;
}

void GUIMeasurement::setText(const char *_data)
{
	setText(desc, unit, _data);
}

void GUIMeasurement::setValue(const char* _val)
{
	if (_val == NULL)
	{
		setText("--");
	}else
	{
		setText(_val);
	}
	redraw();
}

void GUIMeasurement::setValue(int _val)
{
	char tmp[15];
	snprintf(tmp, 15, "%d", _val);
	setText(tmp);
}

void GUIMeasurement::setValue(float _val)
{
	char tmp[15];
	snprintf(tmp, 15, "%.3f", _val);
	setText(tmp);
}

void GUIMeasurement::onEvent(GUIEvent::Event _e, Rect _finger)
{
	GUIView::onEvent(_e, _finger);
}

//EOF
