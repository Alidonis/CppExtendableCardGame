#include <imgui.h>

#include "windowlinker.h"

#include "BaseWindow.h"

void CBaseWindow::render()
{
	ImGui::Begin(getName(), &open, ImGuiWindowFlags_MenuBar);
	ImGui::Button("This is a button !");
	ImGui::End();
}


#ifdef _DEBUG
M_LINKWINDOW(CBaseWindow);
#endif // DEBUG

