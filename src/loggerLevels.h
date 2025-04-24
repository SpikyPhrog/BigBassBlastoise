#if (!defined(LOGGER_LEVEL_H) || defined(GENERATE_ENUM_STRINGS))
#if (!defined(GENERATE_ENUM_STRINGS))
    #define LOGGER_LEVEL_H
#endif
#include "enumToString.h"

BEGIN_ENUM(LoggerLevel)
{
    DECL_ENUM_ELEMENT(DEBUG),
    DECL_ENUM_ELEMENT(INFO),
    DECL_ENUM_ELEMENT(WARNING),
    DECL_ENUM_ELEMENT(ERROR),
    DECL_ENUM_ELEMENT(CRITICAL),
}
END_ENUM(LoggerLevel)
#endif // (!defined(LOGGER_LEVEL_H) || defined(GENERATE_ENUM_STRINGS))