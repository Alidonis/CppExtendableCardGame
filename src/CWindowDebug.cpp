#ifdef _DEBUG
#include <format>
#include <imgui.h>

#include "windowlinker.h"
#include "BaseWindow.h"

#include "CBaseCard.h"
#include "cardlinker.h"

#include "CWindowDebug.h"

std::vector<std::string> Debug_Util_RegisteredCardNames(bool print = true, bool instanciate = false)
{
    std::vector<std::string> cardNames;
    if (print) { std::cout << "Print start" << std::endl; }
    for (size_t i = 0; i < CardLinker_Pairs.size(); i++)
    {
        cardNames.push_back(std::string(CardLinker_Pairs[i]->classname));
        if (print) { std::cout << std::string(CardLinker_Pairs[i]->classname) << std::endl; }
        if (instanciate) { CBaseCard* instantiationTest = CardLinker_Pairs[i]->factory(); std::cout << "Instantiated card name : " << instantiationTest->getName() << std::endl; delete instantiationTest; }
    }

    if (print) { std::cout << "Print end" << std::endl; }
    return cardNames;
}

void CWindowDebug::render()
{
    ImGui::Begin("Debug Window##renderer_debug", NULL, ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoCollapse);
    if (ImGui::BeginMenuBar())
    {
        if (ImGui::BeginMenu("Window"))
        {
            ImGui::MenuItem("...", "", false, false);
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
#endif