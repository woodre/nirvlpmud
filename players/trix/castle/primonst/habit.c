/*
Changed ac from 4 to 3 because ac4 is justified by neither theme nor
balance.  The bishop already has an ac2 ring and a wc18 weapon.
-Feldegast 9-18-00

Added color to short - Eurale 9.29.02
*/
/* 2005.08.12 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/players/forbin/closed/bfeq.c";
#if 0 /* Rumplemintz */
#include "/open/ansi.h"
#else
#include <ansi.h>
#endif

reset(arg){
  if(arg) return;
   ::reset(arg);
    set_short(HIY+"B"+NORM+"ishop "+HIY+"H"+NORM+"abit");
   set_long("This is a long and white habit, embroidered with gold and silver wires.  It\n"+
     "looks precious and quite protective.\n");
   set_ac(3);
   set_params("magical",2,0,0);
   set_params("other|evil",0,15,0);
   set_weight(2);
   set_value(1000);
   set_alias("armor");
   set_name("habit");
   set_type("armor");
  set_bf_guild_bonus(5, 15);
}
