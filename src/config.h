#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "configs.h"

class Config
{
public:
    Config();
    ~Config();
    
    // returns a std::pair<Configs, std::string>
    const std::basic_string<char,std::char_traits<char>,std::allocator<char>>& GetConfig(const Configs& conf);

    void RevertChanges();
    void SaveChanges();

    void UpdateConfig(const Configs& cfg, const std::string& newSetting);
    bool GetAnyChangesMade();

private:
    void SetDefaultValues(bool bForce = false);
    void DeserializeFile();
    void CheckConfigFileExists();
    void SerialiseConfigs();

    bool bFileExists                                            {false};

    std::unordered_map<Configs, std::string> cfgs               {};
    std::unordered_map<Configs, std::string> updatedCfgs        {};
};
