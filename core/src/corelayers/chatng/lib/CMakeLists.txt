set(CMAKE_QUICKCHAT_VERSION_MAJOR    1  CACHE INT "Major UreenQuick version number" FORCE)
set(CMAKE_QUICKCHAT_VERSION_MINOR    0  CACHE INT "Minor UreenQuick version number" FORCE)
set(CMAKE_QUICKCHAT_VERSION_PATCH    0  CACHE INT "Release UreenQuick version number" FORCE)
set(CMAKE_QUICKCHAT_VERSION_STRING "${CMAKE_QUICKCHAT_VERSION_MAJOR}.${CMAKE_QUICKCHAT_VERSION_MINOR}.${CMAKE_QUICKCHAT_VERSION_PATCH}" CACHE STRING "UreenQuick version string" FORCE)

file( GLOB SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )
file( GLOB HDR "${CMAKE_CURRENT_SOURCE_DIR}/*.h" )
file( GLOB FORMS "${CMAKE_CURRENT_SOURCE_DIR}/*.ui" )

set( QUICKCHAT_TYPE "SHARED" )
if( QUICKCHAT_BUILD_TYPE STREQUAL "STATIC" )
    set( QUICKCHAT_TYPE "STATIC" )
    message( STATUS "libUreenQuick will be linked staticaly" )
endif()
include_directories( ${CMAKE_CURRENT_BINARY_DIR} ${QT_INCLUDES})

find_package(Qt4 COMPONENTS Declarative QUIET)
qutim_wrap_cpp(MOC_SRC ${HDR})
qt4_wrap_ui(UIS_H ${FORMS})

add_library(ureenQuick ${QUICKCHAT_TYPE} ${SRC} ${MOC_SRC} ${UIS_H} ${HDR})

qutim_target_link_libraries(ureenQuick
    ${QT_LIBRARIES}
    ${QUTIM_LIBRARY}
	qutim-adiumwebview
    )


set_target_properties(ureenQuick PROPERTIES
    VERSION ${CMAKE_QUICKCHAT_VERSION_STRING}
    SOVERSION ${CMAKE_QUICKCHAT_VERSION_MAJOR}
    DEFINE_SYMBOL QUICKCHAT_LIBRARY
)

install( TARGETS ureenQuick
	RUNTIME DESTINATION bin
		COMPONENT Core
		LIBRARY DESTINATION lib${LIB_SUFFIX}
		COMPONENT Core
		ARCHIVE DESTINATION lib${LIB_SUFFIX}
		COMPONENT CoreDevel
	BUNDLE DESTINATION library
)

install(FILES ${HDR}
    DESTINATION ureen/quick
    COMPONENT CoreDevel
)
qutim_generate_includes("ureen/quick" ${HDR})
