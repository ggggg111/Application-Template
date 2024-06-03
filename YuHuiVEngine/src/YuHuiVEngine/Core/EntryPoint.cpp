#pragma once

#include "YuHuiVEngine/Core/Base.h"
#include "YuHuiVEngine/Core/Application.h"

Yuhui::Application *App = nullptr;

int main(int argc, char **argv)
{
	App = new Yuhui::Application();
	App->Run();
	delete App;

	return 0;
}