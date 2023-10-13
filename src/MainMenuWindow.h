#pragma once

class CMainmenuWindow : public CBaseWindow
{
public:
	CMainmenuWindow() { open = true; closable = false; }
	~CMainmenuWindow() = default;

	void render() override;
	const char* getName() override { return "Main Menu"; }
};