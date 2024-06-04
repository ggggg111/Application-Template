project(YuhuiVEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
	BEFORE
	src
	vendor/spdlog/include
)

add_executable(
	${PROJECT_NAME}
	src/yhvpch.h
	src/yhvpch.cpp
	src/YuHuiVEngine/Core/EntryPoint.cpp
	src/YuHuiVEngine/Core/Base.h
	src/YuHuiVEngine/Core/Application.h
	src/YuHuiVEngine/Core/Application.cpp
	src/YuHuiVEngine/Core/LayerStack.h
	src/YuHuiVEngine/Core/LayerStack.cpp
	src/YuHuiVEngine/Core/Logger.h
	src/YuHuiVEngine/Core/Logger.cpp
	src/YuHuiVEngine/Modules/Module.h
	src/YuHuiVEngine/Modules/Window.h
	src/YuHuiVEngine/Modules/Window.cpp
	src/YuHuiVEngine/Modules/Renderer.h
	src/YuHuiVEngine/Modules/Renderer.cpp
	src/YuHuiVEngine/Layers/Layer.h
	src/YuHuiVEngine/Layers/Layer.cpp
	src/YuHuiVEngine/Layers/ImGuiLayer.h
	src/YuHuiVEngine/Layers/ImGuiLayer.cpp
)

set(DEBUG_ONLY_DEFINITIONS $<$<CONFIG:Debug>:YHD_DEBUG>)
set(RELEASE_ONLY_DEFINITIONS $<$<CONFIG:Release>:YHD_DIST>)
set(DIST_ONLY_DEFINITIONS $<$<CONFIG:RelWithDebInfo>:YHD_RELEASE>)

target_compile_definitions(
	${PROJECT_NAME}
	PUBLIC
	ASSETS_PATH="${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/assets/"
	${DEBUG_ONLY_DEFINITIONS}
	${RELEASE_ONLY_DEFINITIONS}
	${DIST_ONLY_DEFINITIONS}
)

target_precompile_headers(${PROJECT_NAME} PRIVATE src/yhvpch.h)

add_subdirectory(vendor/spdlog)

target_link_libraries(
	${PROJECT_NAME}
	spdlog
)