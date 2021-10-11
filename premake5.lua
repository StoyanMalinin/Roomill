workspace "Roomill"
    architecture "x86_64"
    configurations { "Debug", "Release" }

    project "Roomill"
        kind "ConsoleApp"
        language "C++"

        files 
        {
            "src/**.h",
            "src/**.cpp",
        }
    
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:Release"
            defines { "RELEASE" }
            optimize "On"

        outputdir = "bin/%{cfg.buildcfg}"
    