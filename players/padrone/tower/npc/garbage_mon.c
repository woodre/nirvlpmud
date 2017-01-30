/*
 * garbage_mon.c
 * default mon for the garbage room, use set_type to change it
 */

inherit "obj/monster";

string name, alias, shortdes, longdes;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_level(1);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(30);
  set_wc(2);
#else
  set_hp(15);
  set_wc(5);
  set_ac(3);
#endif

  /* load chats */
  set_a_chat_chance(30);
  load_a_chat("The " + name + " says: Help! Help!");
}

void
set_type(string str)
{
  if (!str)
    return;
  switch (str)
  {
    case "dragon":
      name = "clesetial dragon";
      alias = "dragon";
      shortdes = "Palading the clesetial dragon",
      longdes = "This monster looks almost, but not quite, like a celestial dragon.\n";
      break;
    case "bralrog":
      name = "bralrog";
      alias = "demon";
      shortdes = "A bralrog";
      longdes = "This monster looks almost, but not quite, like a balrog.\n";
      break;
    case "demoon":
      name = "demoon";
      alias = "demon";
      shortdes = "A summoned demoon is here";
      longdes = "This monster looks almost, but not quite, like a demon.\n";
      break;
    case "sirpit":
      name = "evil sirpit";
      alias = "sirpit";
      shortdes = "An evil sirpit";
      longdes = "This monster looks almost, but not quite, like an evil spirit.\n";
      break;
    case "creature":
      name = "laughsome creature";
      alias = "creature";
      shortdes = "A laughsome creature";
      longdes = "This monster looks almost, but not quite, like a loathsome creature.\n";
      break;
    case "knight":
      name = "block knight";
      alias = "knight";
      shortdes = "A block knight";
      longdes = "This monster looks almost, but not quite, like a black knight.\n";
      break;
    case "vumpire":
      name = "vumpire";
      alias = "vumpire";
      shortdes = "A vumpire";
      longdes = "This monster looks almost, but not quite, like a vampire.\n";
      break;
  }
  set_name(name);
  set_alias(alias);
  set_short(shortdes);
  set_long(longdes);
}
