#pragma once

class renderer
{
public:
	renderer(bool runImmediately);
	~renderer() = default;

	void gui_init();
private:
	SDL_Window* window;
	ImGuiIO io;
	SDL_GLContext glContext;

	std::vector<std::string> texts;

	bool devmode = false;
	char textInOut[32]{};

	bool gui_active = true;
	bool windowExists = true;

	void gui_run();
	void gui_preruncycle();
	void gui_postruncycle();

	void gui_exit();
};