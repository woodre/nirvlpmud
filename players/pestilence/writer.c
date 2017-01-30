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
  write_file("/players/pestilence/closed/dark/log/join2",
"Thu Jul  2 09:46:46 2015 Oberynn drank dragnar's blood and joined the "+HIK+"ORDER"+NORM+".\nTue Jul 28 15:37:11 2015 Shadowbane drank chrono's blood and joined the "+HIK+"ORDER"+NORM+".\n");
    return 1;
}
