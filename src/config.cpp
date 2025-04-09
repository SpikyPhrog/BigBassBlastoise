#include "config.h"
#include <fstream>
#include <string>

Config::Config()
{
    SetDefaultValues();
    DeserializeFile();
}

Config::~Config()
{
    std::ofstream cfg(configFilePath);
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

    if (cfg.bad())
    {
        std::cerr<< "DESERIALIZER File not found\n";
        return;
    }
    
    std::string word = "";
    int enumIndex = 0;
    bool bWriteWord = false;

    while (cfg)
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
            printf("word : %s\n", word.c_str());
            word = "";
        }
        
        if (bWriteWord && c != 61)
        {
            word+= c;
        }
    }
    
    cfg.close();
}
