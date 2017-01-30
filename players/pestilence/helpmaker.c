#include "/players/pestilence/define.h"
inherit "obj/treasure";

id(str) { return (::id(str) || str == "help_maker"); }
reset(arg) 
{
  if(arg) return;
  set_short("Pesty's help maker");
}
init() 
{
  add_action("make_nfo","make_help");
}

make_nfo()
{
  write(""+HIW+""+BLINK+"HELP FILE MADE!"+NORM+"\n");
  write_file("/open/info/guilds/darkorder.nfo",
HIK+"If one wishes to join the Dark Order, they must find a member to recruit them.\n"+NORM);
    return 1;
}
