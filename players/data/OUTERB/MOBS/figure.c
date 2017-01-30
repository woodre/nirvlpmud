#include <ansi.h>
inherit "obj/monster.c";


reset(arg)  {
  ::reset(arg);
  if(arg) return;
   
set_name("figure");
set_race("undead");

set_short(HIK+"a Dark Figure"+NORM);
set_long(
  "  The Dark figure is wearing a long black robe with\n"+
  "  it's hood up. The robe is tatered and torn in places\n"+
  "  and a glint of white can be seen through the tears. \n"+
  "  It's impossible to tell if this creature is dead or\n"+
  "  alive, but it seems to be willing to do business. \n");
 
set_level(14);
set_hp(200);
set_al(0);
set_ac(10);
set_wc(16);

}