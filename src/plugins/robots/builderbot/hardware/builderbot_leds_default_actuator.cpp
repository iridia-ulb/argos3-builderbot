/**
 * @file <argos3/plugins/robots/builderbot/hardware/builderbot_leds_default_actuator.cpp>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#include "builderbot_leds_default_actuator.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/plugins/robots/builderbot/hardware/robot.h>

#include <cmath>
#include <cerrno>

namespace argos {

   /****************************************/
   /****************************************/

   CBuilderBotLEDsDefaultActuator::CBuilderBotLEDsDefaultActuator() :
      m_arrLEDs {
         SLED(0), SLED(1), SLED(2), SLED(3),
         SLED(4), SLED(5), SLED(6), SLED(7),
         SLED(8), SLED(9), SLED(10), SLED(11),
      } {}

   /****************************************/
   /****************************************/

   CBuilderBotLEDsDefaultActuator::~CBuilderBotLEDsDefaultActuator() {}

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::Init(TConfigurationNode& t_tree) {
      try {
         CCI_BuilderBotLEDsActuator::Init(t_tree);
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Initialization error in the BuilderBot leds actuator.", ex);
      }
   }

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::Destroy() {}

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::Update() {
      for(SLED& s_led : m_arrLEDs) {
         if(s_led.Configuration) {
            const CColor& cColor = s_led.Configuration.value();
            std::ofstream(s_led.RedBrightnessPath) << static_cast<SInt32>(cColor.GetRed());
            std::ofstream(s_led.GreenBrightnessPath) << static_cast<SInt32>(cColor.GetGreen());
            std::ofstream(s_led.BlueBrightnessPath) << static_cast<SInt32>(cColor.GetBlue());
            s_led.Configuration.reset();
         }
      }
   }

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::Reset() {
      for(SLED& s_led : m_arrLEDs) {
         const CColor& cColor = CColor::BLACK;
         std::ofstream(s_led.RedBrightnessPath) << static_cast<SInt32>(cColor.GetRed());
         std::ofstream(s_led.GreenBrightnessPath) << static_cast<SInt32>(cColor.GetGreen());
         std::ofstream(s_led.BlueBrightnessPath) << static_cast<SInt32>(cColor.GetBlue());
         s_led.Configuration.reset();
      }
   }

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::SetLEDIndex(UInt32 un_index, const CColor& c_color) {
      if(un_index < NUM_LEDS) {
         m_arrLEDs[un_index].Configuration.emplace(c_color);
      }
      else {
         LOGERR << "[ERROR] BuilderBot LED index out of range" << std::endl;
      }
   }

   /****************************************/
   /****************************************/

   void CBuilderBotLEDsDefaultActuator::SetLEDs(const CColor& c_color) {
      for(UInt32 un_index = 0; un_index < NUM_LEDS; un_index++) {
         m_arrLEDs[un_index].Configuration.emplace(c_color);
      }
   }

   /****************************************/
   /****************************************/

}

REGISTER_ACTUATOR(CBuilderBotLEDsDefaultActuator,
                  "builderbot_leds", "default",
                  "Michael Allwright [allsey87@gmail.com]",
                  "1.0",
                  "The BuilderBot leds actuator.",
                  "This actuator controls the leds on the BuilderBot.",
                  "Usable"
);
