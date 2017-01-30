/*
 * kernel/simul/is_wizard.c
 * sefun to handle wizard status checking
 * Rumplemintz
 */

#include <is_wizard.h>

varargs status is_wizard(mixed who, int mode) {
  if (objectp(who))
    if (mode)
      switch(mode) {
      case IW_WIZARD:
        return who->query_level() > 20;
        break;
      case IW_APPRENTICE:
        return who->query_level() > 19;
      case IW_TESTPLAYER:
        return who->is_testchar;
      case IW_TOOLUSER:
        return who->query_level() > 59;
      default:
        return 0;
      }
  return 0;
}

