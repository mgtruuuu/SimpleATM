cmake_minimum_required(VERSION 3.15)


project(SimpleATM VERSION 3.1)

add_library(SimpleATM_compiler_flags INTERFACE)
target_compile_features(SimpleATM_compiler_flags INTERFACE cxx_std_20)


set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(SimpleATM_compiler_flags INTERFACE
  -O2
  #"$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Werror;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Werror>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)








##########
##########


add_executable(SimpleATM 
  main.cpp 
  account.cpp
  bank.cpp
)

target_link_libraries(SimpleATM PUBLIC 
  SimpleATM_compiler_flags
)

target_include_directories(SimpleATM PUBLIC
  ${CMAKE_SOURCE_DIR} 
)






