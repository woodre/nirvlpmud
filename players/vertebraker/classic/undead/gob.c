#include "defs.h"

inherit MY_ABSTRACT;
inherit BASE_GOB;

void reset(status arg)
{
  abstract::reset(arg);
  guild_slave::reset(arg);
  if(arg) return;
}
