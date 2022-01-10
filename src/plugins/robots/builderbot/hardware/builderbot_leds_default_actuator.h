/**
 * @file <argos3/plugins/robots/builderbot/hardware/builderbot_leds_default_actuator.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef BUILDERBOT_LEDS_DEFAULT_ACTUATOR_H
#define BUILDERBOT_LEDS_DEFAULT_ACTUATOR_H

namespace argos {
   class CBuilderBotLEDsDefaultActuator;
}

#include <cmath>
#include <optional>

#include <argos3/core/utility/datatypes/color.h>
#include <argos3/plugins/robots/builderbot/hardware/actuator.h>
#include <argos3/plugins/robots/builderbot/control_interface/ci_builderbot_leds_actuator.h>

namespace argos {

   class CBuilderBotLEDsDefaultActuator : public CPhysicalActuator,
                                          public CCI_BuilderBotLEDsActuator {

   public:

      /**
       * @brief Constructor.
       */
      CBuilderBotLEDsDefaultActuator();

      /**
       * @brief Destructor.
       */
      virtual ~CBuilderBotLEDsDefaultActuator();

      void Init(TConfigurationNode& t_tree) override;

      void Destroy() override;

      void Update() override;

      void Reset() override;

      void SetLEDIndex(UInt32 un_index, const CColor& c_color) override;

      void SetLEDs(const CColor& c_color) override;

   private:

      struct SLED {
         SLED(UInt32 un_index):
            RedBrightnessPath("/sys/class/leds/pca963x:led" + std::to_string(un_index) + "r/brightness"),
            GreenBrightnessPath("/sys/class/leds/pca963x:led" + std::to_string(un_index) + "g/brightness"),
            BlueBrightnessPath("/sys/class/leds/pca963x:led" + std::to_string(un_index) + "b/brightness") {}
         std::string RedBrightnessPath;
         std::string GreenBrightnessPath;
         std::string BlueBrightnessPath;
         std::optional<CColor> Configuration;
      };

      std::array<SLED, CCI_BuilderBotLEDsActuator::NUM_LEDS> m_arrLEDs;

   };
}

#endif
