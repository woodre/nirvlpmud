/*
 *     xiulicoatl.c              
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
     set_name("Xiulicoatl");
     set_alt_name("dragon");
     set_alias("xiulicoatl");
     set_short("Xiulicoatl");
     set_race("dragon");
     set_long("\
   Xiulicoatl is an adolescent ice breathing dragon.  Aqua blue \n\
colored wings span out for great lengths.  Hes soul piercing eyes\n\
burn, as his razor like fangs drip with the lust of freshly iced flesh.\n\
His huge magnificent claws that rip through flesh like hot butter.\n\
Xiumlicoatls tail covered in razor-like spikes, which could thrust\n\
through any matter.\n");
     set_gender("male");
     set_aggressive(1);
     set_level(20);
     set_ac(20 + random(10));
     set_wc(45 + random(10));
     set_hp(4000 + random(500));
     set_wc_bonus(60);
     set_al(-400);
set_dead_ob(this_object()); 
     enable_commands();
   }
}

heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  {
    if(random(75) < 25) rip();
    if(random(75) < 25) breath_ice();
    if(random(75) < 25) tail_lash();
  }
}

rip()
{
  tell_object(attacker_ob,
    "\n\t"+query_name()+" "+HIB+"BITES"+NORM+" you with his razor-like fangs!\n\n");
  tell_room(environment(),
    "\n\t"+query_name()+" "+HIB+"BITES"+NORM+" "+
    attacker_ob->query_name()+" with his razor-like fangs!\n",
    ({ attacker_ob }));
    
  attacker_ob->hit_player(40+random(40));
}

breath_ice()
{
  object *obs;
  int    s;
  tell_room(environment(),
"A deep "+HIK+"rumble"+NORM+" penetrates "+query_name()+"s throat.\n");
tell_room(environment(),
HIC+"\n\t\tICE soars out of "+query_name()+"s throat!\n\n"+NORM);
    
  obs = all_inventory(environment());
  s = sizeof(obs);
  
  while(s --)
  {
    if(obs[s] && living(obs[s]) && obs[s] != this_object())
    {
      obs[s]->hit_player(40+random(40),"other|ice");
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
    
  attacker_ob->hit_player(40+random(40));
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
move_object(clone_object("/players/katya/area/mountain/o/xhelm.c"), environment()); }

