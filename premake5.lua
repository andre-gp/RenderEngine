-- Rendering Engine Configurations
workspace "RenderEngine"
    architecture "x64"
    startproject("Sandbox")
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "RenderEngine/vendor/GLFW/include"
IncludeDir["glad"] = "RenderEngine/vendor/glad/include"
IncludeDir["glm"] = "RenderEngine/vendor/glm/"


include "RenderEngine/vendor/GLFW" -- Includes the GLFW premake5 file.
                                    -- We add this project without workspace, or anything like that, just the project.

include "RenderEngine/vendor/glad"
include "RenderEngine/vendor/glm"

project "RenderEngine"
    location "RenderEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    -- Precompiled Headers
    pchheader "pchRender.h"
    pchsource "RenderEngine/src/pchRender.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "glad",
        "glm"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"

        postbuildcommands
        {
            -- Copy files to Sandbox
            ("{RMDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
            ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "RE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RE_RELEASE"
        optimize "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "RenderEngine/vendor/spdlog/include",
        "RenderEngine/src"
    }
    
    links
    {
        "RenderEngine"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions "/utf-8"
            
    filter "configurations:Debug"
        defines "RE_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "RE_RELEASE"
        optimize "On"