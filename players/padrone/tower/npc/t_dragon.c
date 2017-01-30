/*
 * t_dragon.c
 * Tower dragon
 */

inherit "obj/monster";

object key, the_weapon;

void ticket_check(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("giant stainless steel dragon");
  set_alias("dragon");
  set_level(19);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(400);
  set_ep(444444);
  set_wc(30);
  set_ac(15);
#else
  set_hp(450);
  set_wc(28);
  set_ac(16);
#endif
  set_al(100);
  set_short("A giant stainless steel dragon with a machine gun");
  set_long("This is a giant stainless steel dragon.\n"+
           "Its eyes glow with a fire hotter than molten iron\n"+
           "and the razor claws have caused severe damage to the (stone) floor.\n"+
           "The skin seems to be made of several inches of steel.\n"+
           "It would probably be a very bad move to irritate this dragon...\n");

  /* Setup spells */
  set_chance(20);
  set_spell_dam(40);
  set_spell_mess1("The dragon breathes fire. Woooosh!");
  set_spell_mess2("You are hit by the dragon's firebreath! You are horribly burnt.");

  /* Get weapon, key */
  key = clone_object("obj/key");
  key->set_type("moderate-security");
  key->set_code("treasurydoor");
  move_object(key, this_object());
  the_weapon = clone_object("/players/padrone/obj/machinegun");
  the_weapon->set_monsters_reload_at_reset(1);
  move_object(the_weapon, this_object());
  init_command("wield machinegun");
  set_wc(28);

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
    say("Giant stainless steel dragon immediately notices that " + who +
        " hasn't got a ticket.\n");
    this_object()->attacked_by(suspect);
  }
}
