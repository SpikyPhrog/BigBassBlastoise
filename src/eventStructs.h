#pragma once

struct BaseEventStruct
{
    const char* configString {""};
};

struct UI_Data : BaseEventStruct
{
    int data {0};
};

struct UI_Slider_Data : BaseEventStruct
{
    float data {0};
};