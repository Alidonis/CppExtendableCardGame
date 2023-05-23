#pragma once
class CBaseWindow
{
public:
	~CBaseWindow() = default;

	bool open = false;
	virtual void render();
	virtual const char* getName() { return "Base Window"; }
};

