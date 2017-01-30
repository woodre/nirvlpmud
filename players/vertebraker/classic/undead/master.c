#include "defs.h"

inherit MY_ABSTRACT;
inherit BASE_MASTER;

void reset(status arg)
{
  abstract::reset(arg);
  guild_master::reset(arg);
  if(arg) return;
}
