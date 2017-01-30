/*
 * cy_sam.c
 * Sam the giant from courtyard.c
 */

inherit "obj/monster";

object ticket, trunk;

void ticket_check(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("sam");
  set_alias("giant");
  set_race("giant");
  set_level(16);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_hp(250);
#else
  set_hp(300);
  set_ac(13);
  set_wc(22);
#endif
  set_al(-200);
  set_short("Sam the giant");
  set_long("Sam is a giant. You gasp at his incredible size!\n"+
           "He towers high above you, and wields a huge tree trunk as a weapon.\n"+
           "Sam and his little brother Billy have been employed by the Wizard\n"+
           "as guards. You guess that the Wizard probably doesn't worry\n"+
           "much about intruders any more.\n"+
           "You know that there used to be a platoon of U.S. Marines\n"+
           "guarding this castle, but now they have been replaced\n"+
           "with something more intimidating...\n");

  /* Setup spells */
  set_chance(20);
  /* no damage, just another way to use messages */
  set_spell_mess1("Sam the giant laughs happily.");
  set_spell_mess2("Sam the giant laughs at you.");

  /* Gear and adjusted stat setup */
  ticket = (object)"/players/padrone/outside/front_yard"->make_ticket();
  move_object(ticket, this_object());
  trunk = clone_object("/players/padrone/inside/npc/obj/s_trunk");
  move_object(trunk, this_object());
  init_command("wield trunk");
  set_wc(22);

  /* catch_tell setup */
  set_object(this_object());
  set_function("ticket_check");
  set_type("arrives");
  set_match("");
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
    say("Sam immediately notices that " + who + " hasn't got a ticket.\n");
    this_object()->attacked_by(suspect);
  }
}
