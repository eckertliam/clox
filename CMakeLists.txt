project(clox)

set(CMAKE_C_STANDARD 11)

add_executable(clox main.c common.h
        chunk.c chunk.h
        memory.c memory.h
        debug.h
        debug.c)
