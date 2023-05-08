#include <SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"

#include <iostream>
#include <vector>
#include <string>

#include "testGui.h"
#include <format>

testGui::testGui(bool runImmediately = true) {
    // Step 1. Init SDL and create window
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    this->window = SDL_CreateWindow("My window", 50, 50, 1024, 768, SDL_WINDOW_OPENGL);

    // Step 2. Create OpenGL context
    this->glContext = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, glContext);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    // Step 3. Initialise ImGui
    ImGui::CreateContext();
    this->io = ImGui::GetIO();
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, glContext);
    ImGui_ImplOpenGL3_Init("#version 130");
    if (runImmediately) { gui_init(); }
}

void testGui::gui_init() {
    gui_run();
}

void testGui::gui_run() {
    

    bool windowExists = true;
    while (windowExists) {
        // Step 4.1. Poll for events
        SDL_Event ev;
        while (SDL_PollEvent(&ev))
        {
            ImGui_ImplSDL2_ProcessEvent(&ev);

            if (ev.type == SDL_QUIT)
            {
                windowExists = false;
                break;
            }
        }

        // Step 4.2. ImGui stuff
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("My First Tool", &gui_active, ImGuiWindowFlags_MenuBar);
        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("Window"))
            {
                if (ImGui::MenuItem("Quit", "N/A")) { gui_active = false; windowExists = false; }
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Options"))
            {
                if (!devmode) 
                    if (ImGui::MenuItem("Enable devmode", "N/A")) { devmode = true; }
                ImGui::EndMenu();
            }
            ImGui::EndMenuBar();
        }

        ImGui::InputText("##AddListIn", textInOut, sizeof(textInOut));
        ImGui::SameLine();
        if (ImGui::Button("Add")) { texts.push_back(std::string(textInOut)); strcpy_s(textInOut, ""); }
        ImGui::BeginChild("Scrolling");
        for (int n = 1; n < texts.size() + 1; n++) 
        {
            ImGui::Text(texts[n - 1].c_str());
            ImGui::SameLine();
            if (ImGui::Button(std::string("Delete##" + std::to_string(n)).c_str())) { texts.erase(texts.begin() + (n - 1)); }
        }
            
        ImGui::EndChild();
        ImGui::End();

        // Step 4.3. Render the ImGui stuff
        ImGui::Render();

        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);
    }
    gui_exit();
}

void testGui::gui_exit() {
    // Step 5. Shutdown
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
}