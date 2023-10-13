#include <imgui.h>

#include "windowlinker.h"
#include "BaseWindow.h"

#include "cardlinker.h"

#include "MainMenuWindow.h"

void CMainmenuWindow::render()
{
	ImGui::Begin(getName(), &open, ImGuiWindowFlags_MenuBar);
	
	if (ImGui::BeginMenuBar()) 
	{
		if (ImGui::BeginMenu("Game"))
		{
			ImGui::MenuItem("Quit", "", false, false);
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Options"))
		{
			ImGui::MenuItem("...", "", false, false);
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Debug"))
		{
			if (ImGui::MenuItem("close main menu", "", false, true)) open = false;
			ImGui::MenuItem("...", "", false, false);
			ImGui::EndMenu();
		}
		ImGui::EndMenuBar();
	}

	ImGui::End();
}

M_LINKWINDOW(CMainmenuWindow);
