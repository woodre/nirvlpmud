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
  write_file("/players/pestilence/closed/dark/help/spells/dwield.txt",
HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+
HIR+"                  D W I E L D \n"+NORM+
HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n"+NORM+
HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+
HIW+"  Usage:   dwield (weapon)\n\n"+
"This gives you an enhanced wielding ability, connecting your\n"+
"hatred for everything with your weapon.\n\n\n"+

HIK+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
    return 1;
}
