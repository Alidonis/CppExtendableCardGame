#pragma once

class CMainmenuWindow : public CBaseWindow
{
public:
	CMainmenuWindow() { open = true; }
	~CMainmenuWindow() = default;

	void render() override;
	const char* getName() override { return "Main Menu"; }
};