/*
 * 2006.02.20 Pavlik - changed again for Mages
 */
/* 2005.08.16 Forbin 
// -changed from obj/armor.c to bfeq object to support 
//  modifying of Bloodfist guild attribute bonuses
// inherit "/obj/armor.c"; 
*/
inherit "/obj/armor";
#include "/open/ansi.h"

#define EN environment(this_object())
#define ME capitalize(environment(this_object())->query_name())
#define IT capitalize(environment(this_object())->query_attack()->query_name())
#define GUILDID "mageobj"
#define BONUS_TYPE "evocation"
#define BONUS_AMOUNT 3

reset(arg){
  ::reset(arg);
  set_short(BLU+"S"+BOLD+BLK+"torm "+NORM+BLU+"C"+BOLD+BLK+"loak"+NORM);
  set_long(
  "A huge flowing garment of fine dark material.  Blue energy of the storms\n"+
  "crackles across its surface.  You wonder if it is safe to touch.\n");
  set_ac(1);
  set_weight(1);
  set_value(15000);
  set_alias("cloak");
  set_name("the Storm Cloak");
  set_type("cloak");
  call_out("funks", 10);
}

query_guild_bonus(){ return BONUS_AMOUNT; }

add_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, BONUS_AMOUNT);
}

remove_guild_bonus()
{
  if(present(GUILDID, this_player()))
	present(GUILDID, this_player())->add_guild_bonus(BONUS_TYPE, -BONUS_AMOUNT);
}


funks()
{
  int r;

  while(remove_call_out("funks") != -1); /* 07/18/06 Earwax */
  if(!environment(this_object())) return 1;
  if(!environment(environment(this_object()))) return 1;
  if(!worn)
  {
    call_out("funks", 50);
    return 1;
  }

  r = random(7);

  if(r == 0)
  {
    tell_object(EN, "Your storm cloak crackles with energy.\n");
    tell_room(environment(EN), ME+"'s cloak crackles with mysterious energy.\n");
  }
  else if(r == 2)
  {
    if(EN->query_attack()){
      tell_room(environment(EN),
      "Tiny sparks of electricity surge from "+ME+"'s cloak and ZAP his enemy!\n");
      EN->query_attack()->hit_player(2+random(10), "other|electricity");
      EN->add_spell_point(-random(5));
    }
    else {
      tell_object(EN, "Tiny sparks of electricity crackle across your cloak.\n");
      tell_room(environment(EN), "Tiny sparks of electricity crackle across "+ME+"'s cloak.\n");
    }
  }
  else if(r == 3)
  {
    tell_room(environment(EN),
    ME+"'s storm cloak ripples in the wind and thunder rolls across the sky.\n");
    if(EN->query_attack()) tell_room(environment(EN),
    IT+" glances up at the sky nervously ...\n");
  }
  else if(r == 5)
  {
	tell_object(EN, "Your cloak vibrates softly with powerful magic.\n");
  }

  call_out("funks", 60+random(90));
  return 1;
}
