/*
 * sheriff.c
 * Padrone's sheriff
 */

inherit "obj/monster";

void handle_arrival(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("sheriff");
  set_short("The Sheriff");
  set_level(10);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_hp(200);
#else
  set_hp(150);
  set_wc(14);
  set_ac(8);
#endif
  set_al(300);
  set_short("The Sheriff");
  set_long("This is the local Sheriff.\n"+
           "He is old and tough. Before assuming this office he travelled\n"+
           "the world, thus becoming an experienced warrior.\n");

  /* Setup spell messages, no damage */
  set_chance(20);
  set_spell_dam(0);
  set_spell_mess1("The sheriff yells: Criminal! You'll hang for this!");
  set_spell_mess2("The sheriff yells: Criminal! You'll hang for this!");

  /* catch_tell setup */
  set_object(this_object());
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");

  /* Gear and stats after wield */
  move_object(clone_object("/players/padrone/inside/npc/obj/sheriff_sword"),
              this_object());
  init_command("wield sword");
  move_object((object)"/players/padrone/outside/front_yard"->make_ticket(),
              this_object());
}

void
handle_arrival(string str)
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
    say("The Sheriff immediately notices that "+who+" hasn't got a ticket.\n");
    this_object()->attacked_by(suspect);
  }
  if ("/players/padrone/inside/sheriffs_office"->is_wanted(who))
  {
    say("The Sheriff says: "+who+", you are a criminal! Die for your evil deeds!\n");
    this_object()->attacked_by(suspect);
  }
}
