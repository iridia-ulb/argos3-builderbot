#
# Check ARGoS
#
find_package(ARGoS REQUIRED builderbot)
include_directories(${ARGOS_INCLUDE_DIRS})
link_directories(${ARGOS_LIBRARY_DIR})
link_libraries(${ARGOS_LDFLAGS})

#
# Find the AprilTag library
#
find_package(AprilTag)
if(NOT APRILTAG_FOUND)
  message(FATAL_ERROR "Required library AprilTag not found.")
endif(NOT APRILTAG_FOUND)
include_directories(${APRILTAG_INCLUDE_DIR})

#
# Find Analog Device's IIO library
#
find_package(IIO)
if(NOT IIO_FOUND)
  message(FATAL_ERROR "Required library IIO not found.")
endif(NOT IIO_FOUND)
include_directories(${IIO_INCLUDE_DIR})

#
# Find the V4L2 Sub-device library
#
find_package(V4L2Subdev)
if(NOT V4L2SUBDEV_FOUND)
  message(FATAL_ERROR "Required V4L2 Sub-device library not found.")
endif(NOT V4L2SUBDEV_FOUND)

#
# Find the Mediactl library
#
find_package(Mediactl)
if(NOT MEDIACTL_FOUND)
  message(FATAL_ERROR "Required library Mediactl not found.")
endif(NOT MEDIACTL_FOUND)
include_directories(${MEDIACTL_INCLUDE_DIR})


