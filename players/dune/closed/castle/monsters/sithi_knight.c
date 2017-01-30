inherit "obj/monster";
#include "definitions.h"


id(str)
{
  return str == "sithi" || str == "knight";
}


reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("sithi knight");
   set_race("sithi");
   set_alias("sithi");
   set_short("A Sithi Knight");
   set_long(
"     The Sithi Knight is like its Sithi kin, except for a\n"+
"visible increase in size and strength. The Sithi Knight's hair\n"+
"is dyed in an assortment of colors. Beads hang from the long locks\n"+
"and laces of colorful string loop around its neck. Red rings encircle\n"+
"the knight's eyes. The Sithi is insane.\n");
   set_level(11);
   set_hp(random(20)+165);
   set_al(-40);
   set_wc(16);
   set_ac(10);
   set_aggressive(1);
}
