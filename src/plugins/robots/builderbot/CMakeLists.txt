#
# BuilderBot headers
#
# argos3/plugins/robots/builderbot
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_BUILDERBOT_HARDWARE
  hardware/actuator.h
  hardware/builderbot_camera_system_default_sensor.h
  hardware/builderbot_differential_drive_default_actuator.h
  hardware/builderbot_differential_drive_default_sensor.h
  hardware/builderbot_electromagnet_system_default_actuator.h
  hardware/builderbot_electromagnet_system_default_sensor.h
  hardware/builderbot_leds_default_actuator.h
  hardware/builderbot_lift_system_default_actuator.h
  hardware/builderbot_lift_system_default_sensor.h
  hardware/builderbot_system_default_sensor.h
  hardware/builderbot_rangefinders_default_sensor.h
  hardware/robot.h
  hardware/sensor.h
  hardware/simple_radios_default_actuator.h
  hardware/simple_radios_default_sensor.h)

#
# BuilderBot sources
#
# argos3/plugins/robots/builderbot/hardware
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_BUILDERBOT
  ${ARGOS3_SOURCES_PLUGINS_ROBOTS_BUILDERBOT}
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_BUILDERBOT_HARDWARE}
  hardware/builderbot_camera_system_default_sensor.cpp
  hardware/builderbot_differential_drive_default_actuator.cpp
  hardware/builderbot_differential_drive_default_sensor.cpp
  hardware/builderbot_electromagnet_system_default_actuator.cpp
  hardware/builderbot_electromagnet_system_default_sensor.cpp
  hardware/builderbot_leds_default_actuator.cpp
  hardware/builderbot_lift_system_default_actuator.cpp
  hardware/builderbot_lift_system_default_sensor.cpp
  hardware/builderbot_system_default_sensor.cpp
  hardware/builderbot_rangefinders_default_sensor.cpp
  hardware/main.cpp
  hardware/robot.cpp
  hardware/simple_radios_default_actuator.cpp
  hardware/simple_radios_default_sensor.cpp)

# Create an executable for the robot
add_executable(argos3 ${ARGOS3_SOURCES_PLUGINS_ROBOTS_BUILDERBOT})
target_link_libraries(argos3 stdc++fs
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot
  argos3plugin_${ARGOS_BUILD_FOR}_builderbot
  ${APRILTAG_LIBRARY}
  ${IIO_LIBRARY}
  ${MEDIACTL_LIBRARY}
  ${V4L2SUBDEV_LIBRARY})
  
# Install executable and header files
install(TARGETS argos3
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_BUILDERBOT_HARDWARE} DESTINATION include/argos3/plugins/robots/builderbot/hardware)
