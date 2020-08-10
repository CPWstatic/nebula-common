############ Nebula defined options immutable during configure stage #############
message(STATUS ">>>> Options of ${PROJECT_NAME} <<<<")
option(ENABLE_TESTING                   "Build unit tests" ON)
option(ENABLE_CCACHE                    "Use ccache to speed up compiling" ON)
option(ENABLE_WERROR                    "Regard warnings as errors" ON)
option(ENABLE_JEMALLOC                  "Use jemalloc as memory allocator" ON)
option(ENABLE_ASAN                      "Build with AddressSanitizer" OFF)
option(ENABLE_UBSAN                     "Build with UndefinedBehaviourSanitizer" OFF)
option(ENABLE_TSAN                      "Build with ThreadSanitizer" OFF)
option(ENABLE_STATIC_ASAN               "Statically link against libasan" OFF)
option(ENABLE_STATIC_UBSAN              "Statically link against libubsan" OFF)
option(ENABLE_FUZZY_TESTING             "Enable Fuzzy tests" OFF)
option(ENABLE_FRAME_POINTER             "Build with frame pointer" OFF)
option(ENABLE_STRICT_ALIASING           "Build with -fstrict-aliasing" OFF)
option(ENABLE_COVERAGE                  "Build with coverage report" OFF)
option(ENABLE_PCH                       "Enable precompiled header" OFF)

message(STATUS "ENABLE_TESTING          : ${ENABLE_TESTING}")
message(STATUS "ENABLE_CCACHE           : ${ENABLE_CCACHE}")
message(STATUS "ENABLE_WERROR           : ${ENABLE_WERROR}")
message(STATUS "ENABLE_JEMALLOC         : ${ENABLE_JEMALLOC}")
message(STATUS "ENABLE_ASAN             : ${ENABLE_ASAN}")
message(STATUS "ENABLE_UBSAN            : ${ENABLE_UBSAN}")
message(STATUS "ENABLE_TSAN             : ${ENABLE_TSAN}")
message(STATUS "ENABLE_STATIC_ASAN      : ${ENABLE_STATIC_ASAN}")
message(STATUS "ENABLE_STATIC_UBSAN     : ${ENABLE_STATIC_UBSAN}")
message(STATUS "ENABLE_FUZZY_TESTING    : ${ENABLE_FUZZY_TESTING}")
message(STATUS "ENABLE_FRAME_POINTER    : ${ENABLE_FRAME_POINTER}")
message(STATUS "ENABLE_STRICT_ALIASING  : ${ENABLE_STRICT_ALIASING}")
message(STATUS "ENABLE_COVERAGE         : ${ENABLE_COVERAGE}")
message(STATUS "ENABLE_PCH              : ${ENABLE_PCH}")
