inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
#include "/players/jenny/wings/defines/refnames2.h"
   ::reset(arg);
   if (arg) return;
   set_name(CAP(FIRST)+" "+CAP(LAST));
   set_alt_name(LAST);
   set_race("referee");
   set_alias(FIRST);
   set_gender("male");
   set_al(25+random(40));
   set_level(14);
   set_hp(210+random(20));
   set_wc(18);
   set_ac(11);
   add_money(700+random(100));
   set_short(CAP(FIRST)+" "+CAP(LAST));
   set_long(
      CAP(FIRST)+" "+CAP(LAST)+" is one of the referees for tonight's game.  He\n"+
      "is wearing a black and white striped shirt, an orange armband, and\n"+
      "black pants.\n");
}
init() { 
   ::init(); 
   add_action("prevent","search");
}
prevent() {
   write(TO->query_name()+" prevents you from searching the room.\n");
   return 1;}
