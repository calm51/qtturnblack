
# =============================================
if (WIN32)
    message("CMAKE_CXX_COMPILER_ID ${CMAKE_CXX_COMPILER_ID}") # PRE_BUILD | PRE_LINK | POST_BUILD
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND python "${CMAKE_SOURCE_DIR}/../scripts/make-output/cpp-lib.py" win32msvc ${PROJECT_NAME} ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND python "${CMAKE_SOURCE_DIR}/../scripts/make-output/cpp-lib.py" win32mingw ${PROJECT_NAME} ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})
    endif ()
    set_target_properties(qtturnblack PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS TRUE
    )
elseif (ANDROID)
    set(ANDROID_ABI armeabi-v7a)
    set(ANDROID_NATIVE_API_LEVEL 21)
    ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND python3 "${CMAKE_SOURCE_DIR}/../scripts/make-output/cpp-lib.py" android ${PROJECT_NAME} ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})
else()
    ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD COMMAND python3 "${CMAKE_SOURCE_DIR}/../scripts/make-output/cpp-lib.py" linux64 ${PROJECT_NAME} ${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR})
endif()
# =============================================




