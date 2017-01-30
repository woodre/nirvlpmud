/*
 * captain.c
 * Secret Police captain
 */

inherit "obj/monster";

object hero;
string hero_name;

void handle_say(string str);
void handle_arrival(string str);
void handle_giving(string str);

void
reset(status arg)
{
  object wep, membership;
  monster::reset(arg);
  if (arg)
    return;
  set_name("captain");
  set_alias("secret police captain");
  set_alt_name("The Captain");
  set_short("A Secret Police captain");
  set_long("This is a police captain in the Secret Police.\n"+
           "He looks like an experienced and resourceful man,\n"+
           "and the safety of the realm rests safely in his hands.\n");
  set_gender("male");
  set_level(12);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_ac(3);
#else
  set_hp(180);
  set_wc(16);
  set_ac(9);
#endif
  set_al(250);

  /* Spell setup */
  set_chance(20);
  set_spell_dam(20);
  set_spell_mess1("The Secret Police captain kicks his opponent very hard.");
  set_spell_mess2("The Secret Police captain kicks you very hard. You are hurt!");

  /* Load Chats */
  set_chat_chance(2);
  load_chat("The captain says: The safety of the realm is threatened!\n");
  load_chat("The captain says: We need a hero for a dangerous mission.\n");
  load_chat("The captain says: Demons can not be allowed as pets.\n");
  load_chat("The captain says: It is illegal to keep demons as pets.\n");
  load_chat("The Secret Police captain walks back and forth.\n");

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
  set_function("handle_giving");
  set_type("gives");
  set_match("");

  /* Gear */
  wep = clone_object("obj/weapon");
  wep->set_name("short sword");
  wep->set_alias("shortsword");
  wep->set_alt_name("sword");
  wep->set_class(15);
  wep->set_value(700);
  wep->set_weight(2);
  wep->set_short("A short sword");
  move_object(wep, this_object());
  init_command("wield short sword");

  membership = clone_object("/players/padrone/secret_police/membership");
  move_object(membership, this_object());
}

void
handle_say(string str)
{
  string who, phrase, a , b;
  object client;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
   && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("The Secret Police captain looks brain damaged.\n");
    return;
  }
  if ((who == "The captain") || (who == "Captain"))
    return;
  phrase = lower_case(phrase);
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The captain looks confused.\n");
    return;
  }
  if (!hero || !present(hero, environment(this_object())))
    handle_arrival(who + " arrives.");
  else if (client != hero)
  {
    say("The captain says: Please be quiet, " + who + ". I am talking to " +
        hero_name + ".\n");
  }
  else if (sscanf(phrase, "%syes%s", a, b) == 2
        || sscanf(phrase, "%sok%s", a, b) == 2
        || sscanf(phrase, "%swill%s", a, b) == 2)
  {
    object orders, badge;
    say("The captain says: Thank you, " + who +
        "! This country will not forget you!\n");
    say("The captain has prepared a small speech:\n");
    say("    The well-known wizard Padrone, sometimes known as the Wizard of\n"+
        "    (hah!) Law and Balance, has captured a demon of chaos. In his usual\n"+
        "    megalomaniac stupidity he didn't kill it, but just put it in a\n");
    say("    cell in his (in)famous walking castle. There is even a rumor that\n"+
        "    he did this only to use the demon as a guard for his money!\n"+
        "    That demon is an abomination and a threat, and it must be killed!\n");
    hero = 0;
    orders = clone_object("/players/padrone/secret_police/orders");
    orders->init_orders(who);
    move_object(orders, client);

    log_file("padrone", ctime(time()) + ": " + who +
             " (level " + client->query_level() +
             ") got the secret police orders.\n");

    say("The captain says: Here are your orders");
    if (!present("sp_membership", client))
    {
      badge = clone_object("/players/padrone/secret_police/membership");
      badge->set_name(who);
      badge->set_temporary(1);
      move_object(badge, client);
      say(", and your Secret Police membership");
    }
    say(".\n");
    say("    Report back here as soon as your mission is completed!\n");
  }
  else if ((sscanf(phrase, "%sno%s", a, b) == 2)
        || (sscanf(phrase, "%sdanger%s", a, b) == 2)
        || (sscanf(phrase, "%ssorry%s", a, b) == 2)
        || (sscanf(phrase, "%swon't%s", a, b) == 2))
  {
    say("The captain says: Bah! Coward!\n");
  }
  else
  {
    say("The captain says: What? What are you talking about?\n");
  }
}

