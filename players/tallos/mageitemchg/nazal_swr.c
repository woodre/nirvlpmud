/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2005 Forbin
 *                  All Rights Reserved.
 *  Realm:        City of Keats
 *  Function:     special armor
 *  Create Date:  2005.06.30
 *  Last Edit:    2005.06.30 -Forbin
 *  Notable Changes:            
 */
/* edited 05-17-07 by Tallos to add mage guild bonus*/
#include "/players/forbin/realms/keats/keatsdefine.h"

inherit "obj/armor";
#define GUILDID "mageobj"
#define BONUS_TYPE "enchantment"
#define BONUS_TYPE2 "evocation"
#define BONUS_AMOUNT 2
#define BONUS_AMOUNT2 1
#define ROBES HIB+"Sapp"+NORM+BLU+"hire "+HIB+"Wiz"+NORM+BLU+"ard "+HIB+"Ro"+NORM+BLU+"bes"+NORM

int Go, Count;

reset(arg) 
{
  set_name("sapphire wizard robes");
  SetMultipleIds(({"robe","robes","wizard robe","wizard robes","sapphire wizard robe"}));
  set_short(ROBES);
  set_ac(2);
  set_params("magical", 2, 5);
  set_type("armor");
  set_weight(1);
  set_value(9999);
  Go = 1;
}
query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, BONUS_AMOUNT2);	
 }
			
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
  {
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE2, -BONUS_AMOUNT2);	
  }
}
short()
{
	string sh;
	sh = ::short();
  if(this_player()) /* verte */
  if(this_player()->query_level() > 99)
    sh += HIW+" [ "+NORM+"Go="+NORM+YEL+Go+NORM+", Count="+HIY+Count+HIW+" ]"+NORM;
  return sh;
}

void long()
{
  if(Go) 
    tell_object(this_player(),
      "This beautifully hand-crafted garment shimmers and sparkles with an\n"+
      "incandescent life.  Silky smooth to the touch, yet incredibly stiff,\n"+
      "it appears that these robes may be enchanted in order to provide\n"+ 
      "added protection beyond their normal means.  The back of the robes\n"+
      "is woven with a magnificent design: a wide sapphire stripe runs the\n"+
      "length of the material, and an elliptical blue orb is sewn onto it.\n"+
      "Eight smaller orbs ring the blue one; each is a different color and\n"+
      "bears a single symbol embroidered in white silk thread.\n");
  else
    tell_object(this_player(),
      "This beautifully hand-crafted garment shimmers and sparkles with an\n"+
      "incandescent life.  The material is silky smooth to the touch.  The\n"+
      "back of the robes is woven with a magnificent design: a wide sapphire\n"+
      "stripe runs the length of the material, and an ellipitcal blue orb is\n"+
      "sewn onto it.  Eight smaller orbs ring the blue one; each is a\n"+
      "different color and bears a single symbol embroidered in white silk\n"+
      "thread.\n");
} 

int do_special(object owner)
{
  object nmy;
  if(!owner || !(nmy = (object)owner->query_attack())) return 1;
  if(!owner->is_player()) return 1;
  if(!Go) return 0;
  if(((int)owner->query_attrib("luc") / 2) > random(100))
  {
    tell_object(owner,
      "Your "+ROBES+" "+HIB+"shimmers"+NORM+" brightly!\n");
    tell_room(environment(owner),
      (string)owner->query_name()+"'s "+ROBES+" "+HIB+"shimmers"+NORM+" brightly!\n", ({ owner }));
    if(random(3))
      Count += 5;
    return 5;
  }
  if(random(10)) 
    Count++;  
  if(Count > 7500)    
  {
    tell_object(owner,
      HIB+"\nThe enchantm"+NORM+BLU+"ent surrou"+HIW+"nd your rob"+NORM+"es fades...\n\n");
    Go = 0;
  }
  return 4; 
}

string locker_arg() 
{ 
  return "Count"+Count+"Go"+Go+""; 
}

void locker_init(string arg) 
{ 
  int t1, t2;
  sscanf(arg, "Count%dGo&d", t1, t2);
  Count = t1; Go = t2;
}

status restore_thing(string arg) 
{ 
  restore_object(arg); 
  return 1; 
}

status save_thing(string arg) 
{ 
  save_object(arg); 
  return 1; 
}

status generic_object() { return 1; }

void set_go(int x) { Go = x; }

void set_count(int x) { Count = x; }
