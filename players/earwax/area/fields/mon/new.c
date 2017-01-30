inherit "/obj/monster.c";
#include <ansi.h>

void reset(status arg)
{
  ::reset(arg);
  if (arg)
  {
    return;
  }

  set_short("A hideous moat-monster");
  set_long("Coming soon to a moat-monster near you:  the long description!\n");
  set_name("moatmon");
  set_level(29);
  set_wc(60);
  set_ac(30);
}
