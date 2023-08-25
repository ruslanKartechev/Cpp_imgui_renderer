#include "UserInterface.h"
#include "BubbleSortTester.h"

void UserInterface::Init()
{
	if (!glfwInit())
		return;
	InitImgui();
	window = glfwCreateWindow(1280, 720, "ImGui First app", nullptr, nullptr);
	if (window == nullptr)
		return;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync
	// Setup Dear ImGui context
	//IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	show_demo_window = true;
}

bool UserInterface::ShouldRender()
{
	return !glfwWindowShouldClose(window);
}

void UserInterface::InitImgui()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	IMGUI_CHECKVERSION();
}

void UserInterface::Shut()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void UserInterface::NewFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}


void UserInterface::Render()
{
	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(window, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(0x00004000);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	glfwSwapBuffers(window);
}

void UserInterface::Update()
{
	glfwPollEvents();
	NewFrame();
	if (show_demo_window)
		ImGui::ShowDemoWindow(&show_demo_window);
	ShowTestImage(&show_test_window);
}



void UserInterface::ShowTestImage(bool* p_open)
{
	const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
	ImVec2 window_pos = main_viewport->WorkPos;
	window_pos.x += 100;
	window_pos.y += 100;
	ImVec2 window_size = ImVec2(400, 400);
	ImGui::SetNextWindowPos(window_pos, ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(window_size, ImGuiCond_FirstUseEver);
	ImGui::Begin("Sort Algorithms");  // Create a window

	ImGui::Text("Button click count = %d", button_clicks_count);
	if (ImGui::Button("Sort"))
	{
		button_clicks_count++;
		BubbleSortTester tester;
		currentResult = tester.RunTest();
	}
	if (currentResult != nullptr)
	{
		ShowTable();
	}


	//static float f = 0.0f;
	//static int counter = 0;
	//ImGui::Begin("Sort Algorithms");                          // Create a window called "Hello, world!" and append into it.
	//ImGui::Text("SOME TEXT UP TOP");               // Display some text (you can use a format strings too)
	//ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
	//ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color
	//if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
	//	counter++;
	//ImGui::SameLine();
	//ImGui::Text("counter = %d", counter);
	//ImGui::Text("Some text here");
	ImGui::End();
}


void UserInterface::ShowTable()
{
	int rowCount = currentResult->unsorted->size();
	int columnCount = 3;
	if (ImGui::BeginTable("TABLE OF SORTED Ints", columnCount))
	{
		for (int y = 0; y < rowCount; y++)
		{
			//std::cout << "index: " << y  << " " << (*currentResult->unsorted)[y] << std::endl;
			ImGui::TableNextRow();
			ImGui::TableSetColumnIndex(0);
			ImGui::Text(" Index: %d ", y);
			ImGui::TableSetColumnIndex(1);
			ImGui::Text(" Raw: %d ", (*currentResult->unsorted)[y]);
			ImGui::TableSetColumnIndex(2);
			ImGui::Text(" Sorted: %d ", (*currentResult->sorted)[y]);
		}
		ImGui::EndTable();
	}
}
