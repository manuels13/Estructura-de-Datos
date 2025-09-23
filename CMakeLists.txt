cmake_minimum_required(VERSION 3.20) # Version minima de cmake

project(nombreDelProyecto) # Nombre del proyecto

add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)  # Para todo el proyecto, las opciones de compilacion

add_executable(lista lista.c listaenlazada.c) # Añadir ejecutable, tantos como tengas en tu workspace. 