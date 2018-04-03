include( ExternalProject )

set( URL
  "https://dl.bintray.com/boostorg/release/1.66.0/source/boost_1_66_0.tar.bz2" )
set( SHA256 "5721818253e6a0989583192f96782c4a98eb6204965316df9f5ad75819225ca9" )
set( INSTALL_DIR ${CMAKE_CURRENT_BINARY_DIR}/boost )
set( INCLUDE_DIR ${INSTALL_DIR}/include )
set( LIB_DIR ${INSTALL_DIR}/lib )

ExternalProject_Add( external_boost
        PREFIX boost
        URL ${URL}
        URL_HASH SHA256=${SHA256}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND cp -r <SOURCE_DIR>/boost ${INCLUDE_DIR}/.
)

file(MAKE_DIRECTORY ${INCLUDE_DIR})

add_library(boost INTERFACE IMPORTED GLOBAL)
add_dependencies(boost external_boost)
set_target_properties(boost PROPERTIES
                      INTERFACE_INCLUDE_DIRECTORIES ${INCLUDE_DIR}
                      INTERFACE_SYSTEM_INCLUDE_DIRECTORIES ${INCLUDE_DIR})
