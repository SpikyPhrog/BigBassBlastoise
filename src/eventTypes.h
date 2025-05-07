#if (!defined(EVENTTYPES_H) || defined(GENERATE_ENUM_STRINGS))
#if (!defined(GENERATE_ENUM_STRINGS))
    #define EVENTTYPES_H
#endif
#include "enumToString.h"

BEGIN_ENUM(EventTypes)
{
    DECL_ENUM_ELEMENT(UI_SCORE),
    DECL_ENUM_ELEMENT(UI_LIVES),
    DECL_ENUM_ELEMENT(UI_Slider),
    DECL_ENUM_ELEMENT(GS_GameOver),
    DECL_ENUM_ELEMENT(GS_Start),
    DECL_ENUM_ELEMENT(NONE),
}
END_ENUM(EventTypes)
#endif // (!defined(EVENTTYPES_H) || defined(GENERATE_ENUM_STRINGS))