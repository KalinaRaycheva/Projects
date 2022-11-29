cmake_minimum_required(VERSION 3.5.1)

project(warcraft)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Defines.h
        ${INC_DIR}/Hero.h
        ${INC_DIR}/SpellInit.h
        ${INC_DIR}/SpecialHeroAbilities.h
        ${INC_DIR}/CastSpell.h
       
        
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Hero.c
        ${SRC_DIR}/SpellInit.c
        ${SRC_DIR}/SpecialHeroAbilities.c
        ${SRC_DIR}/CastSpell.c
       
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  

set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})
