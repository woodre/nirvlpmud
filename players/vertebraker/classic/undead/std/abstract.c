#include "../defs.h"

inherit BASE_ABSTRACT;

void reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  add_guild_wizard("francesco");
  set_root_dir("/players/vertebraker/classic/undead/");
}
