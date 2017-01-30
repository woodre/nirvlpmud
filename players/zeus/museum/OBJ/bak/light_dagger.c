/*  dests upon breaking   */

inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
int light;

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("dagger");
   set_short("a dagger");
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

query_save_flag(){ return 0; }  /* storable */

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
    this_player()->hit_player(150+random(100));
    if(!random(3))
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
        target->hit_player(5+random(10));
      else
        target->heal_self(-5-random(10));
      return 8; 
    }
  }
  if(light >= 50)
  {
    tell_room(environment(target), 
      HIY+"\n\tA huge blast of light strikes "+target->QN+"!\n\n"+NORM);
    target->heal_self(-light / 2);
    light -= 30+random(25);
  }
  if(!random(5))
  {
    tell_object(environment(), 
      HIY+"Light pours into your body!\n"+NORM);
    environment()->add_spell_point(5+random(5));
    environment()->add_hit_point(-2);
  }
  else if(!random(5))
  {
    tell_object(environment(), 
      "You slash "+target->QN+" with your dagger of light.\n");
    tell_room(environment(target), 
      ENV->QN+" slashes "+target->QN+" with "+ENV->POS+
      " dagger of light.\n", ({ environment() }));
    light += 5;
    if(target->query_hp() > 5)
      target->hit_player(5);
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
}

