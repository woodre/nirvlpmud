/*  FANNAME is randomized female name in /players/jenny/wings/defines/chicknames.h */
inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
#include "/players/jenny/wings/defines/chicknames.h"
   ::reset(arg);
   if (arg) return;
   set_name(CAP(FANNAME));
   set_alt_name(FANNAME);
   set_alias("fan");
   set_race("human");
   set_gender("female");
   set_al(20+random(19));
   set_level(8);
   set_hp(116+random(10));
   set_wc(12);
   set_ac(7);
   add_money(330+random(36));
   set_short("A fan named "+CAP(FANNAME));
   set_long(
      CAP(FANNAME)+" is an average sized woman who is wearing blue jeans and\n"+
      "a Red Wings jacket.  She is a big fan who got here early to watch\n"+
      "the players warm up before the game.\n");
}
