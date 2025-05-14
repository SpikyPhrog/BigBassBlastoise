#include "config.h"
#include <fstream>
#include <string>
#include "consts.h"
#include "eventTypes.h"
#include "system.h"

Config::Config()
{
    CheckConfigFileExists();
    SetDefaultValues();
    DeserializeFile();
}

Config::~Config()
{
    std::ifstream cfg(configFilePath);
    if (cfg.is_open())
    {
        cfg.close();
    }
}

const std::basic_string<char,std::char_traits<char>,std::allocator<char>> &Config::GetConfig(const Configs &conf)
{
    return cfgs.at(conf);
}

void Config::RevertChanges()
{
    for (auto config : lastChangeCfgs)
    {
        EventTypes event = System::Get()->eventManager->GetEventType(config.first);

        BaseEventStruct data;
        data.configString = config.second.c_str();

        void* dataPtr = &data;

        System::Get()->BroadcastEvent(event, dataPtr);

        dataPtr = nullptr;
    }
    
    updatedCfgs.clear();
    lastChangeCfgs.clear();
}

void Config::SaveChanges()
{
    SerialiseConfigs();
}

void Config::UpdateConfig(const Configs &cfg, const std::string &newSetting)
{
    if (auto configSearch = updatedCfgs.find(cfg); configSearch != updatedCfgs.end())
    {
        configSearch->second = newSetting;
    }
    else
    {
        if (auto cfgSearch = cfgs.find(cfg); cfgSearch != cfgs.end())
        {
            if (newSetting == cfgSearch->second)
            {
                Logger::Log(LoggerLevel::DEBUG, "%s", "No update is required");
                return;
            }           
        }   
        updatedCfgs.try_emplace(cfg, newSetting);
    }
}

bool Config::GetAnyChangesMade()
{
    return updatedCfgs.size() > 0;
}

void Config::SetDefaultValues(bool bForce)
{
    if (bForce)
    {
        bFileExists = false;
    }
    

    if (bFileExists)
    {
        return;
    }
    

    std::ofstream cfg (configFilePath);
    if (cfg.bad())
    {
        std::cerr << "config file not found\n";
    }
    
    cfg<<defaultConfigs;

    cfg.close();

    if (bForce)
    {
        bFileExists = true;
    }
    
}

void Config::DeserializeFile()
{
    std::ifstream cfg (configFilePath);
    char c;

    if (!cfg.is_open())
    {
        std::cerr<< "DESERIALIZER File not found\n";
        return;
    }
    
    std::string word = "";
    int enumIndex = 0;
    bool bWriteWord = false;

    while (cfg.good())
    {
        cfg.get(c);
        
        if (c == 32) // c == " "
        {
            continue;
        }

        if (c == 61) // c == "="
        {
            bWriteWord = true;
        }
        
        if (c == 59) // c == ";"
        {
            cfgs.try_emplace((Configs)enumIndex, word);
            enumIndex++;
            bWriteWord = false;
            word = "";
        }
        
        if (bWriteWord && c != 61)
        {
            word+= c;
        }
    }
    
    cfg.close();
}

void Config::CheckConfigFileExists()
{
    std::ifstream cfg (configFilePath);

    bFileExists = cfg.good();
    
    cfg.close();
}

void Config::SerialiseConfigs()
{
    for (auto updatedCfg : updatedCfgs)
    {
        if (auto changedConfig = cfgs.find(updatedCfg.first); changedConfig != cfgs.end())
        {
            changedConfig->second = updatedCfg.second;
        }
    }

    std::ofstream cfgFile (configFilePath);
    if (cfgFile.bad())
    {
        std::cerr << "config file not found\n";
    }
    
    for (auto config : cfgs)
    {
        std::string Key = GetStringConfigs(config.first);
        cfgFile << Key << "=" << config.second << ";\n";
    }

    cfgFile.close();
    updatedCfgs.clear();
    lastChangeCfgs.clear();
}

void Config::CacheConfigs()
{
    lastChangeCfgs.insert(cfgs.begin(), cfgs.end());
}