void
handle_arrival(string str)
{
  string who, rest, n;
  object client;
  int client_level;

  if (sscanf(str, "%s arrives%s", who, rest) != 2)
  {
    say("The captain looks brain damaged.\n");
    return;
  }
  if ((who == "The captain") || (who == "Captain"))
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The captain looks confused.\n");
    return;
  }
  n = (string)client->query_name();
  if (present("chaosblade of death", client))
  {
    say("The captain says: Ah! Welcome back, " + n + "!\n" +
        "    I see that you have solved your mission!\n" +
        "    Now give that evil sword of chaos to me!\n");
    return;
  }
  if (present("sp_orders", client))
  {
    say("The captain says: What are you doing here, " + n + "?\n"+
        "    You have an important mission to do! Don't just stand there! Move! Move!\n");
    return;
  }
  client_level = (int)client->query_level();
  say("The captain looks up from his papers and says: Welcome, " + n + "!\n");
  say("    I am looking for a person for a very special mission,\n");

  if (hero && present(hero, environment(this_object())) &&
              hero->query_level() > client_level)
  {
    say("    but I think " + hero_name + " here can do it.\n");
  }
  else if (client_level < 5)
  {
    say("    but it's much to dangerous for you, kid. Run along and play now!\n");
  }
  else if (client_level < 10)
  {
    say("    but, frankly, you are not experienced enough for this kind of mission.\n");
  }
  else if (client_level < 15)
  {
    say("    and you might just possibly have a chance, even though I would\n"+
        "    prefer to give this mission to someone with more experience.\n");
    say("    Will you do it?\n");
    hero = client;
    hero_name = who;
  }
  else if (client_level < 20)
  {
    say("    and you are just the kind of person I need!\n");
    say("    Will you do it?\n");
    hero = client;
    hero_name = who;
  }
  else
  {
    say("    and you, Mighty Wizard, can of course do it in no time (grovel, grovel).\n"+
        "    Feel free to try this little mission,\n"+
        "    but try not to mess things up for those\n"+
        "    level 15-19 players who really should be doing it!\n");
    say("    Do you want to do it?\n");
    hero = client;
    hero_name = who;
  }
}

void
handle_giving(string str)
{
  string who, what, whom;
  object the_chaosblade, client, badge;

  if (sscanf(str, "%s gives %s to %s.\n", who, what, whom) == 3)
  {
    the_chaosblade = present("chaosblade of death", this_object());
    if (this_object()->id(lower_case(whom)) && the_chaosblade)
    {
      /* Gave the Chaosblade to the captain, and he has it now */
      client = present(lower_case(who), environment(this_object()));
      if (!client)
      {
        say("The captain looks confused.\n");
        return;
      }
      say("The captain says: You have done your country a great service, " +
          who + "!\n");
      say("    Here is your reward, 10000 gold coins!\n");
      tell_object(client, "Captain gives you 10000 gold coins.\n");
      client->add_money(10000);
      say("The captain sends the Chaosblade away for destruction.\n");
      destruct(the_chaosblade);
      this_object()->add_weight(-8);

      log_file("padrone", ctime(time()) + ": " + who +
               " (level " + client->query_level() +
               ") gave Chaosblade to the secret police Captain!\n");

      badge = present("sp_membership", client);
      if (!present("sp_membership", client))
      {
        badge = clone_object("/players/padrone/secret_police/membership");
        badge->set_name(who);
        move_object(badge, client);
      }
      badge->set_temporary(0);
      say("The captain says: You are now also a full member of the Secret Police!\n");
    }
  }
}
