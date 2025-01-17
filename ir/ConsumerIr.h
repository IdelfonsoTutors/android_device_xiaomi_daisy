/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ANDROID_HARDWARE_IR_V1_0_IR_H
#define ANDROID_HARDWARE_IR_V1_0_IR_H

#include <android/hardware/ir/1.0/IConsumerIr.h>
#include <hardware/consumerir.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace ir {
namespace V1_0 {
namespace implementation {

using ::android::hardware::ir::V1_0::ConsumerIrFreqRange;
using ::android::hardware::ir::V1_0::IConsumerIr;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;

struct ConsumerIr : public IConsumerIr {
    ConsumerIr();
    ~ConsumerIr();
    bool isOk();
    // Methods from ::android::hardware::ir::V1_0::IConsumerIr follow.
    Return<bool> transmit(int32_t carrierFreq, const hidl_vec<int32_t>& pattern) override;
    Return<void> getCarrierFreqs(getCarrierFreqs_cb _hidl_cb) override;
private:
    consumerir_device_t *mDevice;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace ir
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_IR_V1_0_IR_H
