set(libs_files
    geometrys.cpp geometrys.h
    list.cpp  list.h
        maincycle.cpp maincycle.h
)

add_library(LibsModule ${libs_files})
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

target_include_directories(LibsModule PUBLIC include)
