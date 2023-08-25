#pragma once
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include "SortTesterResult.h"
#include "SortResultDiplayer.h"
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

// This example can also compile and run with Emscripten! See 'Makefile.emscripten' for details.
#ifdef __EMSCRIPTEN__
#include "../libs/emscripten/emscripten_mainloop_stub.h"
#endif


class UserInterface
{

public:
	void Init();
	void Render();
	void Update();
	void Shut();
	bool ShouldRender();
	static void InitImgui();

private:
	void NewFrame();
	void ShowTestImage(bool* p_open);
	void ShowTable();

private:
	const char* glsl_version = "#version 130";
	ImVec4 clear_color = ImVec4(0.2f, 0.f, 0.05f, 1.f);
	GLFWwindow* window;
	bool willRender;
	bool show_demo_window = true;
	bool show_test_window = true;
	int button_clicks_count;
	std::shared_ptr<SortTesterResult> currentResult;
};

