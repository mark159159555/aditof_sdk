/*
 * BSD 3-Clause License
 *
 * Copyright (c) 2019, Analog Devices, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef ETHERNET_DEVICE_H
#define ETHERNET_DEVICE_H

#include "aditof/device_construction_data.h"
#include "aditof/device_interface.h"

#include <memory>

class EthernetDevice : public aditof::DeviceInterface {
  public:
    EthernetDevice(const aditof::DeviceConstructionData &data);
    ~EthernetDevice();

  public: // implements DeviceInterface
    virtual aditof::Status open();
    virtual aditof::Status start();
    virtual aditof::Status stop();
    virtual aditof::Status
    getAvailableFrameTypes(std::vector<aditof::FrameDetails> &types);
    virtual aditof::Status setFrameType(const aditof::FrameDetails &details);
    virtual aditof::Status program(const uint8_t *firmware, size_t size);
    virtual aditof::Status getFrame(uint16_t *buffer);
    virtual aditof::Status readAfeRegisters(const uint16_t *address,
                                            uint16_t *data, size_t length);
    virtual aditof::Status writeAfeRegisters(const uint16_t *address,
                                             const uint16_t *data,
                                             size_t length);
    virtual aditof::Status readAfeTemp(float &temperature);
    virtual aditof::Status readLaserTemp(float &temperature);
    virtual aditof::Status getDetails(aditof::DeviceDetails &details) const;
    virtual aditof::Status getHandle(void **handle) override;

  private:
    struct ImplData;

    aditof::DeviceDetails m_deviceDetails;
    std::unique_ptr<ImplData> m_implData;
};

#endif // ETHERNET_DEVICE_H
