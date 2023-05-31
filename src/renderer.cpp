#include <iostream>
#include <vector>
#include <string>
#include <format>

#include <SDL.h>

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_opengl3_loader.h"

#include "CBaseCard.h"
#include "cardlinker.h"
#include "windowlinker.h"

#include "renderer.h"

renderer::renderer(bool runImmediately = true) {
    // Step 1. Init SDL and create window
    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    this->window = SDL_CreateWindow("My window", 50, 50, 1024, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

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

void renderer::gui_init() {
    gui_run();
}

void renderer::gui_preruncycle() {
    // Step 4.2. ImGui stuff
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();
}

void renderer::gui_postruncycle() {
    // Step 4.3. Render the ImGui stuff
    ImGui::Render();

    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
}

void renderer::gui_run() {

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

        gui_preruncycle();
        if (ImGui::BeginMainMenuBar()) {
            if (ImGui::BeginMenu("Top Level menu")) {
                if (ImGui::BeginMenu("Sub-menu")) {
                    if (ImGui::MenuItem("Sub-menu item")) {}
                    ImGui::EndMenu();
                }
                if (ImGui::MenuItem("Top level menu item")) {}
                ImGui::EndMenu();
            }
            ImGui::EndMainMenuBar();
        }

        for (size_t i = 0; i < WindowLinker_Pairs.size(); i++)
        {
            #ifdef _DEBUG
            if (WindowLinker_Pairs[i]->window->getName() == "Debug Window") { WindowLinker_Pairs[i]->window->render();  continue; }
            #endif
            if (WindowLinker_Pairs[i]->window->open) WindowLinker_Pairs[i]->window->render();
        }

        gui_postruncycle();
    }
    gui_exit();
}

void renderer::gui_exit() {
    // Step 5. Shutdown
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
}