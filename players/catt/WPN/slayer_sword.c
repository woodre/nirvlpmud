
inherit "/obj/weapon.c";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
   set_name("black slayer sword");
   set_alias("sword");
   set_short("black slayer sword");
  set_long("While to casual observation this is just another sword, it\n"+
           "exudes an aura of darkness and death.\n");
  set_class(12);
   set_params("other|dark",0,"necro_hit");
  set_weight(3);
  set_value(2000);
}


int necro_hit(object attacker) {
  if(!attacker || !wielded_by)
    return 0;
   if(random(20) > 11) {
      tell_object(wielded_by, "Your sword drains "+
         attacker->query_name()+"\n");
      tell_object(attacker,"You feel drained as "+
         wielded_by->query_name()+"'s sword touches you.\n");
    if(environment())
      tell_room(environment(),
      wielded_by->query_name()+"'s sword glimmers with an evil darkness.\n",
      ({wielded_by,attacker}));
   return 4;
  }
  return 0;
}
  
