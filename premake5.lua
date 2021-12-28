workspace "Kernstuck"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Kernstuck/vendor/GLFW/include"

   include "Kernstuck/vendor/GLFW"

project "Kernstuck"
    location "Kernstuck"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("binint/" .. outputdir .. "/%{prj.name}")

    pchheader "khpc.h"
    pchsource "Kernstuck/src/khpc.cpp"
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
    }
	
	links 
	{ 
	
		
		"Dwmapi.lib",

		"GLFW",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "KS_PLATFORM_WINDOWS",
            "KS_BUILD_DLL",
            
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/FlappyBird")
        }

    filter "configurations:Debug"
        defines "KS_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "KS_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "KS_DIST"
        optimize "On"
    
project "FlappyBird"
        location "FlappyBird"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("binint/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }

        includedirs
        {
            "Kernstuck/vendor/spdlog/include",
            "Kernstuck/src"
        }

        links
        {
            "Kernstuck"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "KS_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "KS_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "KS_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "KS_DIST"
            optimize "On"

            


   
