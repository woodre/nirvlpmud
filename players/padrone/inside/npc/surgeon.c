/*
 * surgeon.c
 * Padrone's surgeon
 */

inherit "obj/monster";

void handle_say(string str);
void handle_arrival(string str);

void
reset(status arg)
{
  object money;
  monster::reset(arg);
  if (arg)
    return;
  set_name("surgeon");
  set_level(16);
#if 0  /* Adjusting to Nirvana monster.guide - Rumplemintz */
  set_male();
  set_hp(400);
#else
  set_hp(300);
  set_wc(22);
  set_ac(13);
#endif
  set_al(200);
  set_short("A surgeon");
  set_long("The surgeon is dressed in a white coat soiled with blood.\n"+
           "He has gloves made of rubber and a face-mask.\n"+
           "Is he competent? Well, who knows...\n"+
           "But maybe you should ask him what he can do?\n");

  /* Spell setup */
  set_chance(20);
  set_spell_dam(40);
  set_spell_mess1("The surgeon performs some surgery.");
  set_spell_mess2("Argggh! The surgeon removes one of your internal organs!");

  /* Load chats */
  set_chat_chance(2);
  load_chat("The surgeon says: How can I help you?\n");
  load_chat("The surgeon sharpens his knives.\n");
  load_chat("The surgeon tests the edge of his scalpel.\n");

  /* Get some gear, set wc/ac after wield/wear  */
  move_object(clone_object("/players/padrone/inside/npc/obj/surg_knife"),
              this_object());
  init_command("wield knife");
  move_object(clone_object("/players/padrone/inside/npc/obj/surg_knife2"),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/surg_saw"),
              this_object());
  move_object(clone_object("/players/padrone/inside/npc/obj/surg_scalpel"),
              this_object());
  set_wc(22);
  set_ac(13);
  money = clone_object("obj/money");
  money->set_money(10 + random(40));
  move_object(money, this_object());

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
}

void
handle_say(string str)
{
  string who, phrase, a, b;
  object client;
  object face;
  int players_level;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
    && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("The surgeon looks brain damages.\n");
    return;
  }
  if ((who == "The surgeon") || (who == "Surgeon"))
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The surgeon looks confused.\n");
    return;
  }
  if (sscanf(phrase, "change appearance to %s", a) == 1
    || sscanf(phrase, "Change appearance to %s", a) == 1)
  {
    while (sscanf(a, "%s.", a) == 1 || sscanf(a, "%s!", a) == 1)
    {
    }
    if (a == "")
    {
      say("The surgeon says: Ha ha. Go away.\n");
      return;
    }
    say("The surgeon operates...\n");
    if (!random(10))
    {
      say("Arrgh!! He fumbled!\n");
      client->reduce_hit_point(10);
    }
    else
    {
      face = present("appearance", client);
      if (face)
        destruct(face);
      face = clone_object("/players/padrone/obj/appearance");
      face->set_description(a);
      move_object(face, client);
      say("The surgeon is finished.\n");
    }
  }
  else if ((sscanf(phrase, "%sappearance%s", a, b) == 2)
         || (sscanf(phrase, "%sdescription%s", a, b) == 2))
  {
    say("The surgeon says: I can change your appearance.\n" +
        "                  Just say 'change appearance to ...', and I'll do it.\n");
  }
  else if (sscanf(phrase, "change sex to %s", a) == 1
        || sscanf(phrase, "Change sex to %s", a) == 1)
  {
    a = lower_case(a);
    say("The surgeon operates...\n");
    if (!random(10))
    {
      say("Arrgh!! He fumbled!\n");
      client->reduce_hit_point(10);
      return;
    }
    else if (a == "m" || a == "male" || a == "man")
    {
      client->set_male();
      say(client->query_name()+" is now a man!\n");
    }
    else if (a == "f" || a == "female" || a == "w" || a == "woman")
    {
      client->set_female();
      say(client->query_name()+" is now a woman!\n");
    }
    else
    {
      client->set_neuter();
      say(client->query_name()+" is now something very strange!\n");
    }
    players_level = (int)client->query_level();
    if (!client->query_npc() && players_level < 20)
      client->set_title((string)"room/adv_guild"->get_new_title(players_level-1));
  }
  else if ((phrase == "change sex")
         || (phrase == "Change sex")
         || (sscanf(phrase, "change sex %s", a) == 1)
         || (sscanf(phrase, "Change sex %s", a) == 1))
  {
    say("The surgeon says: What? Say 'change sex to ...', and I'll do it.\n");
  }
  else if (phrase == "heal" || phrase == "heal me" || phrase == "Heal"
        || phrase == "Heal me")
  {
    say("The surgeon tries to heal you...\n");
    if (random(20))
    {
      say("Arrgh!! He fumbled!\n");
      client->reduce_hit_point(10);
    }
    else
    {
      say("The surgeon performs a successful healing operation!\n");
      say("He really looks proud. Maybe he never succeeded in this before?\n");
    }
  }
  else if (phrase == "remove frog curse"
        || phrase == "Remove frog curse")
  {
    say("The surgeon operates...\n");
    if (!random(10))
    {
      say("Arrgh!! He fumbled!\n");
      client->reduce_hit_point(10);
    }
    else
    {
      say("The surgeon cuts away the frog legs. You feel much better!\n");
      client->frog_curse(0);
    }
  }
  else if ((sscanf(phrase, "%sfrog%s", a, b) == 2)
        || (sscanf(phrase, "%scurse%s", a, b) == 2))
  {
    say("The surgeon says: I can remove a frog curse.\n"+
        "                  Just say 'remove frog curse', and I'll do it.\n");
  }
  else if (sscanf(phrase, "%heal%s", a, b) == 2)
  {
    say("The surgeon says: Heal you? Well, I could try...\n");
  }
  else if (sscanf(phrase, "%shelp%s", a, b) == 2
        || sscanf(phrase, "%sHelp%s", a, b) == 2
        || sscanf(phrase, "%scost%s", a, b) == 2
        || sscanf(phrase, "%sprice%s", a, b) == 2
        || sscanf(phrase, "%slist%s", a, b) == 2
        || sscanf(phrase, "%stell%s", a, b) == 2
        || sscanf(phrase, "%sTell%s", a, b) == 2
        || sscanf(phrase, "%sservice%s", a, b) == 2
        || sscanf(phrase, "%swhat%s", a, b) == 2
        || sscanf(phrase, "%sWhat%s", a, b) == 2
        || sscanf(phrase, "%syes%s", a, b) == 2
        || sscanf(phrase, "%sYes%s", a, b) == 2
        || sscanf(phrase, "%splease%s", a, b) == 2
        || sscanf(phrase, "%sPlease%s", a, b) == 2)
  {
    say("The surgeon says: I will gladly operate on you for free!\n");
    say("                  I can change your appearance (just say \"change appearance\n"+
        "                  to ...\") or your sex (say \"change sex to ...\")!\n");
    say("The surgeon grins evilly.\n");
  }
  else
  {
  }
}

void
handle_arrival(string str)
{
  string who, rest;
  object client;

  if (sscanf(str, "%s arrives%s", who, rest) != 2)
  {
    say("The surgeon looks brain damaged.\n");
    return;
  }
  if ((who == "The surgeon") || (who == "Surgeon"))
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("The surgeon looks confused.\n");
    return;
  }
  say("The surgeon says: Hi there, " + client->query_name() +
      "! Want some surgery?\n");
}
