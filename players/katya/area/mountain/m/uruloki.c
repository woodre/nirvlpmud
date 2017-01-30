/*
 *     uruloki.c              
 *     Katya@Nirvana
 *     Copyright (c) 2007 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object gold;
    gold = clone_object("obj/money");
    gold->set_money(random(10000) + 5000);
    move_object(gold,this_object());

     set_name("Uruloki");
     set_alt_name("dragon");
     set_alias("uruloki");
     set_short("Uruloki");
     set_race("dragon");
     set_long("\
   An enormous fire breathing dragon with brawny golden scales\n\
and fierce, red, soul piercing eyes.  His vast golden wings extend \n\
for miles when he takes to flight.  His long spiked tail drapes behind\n\
his ferocious body.  His razor like claws can pierce through any\n\
materials, as well as his lengthy fangs.\n");
     set_gender("male");
     set_aggressive(1);
     set_level(30);
     set_ac(30 + random(10));
     set_wc(60 + random(10));
     set_hp(5000 + random(500));
     set_wc_bonus(54);
     set_al(-650);
set_dead_ob(this_object()); 
     enable_commands();
   }
}

heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  {
    if(random(100) < 25) slash();
    if(random(100) < 25) breath_fire();
    if(random(100) < 25) tail_lash();
  }
}

slash()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" "+HIC+"RAKES"+NORM+" you with its claws!\n\n");
  tell_room(environment(),
    "\n\t"+query_name()+" "+HIC+"RAKES"+NORM+" "+
    attacker_ob->query_name()+" with its claws!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50));
}

breath_fire()
{
  object *obs;
  int    s;
  tell_room(environment(),
  "A sulfury "+HIK+"smoke"+NORM+" puffs from "+query_name()+"'s nostrils.\n");
  tell_room(environment(),
    HIR+"\n\t\tFIRE leaps from "+query_name()+"'s throat!\n\n"+NORM);
    
  obs = all_inventory(environment());
  s = sizeof(obs);
  
  while(s --)
  {
    if(obs[s] && living(obs[s]) && obs[s] != this_object())
    {
      obs[s]->hit_player(50+random(50),"other|fire");
    }
  }
  return 1;
}

tail_lash()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" "+HIC+"LASHES"+NORM+" you with its TAIL!\n\n");
  tell_room(environment(),
    "\n\t"+query_name()+" "+HIC+"LASHES"+NORM+" "+
    attacker_ob->query_name()+" with its TAIL!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(50+random(50));
}

catch_tell(str)
{
  string x;
  if(sscanf(str,"%s died.%s",x,x) == 2) 
    call_out("eat_corpse", 1);
}

eat_corpse()
{
  object c;
  if(c = present("corpse", environment()))
  {
    tell_room(environment(),
      query_name()+" greedily devours the corpse!\n");
    heal_self(100);
    destruct(c);
  }
}

monster_died() {
  move_object(clone_object(
    "/players/katya/area/mountain/o/uclaw"),
      environment());
  return 0;
}

