/**
 * @file <argos3/plugins/robots/crazyflie/simulator/crazyflie_entity.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef CRAZYFLIE_ENTITY_H
#define CRAZYFLIE_ENTITY_H

namespace argos {
   class CControllableEntity;
   class CEmbodiedEntity;
   class CCrazyflieEntity;
   class CQuadRotorEntity;
   class CRABEquippedEntity;
   class CPerspectiveCameraEquippedEntity;
   class CBatteryEquippedEntity;
   class CCrazyflieDistanceScannerEquippedEntity;
}

#include <argos3/core/simulator/entity/composable_entity.h>

namespace argos {

   class CCrazyflieEntity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

   public:

      CCrazyflieEntity();

      CCrazyflieEntity(const std::string& str_id,
                   const std::string& str_controller_id,
                   const CVector3& c_position = CVector3(),
                   const CQuaternion& c_orientation = CQuaternion(),
                   Real f_rab_range = 3.0f,
                   size_t un_rab_data_size = 10,
                   const std::string& str_bat_model = "",
                   const CRadians& c_cam_aperture = ToRadians(CDegrees(30.0f)),
                   Real f_cam_range = 10.0f);

      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();

      inline CControllableEntity& GetControllableEntity() {
         return *m_pcControllableEntity;
      }

      inline CEmbodiedEntity& GetEmbodiedEntity() {
         return *m_pcEmbodiedEntity;
      }

      inline CQuadRotorEntity& GetQuadRotorEntity() {
         return *m_pcQuadRotorEntity;
      }

      inline CRABEquippedEntity& GetRABEquippedEntity() {
         return *m_pcRABEquippedEntity;
      }

      inline CPerspectiveCameraEquippedEntity& GetPerspectiveCameraEquippedEntity() {
         return *m_pcPerspectiveCameraEquippedEntity;
      }

      inline CBatteryEquippedEntity& GetBatterySensorEquippedEntity() {
          return *m_pcBatteryEquippedEntity;
      }

      inline CCrazyflieDistanceScannerEquippedEntity& GetCrazyflieDistanceScannerEquippedEntity() {
         return *m_pcCrazyflieDistanceScannerEquippedEntity;
      }

      virtual std::string GetTypeDescription() const {
         return "crazyflie";
      }

   private:

      CControllableEntity*              m_pcControllableEntity;
      CEmbodiedEntity*                  m_pcEmbodiedEntity;
      CQuadRotorEntity*                 m_pcQuadRotorEntity;
      CRABEquippedEntity*               m_pcRABEquippedEntity;
      CPerspectiveCameraEquippedEntity* m_pcPerspectiveCameraEquippedEntity;
      CBatteryEquippedEntity*           m_pcBatteryEquippedEntity;
      CCrazyflieDistanceScannerEquippedEntity* m_pcCrazyflieDistanceScannerEquippedEntity;
   };

}

#endif
