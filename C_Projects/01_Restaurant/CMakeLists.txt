cmake_minimum_required(VERSION 3.5.1)

project(restaurant)

set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
     
#generate project binary
add_executable(
    ${PROJECT_NAME}
        ${INC_DIR}/Customer.h
        ${INC_DIR}/CustomersList.h
        ${INC_DIR}/defines.h
        ${INC_DIR}/Dish.h
        ${INC_DIR}/DishQueue.h
        ${INC_DIR}/Fridge.h
        ${INC_DIR}/Kitchen.h
        ${INC_DIR}/Menu.h
        ${INC_DIR}/restaurant.h
        ${INC_DIR}/tables.h

        ${SRC_DIR}/Customer.c
        ${SRC_DIR}/CustomersList.c
        ${SRC_DIR}/Dish.c
        ${SRC_DIR}/DishQueue.c
        ${SRC_DIR}/Fridge.c
        ${SRC_DIR}/Kitchen.c
        ${SRC_DIR}/main.c
        ${SRC_DIR}/Menu.c
        ${SRC_DIR}/restaurant.c
        ${SRC_DIR}/tables.c
)

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  


set_target_c_standard(${PROJECT_NAME} 11)
enable_target_c_warnings(${PROJECT_NAME})