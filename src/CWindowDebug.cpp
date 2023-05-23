#include <format>
#include <imgui.h>

#include "windowlinker.h"
#include "BaseWindow.h"

#include "CWindowDebug.h"

void CWindowDebug::render()
{
    ImGui::Begin("Debug Window##renderer_debug", &open, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_UnsavedDocument);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
    }

    /*if (ImGui::Button("Test Card Linker [Print]")) { Debug_Util_RegisteredCardNames(true, false); }
    if (ImGui::Button("Test Card Linker [Instanciate]")) { Debug_Util_RegisteredCardNames(false, true); }
    if (ImGui::Button("Test Card Linker [Print, Instanciate]")) { Debug_Util_RegisteredCardNames(true, true); }
    */

    for (size_t i = 0; i < WindowLinker_Pairs.size(); i++)
    {
        if (WindowLinker_Pairs[i]->window->getName() == getName()) continue;
        if (ImGui::Button(std::format("{}{}", WindowLinker_Pairs[i]->window->getName(), "##debug").c_str()))
        {
            WindowLinker_Pairs[i]->window->open = true;
        }
    }

    ImGui::End();
}

M_LINKWINDOW(CWindowDebug);