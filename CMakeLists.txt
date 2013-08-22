cmake_minimum_required (VERSION 2.8.3)

project (ck2launcher)

if (NOT WIN32)
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Wwrite-strings -Wconversion -std=c++11")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-sign-conversion -Wno-sign-compare -Wno-nested-anon-types -fPIE")
endif (NOT WIN32)

find_package (Qt5Core REQUIRED)
find_package (Qt5Widgets REQUIRED)
find_package (Qt5WebKitWidgets REQUIRED)

find_package (Boost 1.50 COMPONENTS filesystem system regex REQUIRED)

file (GLOB sources src/*.cpp)
file (GLOB ui ui/*.ui)
file (GLOB gui src/gui/*.cpp)
file (GLOB qrc resources/*.qrc)
file (GLOB gui_moc include/gui/*.hpp)

qt5_wrap_cpp (gui_moc ${gui_moc})
qt5_wrap_ui (ui ${ui})

qt5_add_resources (qrc ${qrc})

include_directories (${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/include ${Boost_INCLUDE_DIR})

add_executable (ck2launcher ${sources} ${gui_moc} ${gui} ${ui} ${qrc})

qt5_use_modules (ck2launcher Gui WebKitWidgets)

target_link_libraries (ck2launcher ${Boost_LIBRARIES})

install (TARGETS ck2launcher DESTINATION bin)
