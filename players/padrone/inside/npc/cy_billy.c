/*
 * cy_billy.c
 * Billy the Giant from courtyard.c
 */

inherit "obj/monster";

void ticket_check(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("billy");
  set_alias("giant");
  set_race("giant");
  set_level(15);
#if 0  /* Adjusted for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_hp(200);
#else
  set_hp(250);
  set_wc(20);
  set_ac(12);
#endif
  set_al(-100);
  set_short("Billy the giant");
  set_long("Billy is a giant. You gasp at his incredible size!\n"+
           "He towers high above you, and wields a tree trunk as a weapon.\n"+
           "Billy and his big brother Sam have been employed by the Wizard\n"+
           "as guards. You guess that the Wizard probably doesn't worry\n"+
           "much about intruders anymore.\n"+
           "You know that there used to be a platoon of U.S. Marines\n"+
           "guarding this castle, but now they have been replaced\n"+
           "with something more intimidating...\n");

  /* Setup spells (just messages, no damage */
  set_chance(20);
  set_spell_mess1("Billy the giant laughs happily.");
  set_spell_mess2("Billy the giant laughs at you.");

  /* catch_tell setup */
  set_object(this_object());
  set_function("ticket_check");
  set_type("arrives");
  set_match("");

  /* Gear and stat reset after wield */
  move_object((object)"/players/padrone/outside/front_yard"->make_ticket(),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/b_trunk"),
              this_object());
  set_wc(18);
}

void
ticket_check(string str)
{
  object suspect;
  string who, rest;
  if (sscanf(str, "%s arrives%s", who, rest) != 2)
    return;
  suspect = present(lower_case(who), environment(this_object()));
  if (!suspect)
    return;
  if (!present("castle ticket", suspect))
  {
    say("Billy immediately notices that " + who + " hasn't got a ticket.\n");
    this_object()->attacked_by(suspect);
  }
}
