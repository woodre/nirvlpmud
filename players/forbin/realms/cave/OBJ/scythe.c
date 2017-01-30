/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Caves of the Salamite
 *  Function:     Weapon
 *  Create Date:  2005.11.04
 *  Last Edit:    2005.11.04 -Forbin
 *  Notes:        WC 19, weight 3, type 'sword'
 */

#include "/players/forbin/realms/salam/salamdefine.h"
inherit "obj/weapon.c";

#define COLOR NORM+CYN
#define HCOLOR HIC
#define BLADEOFBALBERITH COLOR+"Blade "+HCOLOR+"of "+COLOR+"Bal"+HIW+"-"+HCOLOR+"beri"+HIW+"'"+COLOR+"th"+NORM
int Charge;
        
/* Prototype Declaration */
void reptile_check(object ob);        
        
id(str) 
{ 
  if(wielded)
    return (::id(str) || str == "hp_regen_object" || 
                         str == "blade" ||
                         str == "bal-beri'th" || 
                         str == "blade of balberith" || 
                         str == "blade of bal-beri'th");
  else                         
    return (::id(str) || str == "blade" ||
                         str == "bal-beri'th" || 
                         str == "blade of balberith" || 
                         str == "blade of bal-beri'th");
}

reset(arg) 
{
  ::reset(arg);
  if (arg) return;
  set_name("balberith");
  set_short(BLADEOFBALBERITH);
  set_long(
    "  \n");
  set_type("sword");
  set_class(18);
  set_weight(3);
  set_value(1);
  set_buy_value(10000 + random(30001));
  set_hit_func(this_object());
}

init()
{
  ::init();
  add_action("cmd_dissolve", "dissolve");
}

status cmd_dissolve(string arg)
{
  object corpse;
  int corpsevalue;
  string temp;
        
  if(environment()->query_ghost()) 
    return 0;
        
  corpse = present("corpse", environment(environment()));

  if(!corpse)
  {
    tell_object(environment(),
      "There is no corpse to dissolve.\n");
    return 1;
  }
  
  if((int)corpse->query_corpse_level() < 1)
  {
    tell_object(environment(),
      "You cannot dissolve that, it is useless.\n");
    return 1;
  }
  
  if(sscanf(file_name(corpse), "obj/corpse%s", temp) != 1) 
    return 1;
    
  tell_room(environment(environment()),
    (string)environment()->query_name()+" plunges "+
    (string)environment()->query_possessive()+
    "sword into "+(string)corpse->short()+NORM+"...\n"+
    "Streaks of "+HCOLOR+"Blue Energy"+NORM+" stream from the corpse, up the sword,\n"+
    "and into "+(string)environment()->query_name()+".\n", ({ environment() }));
  tell_object(environment(),
    "You plunge your sword into "+(string)corpse->short()+"...\n"+
    "Streaks of "+HCOLOR+"Blue Energy"+NORM+" stream from the corpse, up the sword,\n"+
    "and into you.  You are healed by the corpse's lifeforce.\n");
  corpsevalue = ((int)corpse->query_corpse_level() * 3);
  environment()->add_hit_point((corpsevalue / 6));
  Charge += corpsevalue;
  destruct(corpse);
  return 1;
}

int query_hp_regen()
{
	int rv;
	if(Charge)
	{
    if(!random(4))
      rv = 3;
    else if(!random(2))
      rv = 1;
    else
      rv = 0;
    if(rv && !random(6))
      tell_object(environment(),
        "You feel a warm as energy flows from "+BLADEOFBALBERITH+" into you.\n");
    Charge -= rv;
    return rv;
  }
  else
    return 0;
}

int weapon_hit(object attacker)
{
  if(broke)
  {
    tell_object(this_player(), 
      "There is a flash of "+HCOLOR+"Purple Energy"+NORM+" as "+
      "your "+BLADEOFBALBERITH+" reforms itself.\n");
    broke = 0;
    command("unwield");
    command("wield blade of balberith");
    return 0;
  }

  if(random((int)this_player()->query_attrib("wis")) > 16)
  {
  	tell_object(this_player(),
  	  "Your "+BLADEOFBALBERITH+" glows as a "+HCOLOR+"Vortex of Energy"+NORM+" assails "+
  	  (string)attacker->short()+NORM+"!\n");
    tell_room(environment(this_player()),
      (string)this_player()->query_name()+"'s "+BLADEOFBALBERITH+
      " glows as a "+HCOLOR+"Vortex of Energy"+NORM+" assails "+
      (string)attacker->short()+NORM+"!\n", ({ this_player() }));
     return 8;
  }
  if(random((int)TP->query_attrib("luc")) > 21 && reptile_check(attacker))
  {
    tell_object(this_player(),
      "Your "+BLADEOFBALBERITH+" flashes as it strikes "+HIW+"reptilian"+NORM+" flesh!.\n");
    tell_room(environment(this_player()),
      (string)this_player()->query_name()+"'s "+BLADEOFBALBERITH+" flashes as"+
      " it strikes "+HIW+"reptilian"+NORM+" flesh!.\n", ({ this_player() }));
    attacker->hit_player(8, "other|forbin");
    return 6;
  }
}

status reptile_check(object ob) {
  if(call_other(ob,"id", "reptile") || call_other(ob, "id", "lizard") ||
     call_other(ob, "id", "snake") || call_other(ob, "id", "salamander") ||
     call_other(ob, "id", "salamite") || call_other(ob, "id", "lizardman") ||
     call_other(ob, "id", "iguana") || call_other(ob, "id", "raptor") ||
     call_other(ob, "id", "gecko") || call_other(ob, "id", "bronto") ||
     call_other(ob, "id", "rex") || call_other(ob, "id", "triceratops") ||
     call_other(ob, "id", "dime") || call_other(ob, "id", "pteranadon") ||
     call_other(ob, "id", "antro") || call_other(ob, "id", "steg") ||
     call_other(ob, "id", "disir") || call_other(ob, "id", "dragon") ||
     call_other(ob, "id", "wyvern") || call_other(ob, "id", "turtle"))
    return 1;
  else 
    return 0;
} 