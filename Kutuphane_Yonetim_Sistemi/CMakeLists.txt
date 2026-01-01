cmake_minimum_required(VERSION 3.16)

project(Kutuphane_Yonetim_Sistemi LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Kutuphane_Yonetim_Sistemi main.cpp
    Soru_Belgesi)

include(GNUInstallDirs)
install(TARGETS Kutuphane_Yonetim_Sistemi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
