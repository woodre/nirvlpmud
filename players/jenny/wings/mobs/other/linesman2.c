inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
#include "/players/jenny/wings/defines/linesmennames2.h"
   ::reset(arg);
   if (arg) return;
   set_name(CAP(FIRST)+" "+CAP(LAST));
   set_alt_name(LAST);
   set_race("linesmen");
   set_alias(FIRST);
   set_gender("male");
   set_al(35+random(40));
   set_level(13);
   set_hp(195+random(12));
   set_wc(17);
   set_ac(11);
   add_money(540+random(120));
   set_short(CAP(FIRST)+" "+CAP(LAST));
   set_long(
      CAP(FIRST)+" "+CAP(LAST)+" is one of the linesmen for tonight's game.  He\n"+
      "is wearing a black and white striped shirt, along with black pants.\n");
}
init() { 
   ::init(); 
   add_action("prevent","search");
}
prevent() {
   write(TO->query_name()+" prevents you from searching the room.\n");
   return 1;}
