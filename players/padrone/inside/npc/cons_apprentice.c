/*
 * cons_apprentice.c
 * Apprentice wizard in consultation room
 */

inherit "obj/monster";

object teleportee, latest_teleportee, bird, client;
object gold, stone, key;
status busy_teleporting;

void handle_say(string str);
void handle_arrival(string str);
status take_money(int sum);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("apprentice");
  set_level(19);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_male();
  set_hp(400);
#else
  set_hp(450);
  set_wc(28);
  set_ac(16);
#endif
  set_al(100);
  set_short("The Wizard's apprentice");
  set_long("This is the Wizard's apprentice.\n"+
           "Although still a young man\n"+
           "he has already mastered many of the secrets of magic.\n"+
           "He is wearing a strange hat and looks somewhat dangerous.\n"+
           "Since the Wizard is not in today, the apprentice is handling\n"+
           "the consultations. Talk to him and state your problem!\n");

  /* Setup spells */
  set_chance(20);
  set_spell_dam(40);
  set_spell_mess1("The apprentice casts a fireball.");
  set_spell_mess2("The apprentice casts a fireball at you.");

  /* Load chats */
  set_chat_chance(2);
  load_chat("The apprentice says: How can I help you?\n");
  load_chat("The apprentice studies the appointment book.\n");

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

  /* Grab some gear */
  move_object(clone_object("/players/padrone/obj/wizardshat"),
              this_object());
  init_command("wear hat");
  move_object(clone_object("/players/padrone/inside/npc/obj/w_knife"),
              this_object());
  init_command("wield knife");
  key = clone_object("obj/key");
  key->set_type("crystal");
  key->set_code("towerdoor");
  move_object(key, this_object());
  gold = clone_object("obj/money");
  gold->set_money(10 + 10*random(5));
  move_object(gold, this_object());
  stone = clone_object("/players/padrone/obj/gravstone");
  stone->set_weight(-2);
  move_object(stone, this_object());
  move_object(clone_object("/players/padrone/obj/immunity"), this_object());

  set_dead_ob(this_object());
}

status
monster_died(object app)
{
  object companion;
  companion = present("invisible companion", environment(this_object()));
  if (companion)
    destruct(companion);
  teleportee = 0;
  latest_teleportee = 0;
  busy_teleporting = 0;
  if (bird)
  {
    tell_room(environment(bird),
              "Suddenly the small bird fades away and disappears.\n");
    move_object(bird, "/players/padrone/store");
    destruct(bird);
  }
  return 0;
}

void
bird_handle_leaves(string str)
{
  string who, rest;

  if (sscanf(str, "%s leaves %s.\n", who, rest) != 2)
  {
    say("The bird looks brain damaged.\n");
    write("The bird looks brain damaged.\n");
    return;
  }
  if (teleportee && who == (string)teleportee->query_name())
    bird->init_command(rest);
}

