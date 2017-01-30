/*
* eddie.c
* Eddie from Eddies room
*/

inherit "obj/monster";

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("eddie");
  set_alias("eddie the mischievous prankster");
  set_level(3);
#if 0  /* Adjusting to Nirvana monster.guide - Rumplemintz */
  set_ac(6);
#else
  set_hp(45);
  set_ac(3);
  set_wc(7);
#endif
  set_al(20);
  set_short("Eddie the mischievous prankster");
  set_long("Eddie is a small, sharp-nosed man of undecidable origin. He lives\n"+
     "in the small room behind the Wizard's consultation room, and he spends\n"+
     "his days snooping on the Wizard or his Apprentice when they perform\n"+
     "strange and beautiful magic. He has actually managed to learn one\n"+
     "spell... Maybe he will show you, if you talk nicely to him?\n");

  /* Spell setup */
  set_chance(10);
  set_spell_dam(20);
  set_spell_mess1("Eddie casts the spell SEGMENTATION VIOLATION.");
  set_spell_mess2("Eddie tries to hit you with the spell SEGMENTATION VIOLATION.\n"+
     "He missed almost totally, but you are still hurt by this deadly spell.");

  /* Get a ticket */
  move_object((object)"/players/padrone/outside/front_yard"->make_ticket(),
              this_object());

  /* Load chats */
  set_chat_chance(10);
  load_chat("Eddie grins evilly.\n");
  load_chat("Eddie pokes you in the ribs.\n");
  load_chat("Eddie falls down laughing.\n");
  load_chat("Eddie smiles happily.\n");

  /* Load attacking chats */
  set_a_chat_chance(40);
  load_a_chat("Eddie casts a fireball. It hits himself, and he is badly burnt.\n");
  load_a_chat("Eddie casts a shock. It hits the ceiling.\n");
  load_a_chat("Eddie casts a magic missile. It makes a small round hole in the wall.\n");
  load_a_chat("Eddie tries to summon a flash from the sky. Luckily, nothing happens.\n");
  load_a_chat("Eddie tries to cast the spell GLOBAL NUCLEAR EARTHQUAKE. Nothing happens.\n");
  load_a_chat("Eddie tries to cast the spell FLOATING POINT EXCEPTION. Nothing happens.\n");
  load_a_chat("Eddie tries to cast the spell KILL -9. Nothing happens.\n");
  load_a_chat("Eddie tries to summon a demon. Nothing happens.\n");
  load_a_chat("Eddie tries to summon a balrog. Nothing happens.\n");
  load_a_chat("Eddie screams for the security guards. Nothing happens.\n");

  /* catch_tell setup */
  set_object(this_object());
  set_function("handle_say");
  set_type("says");
  set_match("");
  set_type("tells you:");
  set_match(" ");
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
  set_function("handle_gives");
  set_type("gives");
  set_match("");
}

void
handle_say(string str)
{
  string who, phrase, a, b, a_name;
  object obj;
  object client;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
   && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("Eddie looks brain damaged.\n");
      return;
  }
  if (who == "Eddie" || who == "eddie")
    return;
  phrase = lower_case(phrase);
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("Eddie looks confused.\n");
    return;
  }
  if (sscanf(phrase, "poke %s", a_name) == 1)
  {
    obj = find_living(a_name);
    if (!obj)
    {
      say("Eddie says: Bah! There isn't anyone called "+a_name+"!\n");
      return 0;
    }
    if (obj == this_object())
    {
      say("Eddie falls down laughing.\n");
      return 0;
    }
    if (client->query_money() < 200)
    {
      say("Eddie says: I want 200 coins to do that.\n");
      return 0;
    }
    tell_object(client, "You pay 200 gold coins for the magic assistance.\n");
    client->add_money(-200);
    say("Eddie says: Ok, here we go...\n");
    say("Eddie disappears in a puff of smoke.\n");
    move_object(this_object(), environment(obj));
    say("Eddie arrives in a puff of smoke.\n");
    tell_object(obj, "Eddie pokes you in the eye. Ouch! That hurt!\n");
    say("Eddie pokes "+obj->query_name()+" in the eye!\n", obj);
    say("Eddie says: With greetings from "+client->query_name()+"!\n");
    say("Eddie disappears in a puff of smoke.\n");
    move_object(this_object(), "/players/padrone/inside/eddies_room");
    say("Eddie arrives in a puff of smoke.\n");
    say("Eddie says: Done!\n");
    say("Eddie giggles inanely.\n");
  }
  else if (phrase == "poke")
  {
    say("Eddie says: Yes, yes, but poke who?\n");
  }
  else if ((sscanf(phrase, "%spoke%s", a, b) == 2)
        || (sscanf(phrase, "%sjoke%s", a, b) == 2)
        || (sscanf(phrase, "%sprank%s", a, b) == 2))
  {
    say("Eddie says: For 200 I'll help you with a nice joke... Just tell me"+
        "            to poke someone!\n");
  }
  else if ((sscanf(phrase, "%smoney%s", a, b) == 2)
        || (sscanf(phrase, "%scost%s", a, b) == 2)
        || (sscanf(phrase, "%sprice%s", a, b) == 2))
  {
    say("Eddie says: Oh, for 200 I'll help you with a nice joke...\n");
  }
  else
  {
    say("Eddie smiles happily.\n");
  }
}

void_handle_arrival(string str)
{
  string who, rest;
  object client;

  if (sscanf(str, "%s arrives%s", who, rest) !=2 )
  {
    say("Eddie looks brain damaged.\n");
    return;
  }
  if (who == "Eddie" || who == "eddie")
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("Eddie looks confused.\n");
    return;
  }
  say("Eddie says: Hi, " +client->query_name()+
      "! Wanna pay 200 for a nice little joke?\n"+
      "            Just tell me to poke someone!\n");
}

void
handle_gives(string str)
{
  string who, what;
  int nr_coins;

  if (sscanf(str," %s gives %s to Eddie.\n", who, what) == 2)
  {
    say("Eddie says: Gee! Thank! That's just what I always wanted!\n");
  }
  else if (sscanf(str, "%s gives you %d gold coins.\n", who, nr_coins) == 2)
  {
    if (nr_coins == 200)
      say("Eddie says: Thank you! But i don't know who to do the joke to.\n");
    else
      say("Eddie says: Thank you! I appreciate that.\n");
  }
  else
  {
    say("Eddie looks brain damaged.\n");
  }
}
