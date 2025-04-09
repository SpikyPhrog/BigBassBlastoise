#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "consts.h"

class Config
{
public:
    Config();
    ~Config();
    
    // returns a std::pair<Configs, std::string>
    const std::basic_string<char,std::char_traits<char>,std::allocator<char>>& GetConfig(const Configs& conf);

private:
    void SetDefaultValues();
    void DeserializeFile();

    std::unordered_map<Configs, std::string> cfgs               {};
};
