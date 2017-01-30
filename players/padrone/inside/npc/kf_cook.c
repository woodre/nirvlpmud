/*
 * kf_cook.c
 * Kung Fu Cook
 */

inherit "obj/monster";

void ticket_check(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("Kung-Fu Cook");
  set_alias("cook");
  set_level(random(2) + 5);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_male();
  set_hp(80);
  set_ac(0);
#else
  switch (this_object()->query_level())
  {
    case 5:
      set_hp(75);
      set_wc(8);
      set_ac(4);
      break;
    default:
      set_hp(90);
      set_wc(9);
      set_ac(5);
      break;
  }
#endif
  set_short("The Incredible Kung-Fu Cook");

  /* Get ticket and weapon */
  move_object((object)"/players/padrone/outside/front_yard"->make_ticket(),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/kf_chopper"),
              this_object());
  init_command("wield chopper");

  /* catch_tell setup */
  set_object(this_object());
  set_function("ticket_check");
  set_type("arrives");
  set_match("");
}

void
ticket_check(string str)
{
  string who, rest;
  object suspect;

  if (sscanf(str, "%s arrives%s", who, rest) != 2)
    return;
  suspect = present(lower_case(who), environment(this_object()));
  if (!suspect)
    return;
  if (!present("castle ticket", suspect))
  {
    say("Kung-Fu Cook immediately notices that "+who+" hasn't got a ticket.\n");
    this_object()->attacked_by(suspect);
  }
}
