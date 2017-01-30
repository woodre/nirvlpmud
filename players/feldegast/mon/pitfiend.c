/*
File: pitfiend.c
Author: Feldegast
Date: 3/18/02
Description:
  A pit fiend summoned by the orcish shaman in the encampment
in Caladon.  HB aggresive.  Loot located deeper in the camp.
*/

#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_aggressive(1);
  set_name("pit fiend");
  set_alt_name("fiend");
  set_short("A "+MAG+"Pit"+NORM+" Fiend");
  set_long(
    "This is a bent, misshapen creature from the nether regions of hell.\n"+
    "Such creatures, bereft of all kindness and good, come the closest to\n"+
    "pleasure when they are tormenting others.\n"
  );
  set_gender("male");
  set_race("demon");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(450);
  set_al(-1000);
  load_spell(15,35,0,
    RED+"\nThe Pit Fiend slashes you with its claws!\n\n"+NORM,
    RED+"\nThe Pit Fiend slashes #ATT# with its claws!\n\n"+NORM);
}

void heart_beat()
{
  object ob;
  ::heart_beat();
  if(attacker_ob) 
    return;
  ob=first_inventory(environment());
  while(ob)
  {
    if(living(ob) && ob->is_player() && !ob->query_ghost() && !random(3))
    {
      attacked_by(ob);
      tell_room(environment(), RED+"The Pit Fiend notices prey nearby.\n"+NORM);
    }
    ob=next_inventory(ob);
  }
}