void
bird_handle_say(string str)
{
  string who, phrase, a, b;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
   && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("The bird looks brain damaged.\n");
    write("The bird looks brain damaged.\n");
    return;
  }
  phrase = lower_case(phrase);
  client = present(lower_case(who), environment(bird));
  if (!client)
  {
    say("The bird looks confused.\n");
    write("The bird looks confused.\n");
    return;
  }
  if (client != teleportee)
  {
    say("The small bird doesn't seem interested in what " + who +
        " has to say.\n");
    return;
  }
  if (sscanf(phrase, "%syes%s", a, b) == 2
   || sscanf(phrase, "%steleport%s", a, b) == 2
   || sscanf(phrase, "%sok%s", a, b) == 2)
  {
    say("The small bird chirps happily, flutters around " + who +
        ", and flies away.\n");
    write("The small bird chrips happily, flutters around " + who +
          ", and flies away.\n");
    move_object(bird, "/players/padrone/store");
    destruct(bird);
    latest_teleportee = teleportee;
    tell_object(teleportee, "You are magically transferred somewhere.\n");
    teleportee->move_player("X", environment(this_object()));
    if (!present("castle ticket", teleportee))
    {
      object ticket;
      tell_room(environment(this_object()),
                "The apprentice says: As a bonus you get a free ticket to the"+
                " Castle of Padrone!\n");
      ticket = (object)"/players/padrone/outside/front_yard"->make_ticket();
      if (teleportee->add_weight(1))
      {
        move_object(ticket, teleportee);
        say("The apprentice gives ticket to " +
            teleportee->query_name() + ".\n");
        write("The apprentice gives ticket to " +
              teleportee->query_name() + ".\n");
      }
      else
      {
        say("The apprentice drops the ticket.\n");
        write("The apprentice drops the ticket.\n");
        move_object(ticket, environment(this_object()));
      }
    }
    teleportee = 0;
    busy_teleporting = 0;
  }
  else if (sscanf(phrase, "%snot%s", a, b) == 2
        || sscanf(phrase, "%sno%s", a, b) == 2
        || sscanf(phrase, "%sdo not%s", a, b) == 2
        || sscanf(phrase, "%sdon't%s", a, b) == 2)
  {
    say("The small bird looks disappointed and flies away.\n");
    write("The small bird looks diappointed and flies away.\n");
    move_object(bird, "/players/padrone/store");
    destruct(bird);
    tell_room(environment(this_object()),
              "The apprentice says: " + teleportee->query_name() +
              " didn't want to be teleported.\n");
    teleportee = 0;
    busy_teleporting = 0;
  }
  else
  {
    say("The small bird doesn't understand. It is still waiting for something.\n");
    write("The small bird doesn't understand. It is still waiting for something.\n");
  }
}
status
take_money(int sum)
{
  object the_money;

  if (client->query_money() < sum)
  {
    tell_object(client, "That would cost " + sum +
                " gold pieces, which you don't have.\n");
    return 0;
  }
  tell_object(client, "You pay " + sum +
              " gold coins for the magic assistance.\n");
  client->add_money(-sum);

  /* Put the money in the vault -- but not if it's a wizard */
  if (client->query_level() < 20)
  {
    the_money = clone_object("obj/money");
    the_money->set_money(sum);
    "/players/padrone/walker/cell"->put_in_vault(the_money);
  }
  if (!random(10))
  {
    tell_object(client,
                "The apprentice fumbles and -- BLAMMM!! The spell failed." +
                " You are now a frog.\n");
    say("The apprentice fumbles and turns " +
        client->query_name() + " into a frog.\n");
    client->frog_curse(1);
    return 0;
  }
  return 1;
}

int
abs(int n)
{
  if (n < 0)
    return -n;
  else
    return n;
}

