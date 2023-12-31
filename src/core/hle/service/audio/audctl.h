// SPDX-FileCopyrightText: Copyright 2018 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "core/hle/service/service.h"

namespace Core {
class System;
}

namespace Service::Audio {

class AudCtl final : public ServiceFramework<AudCtl> {
public:
    explicit AudCtl(Core::System& system_);
    ~AudCtl() override;

private:
    enum class AudioOutputMode {
        Invalid,
        Pcm1ch,
        Pcm2ch,
        Pcm6ch,
        PcmAuto,
    };

    enum class ForceMutePolicy {
        Disable,
        SpeakerMuteOnHeadphoneUnplugged,
    };

    enum class HeadphoneOutputLevelMode {
        Normal,
        HighPower,
    };

    void GetTargetVolumeMin(HLERequestContext& ctx);
    void GetTargetVolumeMax(HLERequestContext& ctx);
    void GetForceMutePolicy(HLERequestContext& ctx);
    void GetOutputModeSetting(HLERequestContext& ctx);
    void GetHeadphoneOutputLevelMode(HLERequestContext& ctx);
    void IsSpeakerAutoMuteEnabled(HLERequestContext& ctx);
};

} // namespace Service::Audio
