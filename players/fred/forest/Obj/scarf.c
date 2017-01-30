inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("scarf");
  set_short("A flowing scarf");
  set_long(
  "A heavy cotton scarf knitted by Fred in all his spare time.\n");
  set_type("scarf");
  set_ac(1);
  set_weight(1);
  set_value(250);
}

do_special(owner)
{
  /*  Just because I'm evil */
  if(owner->query_guild_name() != "rangers")
  {
    if((int)owner->query_attrib("cha") > random(100))
    {
      tell_object(owner,
        "Your scarf flaps gently in the breeze....\n");
      tell_room(environment(owner),
        owner->query_name()+"'s scarf flaps gently in the breeze...\n", ({ owner }));
      return -(1+random(5));
    } 
    return -(1+random(5));
  }
  if((int)owner->query_attrib("cha") > random(100))
  {
    tell_object(owner,
      "Your scarf flaps gently in the breeze...\n");
    tell_room(environment(owner),
      owner->query_name()+"'s scarf flaps gently in the breeze...\n", ({ owner }));
    owner->heal_self(random(4));
    return random(2);
  }
  return;
}
