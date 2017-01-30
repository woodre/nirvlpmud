/*  dests upon breaking   */
/* /players/zeus/museum/OBJ/light_dagger.c
//
// 2005.08.20 -Forbin
// Changes:
//   increased a some hit_players to other|light and raise a couple
//   of hit_player values
// 2013.04.15 -Dragnar
//   Added mage bonus for Illusion.  Changed hit_player when wielded to 
//   other|light to match theme.  Dagger deadly to mages when wielded, hard
//   to obtain, and theme makes it ideal for mage illusion.
// 2014.01.02 - Dragnar
//   Updated wear function. How can a dagger of light wear? Also updated
//   chance of failed wield to be based on stats.
*/
inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

#define GUILDID "mageobj"
#define BONUS_TYPE "illusion"
#define BONUS_AMOUNT 4


int light;

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("dagger");
   set_short(HIY+"a dagger of light"+NORM);
   set_type("dagger");
   set_long(HIY+
"This is a beautiful dagger made of pure light.  It's true dimensions are\n"+
"hard to define because you can't look directly into the dagger.  There\n"+
"is a strong aura of energy about it.  Only a very strong person could\n"+
"wield this dagger and endure the burning light.\n"+NORM);
   set_value(2099);
   set_weight(1);
   set_light(1);
   set_class(19);
   set_hit_func(this_object());
   message_hit=({
    "sliced"," with a burning slash of "+HIY+"light"+NORM,
    "sliced"," with deadly attack",
    "tore into"," with a lightning quick slash",
    "cut"," with a quick slash",
    "grazed","",
    "grazed","",
    "grazed","",
  });
}


wield(string str)
{
  if(id(str) && present(this_object(), this_player()) &&
    this_player()->query_weapon() == this_object()){
    ::wield(str);
    return 1;
  }
  ::wield(str);
  if(id(str))
  {
    if(!present(this_object(), this_player())) return 0;
    if(this_player()->query_level() < 10){
      write("This dagger is too painful for a player below "+
        "level 10 to use.\n");
      call_other(this_player(), "stop_wielding");  
      wielded = 0;  
      wielded_by = 0;
      TO->drop();
      return 1;
    }
    write(HIY+"The dagger burns your hands!\n"+NORM);
    this_player()->hit_player(150+random(100), "other|light");
    if(!random(this_player()->query_total_stats()/30))
    {
      write(HIY+"You drop the dagger quickly.\n"+NORM);
      call_other(this_player(), "stop_wielding");  
      wielded = 0;  
      wielded_by = 0;
      TO->drop();
      return 1;
    }
    return 1;
  }
}

weapon_breaks()
{
  if(broke) return 1;
  save_flag = 0;
  tell_object(environment(), HIY+
    "\n\tThere is a sudden flash of light from your dagger!\n\n"+
    "\t    Your dagger melts away in your hand!\n\n"+NORM);
  environment()->hit_player(20);
  this_object()->drop();
  wielded=0;
  wielded_by=0;
  destruct(this_object());
  return 1;
}

query_wear() {
  return 1;
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

int weapon_hit(object target){
  if(!target) return 0;
  if(target->query_hp() < ((int)target->query_mhp() / 9))
  {
    if(!random(3))
    {
      tell_object(environment(), 
        "You slash "+target->QN+", burning "+target->OBJ+
        " with "+HIY+"light\n"+NORM);
      tell_room(environment(target), 
        ENV->QN+" slashes "+target->QN+", burning "+target->OBJ+
        " with "+HIY+"light\n"+NORM, ({ environment() }));
      if(target->query_hp() > 14)
        target->hit_player(10+random(20), "other|light");
      else
        target->hit_player(10+random(20), "other|light");
      return 8; 
    }
  }
  if(light >= 50)
  {
    tell_room(environment(target), 
      HIY+"\n\tA huge blast of light strikes "+target->QN+"!\n\n"+NORM);
    target->hit_player((light / 2), "other|light");
    light -= 30+random(25);
  }
  if(!random(5))
  {
    tell_object(environment(), 
      HIY+"Light pours into your body!\n"+NORM);
    environment()->add_spell_point(5+random(5));
    environment()->hit_player(2, "other|light");
  }
  else if(!random(5))
  {
    tell_object(environment(), 
      "You slash "+target->QN+" with your dagger of light.\n");
    tell_room(environment(target), 
      ENV->QN+" slashes "+target->QN+" with "+ENV->POS+
      " dagger of light.\n", ({ environment() }));
    light += 5;
    if(target->query_hp() > 10)
      target->hit_player(10, "other|light");
    else
      return 6;
  }
  if(!random(35))
  {
    tell_object(environment(),
      "Beams of light explode from your dagger.\n");
    tell_room(environment(target),
      "Beams of light explode from "+ENV->QN+"'s dagger.\n",
      ({ environment() }));
  }
  else if(!random(35))
  {
    tell_object(environment(),
      "Your dagger pulses with a furious aura of light.\n");
    tell_room(environment(target),
      ENV->QN+"'s dagger pulses with a furious aura of light.\n",
      ({ environment() }));
  }
  else if(!random(35))
  {
    tell_object(environment(),
      "Your dagger radiates burning white light.\n");
    tell_room(environment(target),
      ENV->QN+"'s dagger radiates burning white light.\n",
      ({ environment() }));
  }
  else if(!random(35))
  {
    tell_object(environment(),
      "Waves of light eminate from your dagger.\n");
    tell_room(environment(target),
      "Waves of light eminate from "+ENV->QN+"'s dagger.\n",
      ({ environment() }));
  }
  return 0; /* Rumplemintz */
}
