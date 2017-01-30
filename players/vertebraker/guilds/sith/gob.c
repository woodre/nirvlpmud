#include "def.h"

inherit "/players/vertebraker/dev/guild_object";

reset(arg){
  ::reset(arg);
  if(arg || root()) return;
  set_id("Mark of the Sith");
  set_short("Mark of the "+HIR+"Sith"+NORM);
  set_long("\
The mark of the Sith is upon you.\n"+
RED+"\n"+NORM+"\n\
Type <shelp> to see your guild's abilities.\n");
  guild_file = basename(this_object());
  guild_name = "sith";
  cmd_dir = BINDIR;
  save_dir = SAVEDIR;
}

id(string str)
{
  if(str==GOBID || ::id(str))
    return 1;
}

guild_login()
{
}