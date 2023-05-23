#pragma once

class CWindowDebug : public CBaseWindow
{
public:
	CWindowDebug() { open = true; }
	~CWindowDebug() = default;

	void render() override;
	const char* getName() override { return "Debug Window"; }
};