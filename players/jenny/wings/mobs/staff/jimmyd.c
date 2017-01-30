inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jimmy devellano" ||  str == "jimmy" || str == "devellano" || str == "Jimmy Devellano" || str == "jim"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Jimmy Devellano");
   set_race("human");
   set_gender("male");
   set_al(50+random(10));
   set_level(8);
   set_hp(130);
   set_wc(11);
   set_ac(7);
   add_money(300+random(100));
   set_short(BOLD+WHT+"Jimmy Devellano"+NORM);
   set_long(
      "Jimmy Devellano is the Senior Vice President of the Detroit Red Wings.\n"+
      "He is a pudgy, older man, with dark hair and thick glasses.  Jimmy is\n"+
      "wearing an ugly dark brown suit, and red tie.  He used to be the team's\n"+
      "General Manager, but was dismissed from that job after a series of bad\n"+
      "trades.\n");
}
