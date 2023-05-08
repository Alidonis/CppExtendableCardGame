#pragma once

class testGui
{
public:
	testGui(bool runImmediately);
	~testGui() = default;

	void gui_init();
private:
	SDL_Window* window;
	ImGuiIO io;
	SDL_GLContext glContext;

	std::vector<std::string> texts;

	bool devmode = false;
	char textInOut[32]{};
	float my_color[4];

	bool gui_active = true;

	void gui_run();
	void gui_exit();
};