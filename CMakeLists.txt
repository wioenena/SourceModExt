CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(L4D2Extension)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

SET(MS_SDK "${CMAKE_SOURCE_DIR}/sdks/metamod-source")
SET(HL2SDK "${CMAKE_SOURCE_DIR}/sdks/hl2-l4d2")
SET(SM_SDK "${CMAKE_SOURCE_DIR}/sdks/sourcemod")

INCLUDE_DIRECTORIES(
    ${CMAKE_SOURCE_DIR}/src
    # Metamod Source
    ${MS_SDK}/core
    ${MS_SDK}/core/sourcehook

    # SourceMod
    ${SM_SDK}/sourcepawn/include
    ${SM_SDK}/public
    ${SM_SDK}/public/amtl/amtl
    ${SM_SDK}/public/amtl

    # Half-Life 2 SDK L4D2
    ${HL2SDK}/public
    ${HL2SDK}/public/tier0
    ${HL2SDK}/public/tier1
)

ADD_COMPILE_OPTIONS(
    -m32 -fPIC -g -w
    -D_LINUX
    -Dstricmp=strcasecmp
    -D_vsnprintf=vsnprintf
)

LINK_DIRECTORIES(${HL2SDK}/lib/linux)
SET(
    CMAKE_SHARED_LINKER_FLAGS
    "${CMAKE_SHARED_LINKER_FLAGS} -static-libstdc++"
)

SET(SDK_SOURCES
    ${SM_SDK}/public/smsdk_ext.cpp
)

SET(SOURCE_FILES src/extension.cpp ${SDK_SOURCES})

ADD_LIBRARY(L4D2Extension SHARED ${SOURCE_FILES})

SET_TARGET_PROPERTIES(L4D2Extension PROPERTIES
    PREFIX ""
)
SET_TARGET_PROPERTIES(L4D2Extension PROPERTIES
    CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
