#include "CommonHeaders.h"

#include <SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"

#include "renderer.h"

int main(int argc, char** argv)
{
	//CEngine engine = CEngine();
	new renderer(true);
	return 0;
}