file(GLOB LIBQDIGIBIB_HDRS *.h )
file(GLOB LIBQDIGIBIB_SRCS *.cpp )

qt4_wrap_cpp( LIBQDIGIBIB_MOC_SRCS ${HDRS})

add_library( libqdigibib ${LIBQDIGIBIB_SRCS} ${LIBQDIGIBIB_MOC_SRCS} )

target_link_libraries(libqdigibib ${QT_LIBRARIES})
