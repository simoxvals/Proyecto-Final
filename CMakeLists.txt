cmake_minimum_required(VERSION 3.16)

project(Juego VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Añadir Multimedia al listado de componentes requeridos
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Juego
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ventana.h
        ventana.cpp
        logindialog.h logindialog.cpp
        registerdialog.h registerdialog.cpp
        nivel.h nivel.cpp
        recursos.qrc
        personaje.h personaje.cpp


        nivel1.h nivel1.cpp

        objeto.h objeto.cpp
        bart.h bart.cpp
        gema.h gema.cpp
        parca.h parca.cpp
        hacha.h hacha.cpp
        fuego.h fuego.cpp













    )
else()
    if(ANDROID)
        add_library(Juego SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Juego
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Añadir Qt Multimedia a las bibliotecas vinculadas
target_link_libraries(Juego PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Multimedia)

# Opciones de macOS/iOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Juego)
endif()
set_target_properties(Juego PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Juego
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Juego)
endif()
