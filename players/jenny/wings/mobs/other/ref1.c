inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
#include "/players/jenny/wings/defines/refnames1.h"
   ::reset(arg);
   if (arg) return;
   set_name(CAP(FIRST)+" "+CAP(LAST));
   set_alt_name(LAST);
   set_race("referee");
   set_alias(FIRST);
   set_gender("male");
   set_al(40+random(30));
   set_level(15);
   set_hp(225+random(51));
   set_wc(21);
   set_ac(12);
   add_money(900+random(185));
   set_short(CAP(FIRST)+" "+CAP(LAST));
   set_long(
      CAP(FIRST)+" "+CAP(LAST)+" is one of the referees for tonight's game.  He\n"+
      "is wearing a black and white striped shirt, an orange armband, and\n"+
      "black pants.  "+CAP(FIRST)+" is one of the NHL's better referees.\n");
}
init() { 
   ::init(); 
   add_action("prevent","search");
}
prevent() {
   write(TO->query_name()+" prevents you from searching the room.\n");
   return 1;}
