#if (!defined(CONFIGS_H) || defined(GENERATE_ENUM_STRINGS))
#if (!defined(GENERATE_ENUM_STRINGS))
    #define CONFIGS_H
#endif
#include "enumToString.h"

BEGIN_ENUM(Configs)
{
    DECL_ENUM_ELEMENT(MasterVolume),
    DECL_ENUM_ELEMENT(Name),
    DECL_ENUM_ELEMENT(None),
}
END_ENUM(Configs)
#endif // (!defined(CONFIGS_H) || defined(GENERATE_ENUM_STRINGS))