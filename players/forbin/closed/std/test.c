/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     Crown for King of Salamites
 *  Create Date:  2004.06.04
 *  Last Edit:    2004.06.10 -Forbin
 *  Notable Changes:            
 */

#include "/players/forbin/realms/flame_forest/ffdefine.h"
inherit "players/forbin/closed/std/armwep.c";

reset(arg) {
  set_name("gloves");
  set_alias("crown");
  set_short(HIW+"Test Gloves Weapon"+NORM);
  set_long("Just a test!\n");
  set_armor_type("ring");
  set_ac(2);
  set_weapon_type("exotic");
  set_class(18);
  set_weight(1);
  set_value(4500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(19);

if(W>16)  {
  say(""+BOLD+""+BLK+""+user+"'s Battleaxe discharges a stream of"+RED+" Flame "+NORM+""+
  ""+BOLD+""+BLK+"which engulf's its victim!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Battleaxe discharges a stream of "+BOLD+""+RED+"FLAME"+NORM+""+
  ""+BOLD+""+BLK+" which engulf's your foe!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Axe pulses with a bright"+RED+" Aura of Flame"+NORM+""+
  ""+BOLD+""+BLK+" as it strikes at its foe!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Axe pulses with a "+BOLD+""+RED+"Flaming Aura"+NORM+""+
  ""+BOLD+""+BLK+" as you strike your foe!"+NORM+"\n");
  return 3;
   }
return;
}


do_special(owner)
{

int z;
object ob;
  z = 1;
   if (z<5){
 environment()->add_hit_point(random(2));
tell_room(environment(owner), ""+environment()->query_name()+"'s "+HIW+"diamond ring"+NORM+" glows brightly as power flows from it.\n");
return 1;
}
      return 0; 
   }


