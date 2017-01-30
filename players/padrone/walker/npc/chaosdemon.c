/*
 * chaosdemon.c
 */

inherit "obj/monster";

void test_if_any_here();

void
reset(status arg)
{
  object wep;
  ::reset(arg);
  if (arg)
    return;
  set_name("chaosdemon");
  set_alias("demon");
  set_race("demon");
  set_level(19);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(1000);
  set_ac(1000);
  set_neuter();
#else
  set_hp(1000);
  set_ac(1000);   /* Leaving this, as using the sword to kill him is
                   * the correct way - Rumplemintz */
#endif
  set_al(1500 - random(3000));
  set_short("An invulnerable chaosdemon");
  set_long("This is a demon of chaos. It is not evil, not good, not neutral.\n"+
           "It is -- chaotic. It shimmers and wavers like a cloud of poison gas,\n"+
           "but you can still make out some features, like the gleaming teeth,\n"+
           "the dangerously glowing eyes, and the industrial-strength muscles in\n"+
           "what should probably be called arms.\n"+
           "This creature looks invulberable, and clearly a very special wepaon\n"+
           "is needed if you want to hurt it.\n");

  /* Spell setup */
  set_chance(20);
  set_spell_dam(40);
  set_spell_mess1("The chaosdemon casts a SEVERE INTERNAL DAMAGE AND PAIN spell.");
  set_spell_mess2("The chaosdemon casts a SEVERE INTERNAL DAMAGE AND PAIN spell at you.");

  /* Gear */
  wep = clone_object("/players/padrone/walker/npc/obj/chaosblade");
  move_object(wep, this_object());
  init_command("wield chaosblade");

  /* catch_tell setup */
  set_object(this_object());
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
  set_function("handle_leaving");
  set_type("leaves");
  set_match("");
  set_type("disappears");
  set_match("");
}

void
handle_arrival()
{
  set_heart_beat(1);
}

void
handle_leaving()
{
  if (!test_if_any_here())
    set_heart_beat(0);
}

status
test_if_any_here()
{
  object obj, this_obj;
  obj = first_inventory(this_object());
  while (obj)
  {
    this_obj = obj;
    obj = next_inventory(obj);
    if (living(this_obj) && !this_obj->query_npc())
      return 1;
  }
  return 0;
}

void
heart_beat()
{
  int al;
  al = (int)this_object()->query_alignment();
  if (al > 0)
    al = -random(1500);
  else
    al = random(1500);
  this_object()->set_al(al);
  if (al < -1000)
    tell_room(environment(this_object()), "Now the demon looks totally evil.\n");
  else if (al < 0)
    tell_room(environment(this_object()), "Now the demon looks evil.\n");
  else if (al < 1000)
    tell_room(environment(this_object()), "Now the demon looks nice.\n");
  else
    tell_room(environment(this_object()), "Now the demon looks very nice.\n");
}
