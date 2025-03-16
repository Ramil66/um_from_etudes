cmake_minimum_required(VERSION 3.14)

project(UM-1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(UM-1
  main.cpp
  Memory.h
  Command.h
  Command.cpp
  Types.h
  Memory.cpp
  Processor.h
  Processor.cpp
  Commands/memorycommands.h
  Commands/memorycommands.cpp
  Commands/logicalcommands.h
  Commands/logicalcommands.cpp
  Commands/transitioncommands.h
  Commands/transitioncommands.cpp
  Commands/shiftcommands.h
  Commands/shiftcommands.cpp
  Commands/comparecommands.h
  Commands/comparecommands.cpp
  Commands/arithmeticcommands.h
  Commands/arithmeticcommands.cpp
  Commands/othercommands.h
  Commands/othercommands.cpp
  psw.cpp
  psw.h
  programm
  logs.h
  logs.cpp
  except.h
  assembly.h assembly.cpp

)
target_link_libraries(UM-1 Qt${QT_VERSION_MAJOR}::Core)



install(TARGETS UM-1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
