/*  FANNAME is randomized male name in /players/jenny/wings/defines/mannames.h */
inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
#include "/players/jenny/wings/defines/mannames.h"
   ::reset(arg);
   if (arg) return;
   set_name(CAP(FANNAME));
   set_alt_name(FANNAME);
   set_alias("fan");
   set_race("human");
   set_gender("male");
   set_al(25+random(10));
   set_level(9);
   set_hp(132+random(10));
   set_wc(14);
   set_ac(6);
   if(!random(6)) { set_aggressive(1); }
   add_money(350+random(92));
   set_short("A fan named "+CAP(FANNAME));
   set_long(
      CAP(FANNAME)+" is an average sized guy who is wearing blue jeans and a\n"+
      "Red Wings jacket.  He is a big fan who got here early to watch\n"+
      "the players warm up before the game.\n");
}
