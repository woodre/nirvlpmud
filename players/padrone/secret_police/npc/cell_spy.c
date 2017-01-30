/*
 * cell_spy.c
 * Enemy spy in cell
 */

inherit "obj/monster";

void handle_say(string str);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("spy");
  set_alias("enemy spy");
  set_short("An enemy spy");
  set_long("This is an enemy spy that has been arrested by the Secret Police.\n"+
           "He is small, devious, and dressed in a black coat and hat.\n");
  set_gender("male");
  set_level(3);
#if 0 /* Adjusting for Nirvana monster.guide - Rumplemintz */
  set_hp(100);
#else
  set_hp(30);
  set_wc(6);
  set_ac(3);
#endif
  set_chance(20);
  set_spell_dam(20);
  set_spell_mess1("The spy hits his opponent with a karate kick.");
  set_spell_mess2("The spy hits you with a karate kick. You are hurt!");
  set_chat_chance(20);
  load_chat("The enemy spy glares at you.\n");
  load_chat("The enemy spy says nothing.\n");
  set_object(this_object());
  set_function("handle_say");
  set_type("says");
  set_match("");
  set_type("tells you:");
  set_match(" ");
}

void
handle_say(string str)
{
  string who, junk;
  object client;

  if ((sscanf(str, "%s says%s\n", who, junk) != 2)
   && (sscanf(str, "%s tells%s\n", who, junk) != 2))
  {
    return;
  }
  else
  {
    client = present(lower_case(who), environment(this_object()));
    if (client)
    {
      say("Spy says: You lie! Take this, you capitalist lackey!\n");
      this_object()->attacked_by(client);
    }
  }
}
