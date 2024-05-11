cmake_minimum_required(VERSION 3.27)
project(DishSystem C)

set(CMAKE_C_STANDARD 11)

add_library(DishSystem STATIC library.c
        controller/CLogin.c
        controller/h/CLogin.h
        commmon/CTools.c
        commmon/h/CTools.h
        commmon/Screen.c
        commmon/h/Screen.h
        commmon/CRole.c
        commmon/h/CRole.h
        Screen/LoginScreen.c
        Screen/h/LoginScreen.h
        Screen/RegisterScreen.c
        Screen/h/RegisterScreen.h
        Screen/SelectScreen.c
        Screen/h/SelectScreen.h
        Screen/UpdateScreen.c
        Screen/h/UpdateScreen.h
)

