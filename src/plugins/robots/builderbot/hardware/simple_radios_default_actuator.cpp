/**
 * @file <argos3/plugins/robots/builderbot/hardware/simple_radios_default_actuator.cpp>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#include "simple_radios_default_actuator.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/core/utility/networking/tcp_socket.h>
#include <argos3/plugins/robots/builderbot/hardware/robot.h>

namespace argos {

   /****************************************/
   /****************************************/

   const std::string CSimpleRadiosDefaultActuator::NFC_DEVICE_PATH("/dev/nfc");

   /****************************************/
   /****************************************/

   void CSimpleRadiosDefaultActuator::Init(TConfigurationNode& t_tree) {
      try {
         /* Parent class init */
         CCI_SimpleRadiosActuator::Init(t_tree);
         if(!CRobot::GetInstance().GetSocket().IsConnected()) {
            LOGERR << "[WARNING] Robot is not connected to a router" << std::endl;
         }
         m_vecInterfaces.emplace_back("wifi"); // 0
         m_vecInterfaces.emplace_back("nfc"); // 1
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Error initializing the radio default actuator", ex);
      }
   }

   
   /****************************************/
   /****************************************/

   void CSimpleRadiosDefaultActuator::Update() {
      /* send wifi messages if the socket is connected */
      if(CRobot::GetInstance().GetSocket().IsConnected()) {
         for(const CByteArray& c_message : m_vecInterfaces[0].Messages) {
            CRobot::GetInstance().GetSocket().SendByteArray(c_message);
         }
         /* Flush data from the control interface */
         m_vecInterfaces[0].Messages.clear();
      }
      /* send nfc messages */
      for(const CByteArray& c_message : m_vecInterfaces[1].Messages) {
         std::ofstream cStream(NFC_DEVICE_PATH, std::ofstream::binary);
         cStream.write(reinterpret_cast<const char*>(c_message.ToCArray()), c_message.Size());
      }
      m_vecInterfaces[1].Messages.clear();
   }

   /****************************************/
   /****************************************/

   void CSimpleRadiosDefaultActuator::Reset() {
      m_vecInterfaces[0].Messages.clear();
      m_vecInterfaces[1].Messages.clear();
   }

   /****************************************/
   /****************************************/

   REGISTER_ACTUATOR(CSimpleRadiosDefaultActuator,
                     "simple_radios", "default",
                     "Michael Allwright [allsey87@gmail.com]",
                     "1.0",
                     "Hardware implementation of the simple radio actuator.",
                     "This actuator sends messages to other robots using the local network\n"
                     "and the BuilderBot's NFC interface.",
                     "Usable"
   );

   /****************************************/
   /****************************************/

}
   
