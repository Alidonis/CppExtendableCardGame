#pragma once
#include "CommonHeaders.h"
#include "BaseWindow.h"

struct windowsPair;
inline std::vector<windowsPair*> WindowLinker_Pairs;

struct windowsPair
{
	windowsPair(CBaseWindow* _window)
		: window(_window)
	{
		WindowLinker_Pairs.push_back(this);
	}

	CBaseWindow* window;
};

#define M_LINKWINDOW(dllclass) \
    windowsPair __windowLst##dllclass = windowsPair( new dllclass() )