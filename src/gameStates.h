#if (!defined(GAMESTATES) || defined(GENERATE_ENUM_STRINGS))
#if (!defined(GENERATE_ENUM_STRINGS))
    #define GAMESTATES_H
#endif
#include "enumToString.h"

// enum class GameStates
// {
//     MainMenu,
//     Options,
//     Start,
//     Paused,
//     GameOver,
//     PromptSettings
// };

BEGIN_ENUM(GameStates)
{
    DECL_ENUM_ELEMENT(GS_MainMenu),
    DECL_ENUM_ELEMENT(GS_Options),
    DECL_ENUM_ELEMENT(GS_Start),
    DECL_ENUM_ELEMENT(GS_Paused),
    DECL_ENUM_ELEMENT(GS_GameOver),
    DECL_ENUM_ELEMENT(GS_PromptSettings),
    DECL_ENUM_ELEMENT(GS_PostWaveComplete),
}
END_ENUM(GameStates)
#endif // (!defined(GAMESTATES_H) || defined(GENERATE_ENUM_STRINGS))