void
handle_say(string str)
{
  string who, phrase, a, b, a_name, out;
  int oa, na, add;
  object obj;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
   && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("The apprentice looks brain damaged.\n");
    return;
  }
  if ((who == "The apprentice") || (who == "Apprentice"))
    return;

  if (!bird || !teleportee)
    busy_teleporting = 0;
  if (busy_teleporting)
  {
    say("The apprentice is concentrating on a spell and doesn't listen.\n");
    return;
  }
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The apprentice looks confused.\n");
    return;
  }
  if (sscanf(phrase, "%shelp%s", a, b) == 2
   || sscanf(phrase, "%sHelp%s", a, b) == 2)
  {
    say("The apprentice says: Well, " + who + ", I do have some powers.\n"+
        "                     But magic assistance is of course not free.\n");
  }
  else if ((sscanf(phrase, "%scost%s", a, b) == 2)
        || (sscanf(phrase, "%sprice%s", a, b) == 2)
        || (sscanf(phrase, "%sPrice%s", a, b) == 2)
        || (sscanf(phrase, "%slist%s", a, b) == 2)
        || (sscanf(phrase, "%stell%s", a, b) == 2)
        || (sscanf(phrase, "%sTell%s", a, b) == 2)
        || (sscanf(phrase, "%sservice%s", a, b) == 2)
        || (sscanf(phrase, "%swhat%s", a, b) == 2)
        || (sscanf(phrase, "%sWhat%s", a, b) == 2))
  {
    say("The apprentice says: The prices are fixed:\n"+
        "          Know Alignment:                 100 gold coins\n"+
        "          Heal yourself:                 4000 gold coins\n"+
        "          Heal someone else:             2000 gold coins\n");
    say("          Teleport a player here         1000 gold coins\n"+
        "          Change Alignment:               100 gold coins per point\n"+
        "          Change Alignment Description:    20 gold coins (temporary)\n" +
        "          Remove Frog Curse:              500 gold coins\n");
    say(" - Just tell me what you want, the apprentice smiles.\n");
  }
  else if (phrase == "know alignment" || phrase == "Know alignment")
  {
    if (!take_money(100))
      return;
    say("The apprentice casts the spell KNOW ALIGNMENT.\n");
    tell_object(client, "The apprentice tells you: Your alignment is " +
                client->query_alignment() + ".\n");
  }
  else if (sscanf(phrase, "heal %s", a_name) == 1
        || sscanf(phrase, "Heal %s", a_name) == 1)
  {
    if (a_name == "myself" || a_name == "me")
      obj = client;
    else
    {
      obj = present(lower_case(a_name), environment(this_object()));
      if (!obj || !living(obj))
      {
        say("The apprentice says: But there is no " + a_name + " here!\n");
        return;
      }
    }
    if (obj == client)
    {
      if (!take_money(4000))
      return;
    }
    else
    {
      if (!take_money(2000))
      return;
    }
    say("The apprentice casts the spell HEAL.\n");
    obj->heal_self(1000);
    tell_object(obj, "You are healed by the Wizard's Apprentice.\n");
    /* Snicker, snicker...*/
    this_object()->heal_self(1000);
    tell_object(client, "The apprentice heals himself at the same time.\n");
  }
  else if (phrase == "heal" || phrase == "Heal")
  {
    say("The apprentice says: Heal who? Say 'heal ...', and I'll do it.\n");
  }
  else if (sscanf(phrase, "teleport %s", a_name) == 1
        || sscanf(phrase, "Teleport %s", a_name) == 1)
  {
    object teleportee_env;
    teleportee = find_living(lower_case(a_name));
    if (!teleportee)
    {
      say("The apprentice says: Sorry, I cannot find " + a_name + ".\n");
      return;
    }
    else if (teleportee->query_npc())
    {
      say("The apprentice says: Sorry, but that is just a simple monster.\n"+
          "                     I only teleport players.\n");
      return;
    }
    else if (present(teleportee, environment(this_object())))
    {
      say("The apprentice says: Don't be stupid.\n");
      return;
    }
    say("The apprentice says: Ok, this may take some time...\n");
    if (!take_money(1000))
      return;
    say("The apprentice casts the spell TELEPORT.\n");
    busy_teleporting = 1;

    /* We create a small bird that teleports to the presumptive teleportee
     * and asks him/her/it if they want to be teleported.
     * Otherwise, someone might use this spell for evil purposes...
     */
    bird = clone_object("obj/monster");
    bird->set_name("bird");
    bird->set_level(1);
#if 0  /* Adjusting for Nirvana monster.guide -- Rumplemintz */
    bird->set_hp(10);
    bird->set_ac(10);
#else
    bird->set_hp(15);
    bird->set_wc(5);
    bird->set_ac(3);
#endif
    bird->set_al(100);
    bird->set_short("A small bird that shimmers strangely");
    bird->set_long("This small bird doesn't seem quite natural.\n"+
                   "There must be magic involved here...\n");
    /* Load chats */
    bird->set_chat_chance(25);
    bird->load_chat("The small bird flutters happily.\n");
    bird->load_chat("The small bird sings cheerfully.\n");
    bird->load_chat("The small bird seems to be waiting for something.\n");
    bird->load_chat("The small bird seems to be waiting for someone to say "+
                    "something.\n");
    bird->load_chat("The small bird looks at you questioningly.\n");

    /* catch_tell setup */
    bird->set_object(bird);
    bird->set_function("bird_handle_say");
    bird->set_type("says");
    bird->set_match("");
    bird->set_type("tells you:");
    bird->set_match(" ");
    bird->set_function("bird_handle_leaves");
    bird->set_type("leaves");
    bird->set_match("");
    move_object(bird, environment(this_object()));
    move_object(this_object(), environment(this_object()));
    teleportee_env = environment(teleportee);
    move_object(bird, teleportee_env);
    tell_room(teleportee_env,
              "Suddenly a small bird comes flying from no obvious direction.\n");
    tell_room(teleportee_env,
              "It seems to whisper something to " +
              teleportee->query_name() + ".\n");
    tell_object(teleportee, "The bird whispers to you: Greetings from " +
                client->query_name()+"!\n - Do you want to be teleported?\n");
  }
  else if (phrase == "teleport" || phrase == "Teleport")
  {
    say("The apprentice says: Yes, but who? Say 'teleport ...', and I'll do it.\n");
  }
  else if (sscanf(phrase, "change alignment to %d", na) == 1
        || sscanf(phrase, "Change alignment to %d", na) == 1)
  {
    if (na > 10000 || na < -10000)
    {
      say("The apprentice says: " + na + "? Go away!\n");
      return;
    }
    oa = (int)client->query_alignment();
    if (!take_money(100 * abs(oa - na)))
      return;
    add = na - (oa * 9) / 10;
    say("The apprentice casts the spell CHANGE ALIGNMENT\n" +
        " to change the alignment from " + oa + " to " + na + ".\n");
    client->add_alignment(add);
  }
  else if ((phrase == "change alignment")
        || (phrase == "Change alignment")
        || (sscanf(phrase, "Change alignment %d", a) == 1)
        || (sscanf(phrase, "change alignment %d", a) == 1))
  {
    say("The apprentice says: What? Say 'change alignment to ...', and I'll do it.\n");
  }
  else if (sscanf(phrase, "change alignment to %s", a) == 1
        || sscanf(phrase, "Change alignment to %s", a) == 1)
  {
    say("The apprentice says: The alignment has to be a numeric value.\n");
  }
  else if (sscanf(phrase, "change alignment description to %s", a) == 1
        || sscanf(phrase, "Change alignment description to %s", a) == 1)
  {
    if (!take_money(20))
      return;
    say("The apprentice casts the spell CHANGE ALIGNMENT DESCRIPTION.\n");
    this_object()->set_level(100);
    client->set_alignment(a);
    this_object()->set_level(10);
  }
  else if ((phrase == "change alignment description")
        || (phrase == "Change alignment description")
        || (sscanf(phrase, "change alignment description %s", a) == 1)
        || (sscanf(phrase, "Change alignment description %s", a) == 1))
  {
    say("The apprentice says: What? Say 'change alignment description to ...',\n"+
        "                     and I'll do it.\n");
  }
  else if (phrase == "remove frog curse"
        || phrase == "Remove frog curse")
  {
    if (!take_money(500))
      return;
    say("The apprentice casts the spell REMOVE FROG CURSE.\n");
    client->frog_curse(0);
  }
  else if ((sscanf(phrase, "%sfrog%s", a, b) == 2)
        || (sscanf(phrase, "%scurse%s", a, b) == 2))
  {
    say("The apprentice says: I can remove a frog curse.\n"+
        "                     Just say 'remove frog curse', and I'll do it.\n");
  }
  else if ((sscanf(phrase, "%stitle%s", a, b) == 2)
        || (sscanf(phrase, "%sdescription%s", a, b) == 2))
  {
    say("The apprentice says: I know two spells to handle alignments,\n"+
        "                     KNOW ALIGNMENT and CHANGE ALIGNMENT.\n"+
        "                     Just say 'know alignment',\n"+
        "                     or 'change alignment to ...',\n"+
        "                      - and I'll do it.\n");
  }
  else
  {
    say("The apprentice looks puzzled.\n");
  }
}

void
handle_arrival(string str)
{
  string who, rest;

  if (sscanf(str, "%s arrives%s", who, rest) != 2)
  {
    say("The apprentice looks brain damaged.\n");
    return;
  }
  if ((who == "The apprentice") || (who == "Apprentice"))
    return;
  if (!bird || !teleportee)
    busy_teleporting = 0;
  if (busy_teleporting)
  {
    say("The apprentice is concentrating on a spell.\n");
    return;
  }
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The apprentice looks confused.\n");
    return;
  }
  if (client == latest_teleportee)
  {
    latest_teleportee = 0;
    return;
  }
  if (!present("castle ticket", client))
  {
    say("The apprentice immediately notices that " + who +
        " hasn't got a ticket.\n");
    this_object()->attacked_by(client);
    return;
  }
  say("The apprentice says: Welcome, " + client->query_name() + ".\n");
  if (present("padrone", environment(this_object())))
    say(" - The Wizard is standing right here, but he is inventing new magic\n"+
        " - and cannot be interrupted. But maybe I can help you?\n");
  else
    say(" - The Wizard is not here today, he's out looking for\n"+
        " - a castle he lost. But maybe I can help you?\n");
}
