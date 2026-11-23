#pragma once
#include <stdint.h>
#include <stddef.h>
// EMERGENCY_ORIGIN_POLICY_OPEN_SOS_V1
// Cualquier NodeNum legítimo puede originar un SOS. Esto NO autentica la identidad.
// En relays, la prioridad ALERT requiere adicionalmente una firma XEdDSA VERIFICADA.
namespace EmergencyOriginPolicy {
inline bool validNodeNum(uint32_t nodeNum)
{
    return nodeNum != 0U && nodeNum != UINT32_MAX;
}
} // namespace EmergencyOriginPolicy
static constexpr uint32_t EMERGENCY_CACHE_MS = 60UL * 60UL * 1000UL; // dedup lifetime since reception
static constexpr size_t EMERGENCY_HISTORY_SLOTS = 16; // RAM-only bounded alert history
static constexpr size_t EMERGENCY_STORED_ALERTS = 8; // ~1.5 KiB bounded RAM for alert fetch
static constexpr uint32_t EMERGENCY_FETCH_COOLDOWN_MS = 5000;
static constexpr uint32_t EMERGENCY_RECEIPT_COOLDOWN_MS = 2000;
#ifndef EMERGENCY_ENABLE_RECEIPTS
#define EMERGENCY_ENABLE_RECEIPTS 1
#endif

// Optional ZeroInfra EMG1 SOS location diagnostic (GPS prefix: @lat,lon SOS).
// Does not influence transmission priority or acceptance of SOS without GPS.
#ifndef EMERGENCY_GPS_TEXT_TRACE
#define EMERGENCY_GPS_TEXT_TRACE 1
#endif
