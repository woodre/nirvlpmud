#include "def.h"

inherit "/players/vertebraker/dev/guild_object";


reset(arg)
{
  ::reset(arg);
  if(arg) return;
  guild_file=basename(this_object());
  guild_name="WitchHunter";
  cmd_dir = CMDDIR;
  save_dir = SAVE;
}

init()
{
  object e;
  if((e = environment()) && !e->query_wh_shadow())
  {
    object y;
    y = clone_object(STDDIR + "player_shadow");
    y->start_shadow(e);
  }
  ::init();
}

id(str)
{
  return str == GID || ::id(str)
  || str == "guild_monitor"
  ;
}


print_monitor()
{
  int xdr;
  int xtd;

  xdr=(int)environment()->query_wh_kep();
  xtd=(int)environment()->query_wh_pep();

  if(xdr > 0) {
    tell_object(environment(), HIC+"KEP: ("+NORM+xdr+HIC+")"+NORM+"\n");
  }
  if(xtd > 0) {
    tell_object(environment(), HIM+"PEP: ("+NORM+xtd+HIM+")"+NORM+"\n");
  }
}
