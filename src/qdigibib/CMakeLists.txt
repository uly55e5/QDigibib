file(GLOB QDIGIBIB_HDRS *.h )
file(GLOB QDIGIBIB_SRCS *.cpp )
file(GLOB QDIGIBIB_UIS *.ui)

qt4_wrap_cpp( QDIGIBIB_MOC_SRCS ${QDIGIBIB_HDRS})
qt4_wrap_ui( QDIGIBIB_UI_HDRS ${QDIGIBIB_UIS} )

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable( qdigibib ${QDIGIBIB_SRCS} ${QDIGIBIB_MOC_SRCS} ${QDIGIBIB_UI_HDRS})

target_link_libraries( qdigibib libqdigibib ${QT_LIBRARIES})