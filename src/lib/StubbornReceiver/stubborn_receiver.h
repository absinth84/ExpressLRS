#pragma once

#include <cstdint>

class StubbornReceiver
{
public:
    void ResetState();
    void SetDataToReceive(uint8_t maxLength, uint8_t* dataToReceive, uint8_t bytesPerCall);
    bool ReceiveData(uint8_t packageIndex, volatile uint8_t* data);
    bool HasFinishedData();
    void Unlock();
    bool GetCurrentConfirm();
private:
    uint8_t *data;
    volatile bool finishedData;
    volatile uint8_t length;
    volatile uint8_t bytesPerCall;
    volatile uint8_t currentOffset;
    volatile uint8_t currentPackage;
    volatile bool telemetryConfirm;
};
