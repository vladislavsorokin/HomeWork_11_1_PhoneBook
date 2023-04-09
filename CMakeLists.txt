cmake_minimum_required(VERSION 3.25)
project(phone_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(phone_book main.cpp FileHelper.h ConsoleHelper.h PhoneBook.h)
