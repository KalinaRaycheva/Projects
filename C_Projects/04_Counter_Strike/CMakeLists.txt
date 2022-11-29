cmake_minimum_required(VERSION 3.5.1)

project(counter_strike)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/BattleField.h
        ${INC_DIR}/Player.h
        ${INC_DIR}/PlayerInit.h
        ${INC_DIR}/Vector.h
       
        ${INC_DIR}/pistols/DesertEagle.h
        ${INC_DIR}/pistols/Fire.h
        ${INC_DIR}/pistols/Glock.h
        ${INC_DIR}/pistols/Pistol.h
        ${INC_DIR}/pistols/PistolCommonFunctionality.h
        
        ${SRC_DIR}/BattleField.c
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Player.c
        ${SRC_DIR}/PlayersInit.c
        ${SRC_DIR}/Vector.c

        ${SRC_DIR}/pistols/DesertEagle.c
        ${SRC_DIR}/pistols/Fire.c
        ${SRC_DIR}/pistols/Glock.c
        ${SRC_DIR}/pistols/PistolCommonFunctionality.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
