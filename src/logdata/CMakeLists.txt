add_library(logdata STATIC
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/abstractlogdata.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/blockpool.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/compressedlinestorage.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/encodingdetector.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/linepositionarray.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/loadingstatus.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/logdata.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/logdataworker.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/logfiltereddata.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/logfiltereddataworker.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/marks.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/linetypes.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/fileholder.h
         ${CMAKE_CURRENT_SOURCE_DIR}/include/data/filedigest.h


        ${CMAKE_CURRENT_SOURCE_DIR}/src/abstractlogdata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/blockpool.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/compressedlinestorage.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/encodingdetector.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logdata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logdataworker.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logfiltereddata.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/logfiltereddataworker.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/marks.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/fileholder.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/filedigest.cpp

        src/filedigest.cpp)

set_target_properties(logdata PROPERTIES AUTOMOC ON)

target_include_directories(logdata PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(logdata PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/data")

target_link_libraries(logdata PUBLIC
        Qt5::Core
        Qt5::Concurrent
        immer
        tbb_static
        named_type
        absl::optional
        absl::variant
        utils
        filewatch
        uchardet)

target_link_libraries(logdata PRIVATE xxHash::xxhash)


if (${USE_LTO})
set_property(TARGET logdata PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()
