#include "config.h"
#include <fstream>
#include <string>

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

void Config::SetDefaultValues()
{
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
