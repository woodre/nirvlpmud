#include "/players/pestilence/ansi.h"
inherit "obj/armor";

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("collar");
   set_alias("magenta's collar");
   set_type("amulet");
   set_short(""+MAG+"Magenta's Collar"+NORM+"");
   set_long("This is a magenta collar worn by Magenta.\n");
   set_ac(1);
   set_weight(1);
   set_value(250);
}
