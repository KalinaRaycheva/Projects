cmake_minimum_required(VERSION 3.5.1)

project(starcraft)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/BattleField.h
        ${INC_DIR}/Defines.h
        ${INC_DIR}/Protoss.h
        ${INC_DIR}/Terran.h
        ${INC_DIR}/Vector.h
        ${INC_DIR}/Helper.h
        ${INC_DIR}/ProtossTurn.h
        ${INC_DIR}/TerranTurn.h

        ${SRC_DIR}/BattleField.c
        ${SRC_DIR}/main.c
        ${SRC_DIR}/ProtossTurn.c
        ${SRC_DIR}/ProtossShips.c
        ${SRC_DIR}/TerranTurn.c
        ${SRC_DIR}/TerranShips.c
        ${SRC_DIR}/Vector.c
        ${SRC_DIR}/Helper.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
