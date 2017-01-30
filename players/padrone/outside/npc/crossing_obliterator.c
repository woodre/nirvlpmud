/*
 * Sir Obliterator - loaded from crossing.c
 */

inherit "obj/monster";

object follow, last_talker, violens;
string follow_name;
status found_him;

/* Prototypes */
void handle_say(string str);
void hanndle_arrival(string str);
void handle_leaving(string str);
status check_violens();

void
reset(status arg)
{
  ::reset(arg);
  if (arg)
    return;

  follow = 0;
  follow_name = 0;
  last_talker = 0;
  found_him = 0;
  violens = 0;

  set_name("obliterator");
  set_alias("sir obliterator");
  set_short("Sir Obliterator, the anti-paladin");
  set_long("Sir Obliterator is an evil anti-paladin.\n" +
           "He is dressed in black, has a grim look on his face, and is quite\n" +
           "obviously very, very dangerous. You are lucky today, however,\n" +
           "because he doesn't seem to be the least interested in you.\n" +
           "Sir Obliterator is on an important mission -- a matter of life\n" +
           "and death! Well, mostly death, really...\n");
  set_level(19);
#if 0 /* to conform with Nirvana monster.guide */
  set_hp(250);
else
  set_hp(450);
#endif
  set_al(-1000);

  /* Spells section */
  set_spell_mess1("Sir Obliterator kicks his opponent hard with his combat boots.");
  set_spell_mess2("Sir Obliterator kicks you hard with his combat boots.");
  set_chance(20);
  set_spell_dam(20);

  /* Regular chats section */
  set_chat_chance(10);
  load_chat("Sir Obliterator says: Excuse me, Sir! Have you seen a prince called Violens?\n");
  load_chat("Sir Obliterator says: Can you show me to prince Violens?\n");
  load_chat("Sir Obliterator says: You! Where is that bastard Violens?\n");
  load_chat("Sir Obliterator says: In which direction can I find prince Violens?\n");
  load_chat("Sir Obliterator says: You! Peasant! Show me to prince Violens!\n");
  load_chat("Sir Obliterator says: Have you seen a prince who calls himself Violens?\n");
  load_chat("Sir Obliterator says: I need to find a prince called Violens.\n");
  load_chat("Sir Obliterator says: Take me to Violens!\n");
  load_chat("Sir Obliterator says: I have a message for prince Violens.\n");
  load_chat("Sir Obliterator says: I am fulfilling a quest that has been laid upon me.\n");
  load_chat("Sir Obliterator says: I'm on a mission from God. But not that God.\n");
  load_chat("Sir Obliterator looks dangerous.\n");
  load_chat("Obliterator looks at you threateningly.\n");
  load_chat("Sir Obliterator says: 200 gold coins if you lead me to prince Violens!\n");
  load_chat("Sir Obliterator says: Take me to Violens and earn 200 gold coins!\n");

  /* Attacking chats section */
  set_a_chat_chance(20);
  load_a_chat("Sir Obliterator grins evilly.\n");
  load_a_chat("Sir Obliterator says: Begone, jerk! I have other things to do!\n");
  load_a_chat("Sir Obliterator says: Don't try to stop me!\n");
  load_a_chat("Sir Obliterator says: So, you are a friend of Violens, are you?\n");
  load_a_chat("Sir Obliterator laughs insanely.\n");
  load_a_chat("Sir Obliterator says: Don't think you can even TOUCH me, you nerd!\n");
  load_a_chat("Sir Obliterator says: Who put you up to this? Violens?\n");
  load_a_chat("Sir Obliterator says: Prepare to die!\n");
  load_a_chat("Sir Obliterator says: If you run away, I will not kill you. Not now, that is.\n");

  /* catch_tell section */
  set_object(this_object());
  set_function("handle_say");
  set_type("says:");
  set_match("");
  set_type("tells you:");
  set_match(" ");
  
  set_function("handle_arrival");
  set_type("arrives");
  set_match("");
  
  set_function("handle_leaving");
  set_type("leaves");
  set_match("");
  
  set_function("check_violens");
  set_type("died");
  set_match("");
  set_type("killed");
  set_match("");

  /* Handle the death */
  set_dead_ob(this_object());

  /* Handle his gear and setup his stats after wield/wear */
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_amulet"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_boots"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_helmet"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_longsword"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_mail"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_shield"),
              this_object());
  move_object(clone_object("/players/padrone/outside/npc/obj/oblit_avenger"),
              this_object());
  init_command("wear boots");
  init_command("wear helmet");
  init_command("wield longsword");
  init_command("wear chainmail");
  init_command("wear shield");

#if 0  /* here's original values, replacing with monster.guide values */
  set_ac(9);
  set_wc(30);
#else
  set_wc(28);
  set_ac(16);
#endif
}

/* Called when Obliterator dies */
int
monster_died(object ob)
{
  object murderer, corpse;

  murderer = (object)this_object()->query_attack();
  if (murderer && murderer == find_living("violens"))
  {
    say("Sir Obliterator says: Ouch! I didn't know he was THAT tough!\n");
    say("In his dying breath Sir Obliterator mumbles a spell of teleport.\n");
    say("Sir Obliterator disappears in a puff of smoke.\n");
    move_object(this_object(), "/players/padrone/store");
    corpse = present("corpse of obliterator", environment(murderer));
    if (corpse)
      move_object(corpse, "/players/padrone/store");
    return 0;
  }
  return 0;
}

void
handle_leaving(string str)
{
  string who, rest, n;

  if (check_violens())
    return;

  if (sscanf(str, "s leaves %s.\n", who, rest) != 2)
  {
    say("Sir Obliterator looks brain damaged.\n");
    return;
  }
  else if ((who == "Sir Obliterator") || (who == "Obliterator"))
    return;
  else if (who == "Violens")
  {
    this_object()->init_command(rest);
    check_violens();
  }
  else if (find_living("violens") && present(find_living("violens"),
                                             environment(this_object())))
  {
    return;
  }
  else if (who == follow_name)
  {
    this_object()->init_command(rest);
    if (!found_him)
    {
      if (check_violens() && present(follow, environment(this_object())))
      {
        say("Sir Obliterator says: Here is your reward, " +follow_name+ ".\n");
        say("Sir Obliterator gives 200 coins to " +follow_name+ ".\n");
        follow->add_money(200);
        tell_object(follow, "You feel more evil, having sold prince Violens"+
                            " to the anti-paladin.\n");
        follow->add_alignment(-200);
        follow = 0;
        follow_name = 0;
      }
    }
    else
      check_violens();
  }
  else if (random(4))
  {
    object enemy;

    /* Not following anyone: 75% chance of following anybody */
    enemy = (object)this_object()->query_attack();
    if (!enemy || (string)enemy->query_name() != who)
      this_object()->init_command(rest);
    check_violens();
  }
}

void
handle_arrival(string str)
{
  string who, rest, n;
  
  if (check_violens())
    return;
  else if (find_living("violens") && present(find_living("violens"),
                                             environment(this_object())))
    return;

  if (sscanf(str, "%s arrives%s", who, rest) !=2)
  {
    say("Sir Obliterator looks brain damaged.\n");
    return;
  }
  if (who != "Sir Obliterator" && who != "Obliterator" &&
      who != "Violens")
    say("Sir Obliterator says: Excuse me, " + who +
        ", but have you seen prince Violens?\n");
}

void
handle_say(string str)
{
  object talker;
  string who, phrase, a, b, dir, where;
  int oa, na, add;

  if (check_violens())
    return;
  else if (find_living("violens") && present(find_living("violens"),
                                             environment(this_object())))
    return;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2) &&
      (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("Sir Obliterator looks brain damaged.\n");
    return;
  }
  if ((who == "Sir Obliterator") || (who == "Obliterator"))
    return;
  phrase = lower_case(str);  /* Use the whole sentence, include "X says: " */
  talker = find_living(lower_case(who));
  if (!talker)
  {
    say("Sir Obliterator looks confused.\n");
    return;
  }
  where = 0;
  if (sscanf(phrase, "%snorth%s", a, b) == 2)
  {
    where = "north";
  }
  else if (sscanf(phrase, "%ssouth%s", a, b) == 2)
  {
    where = "south";
  }
  else if (sscanf(phrase, "%seast%s", a, b) == 2)
  {
    where = "east";
  }
  else if (sscanf(phrase, "%swest%s", a, b) == 2)
  {
    where = "west";
  }
  else if (sscanf(phrase, "%ssoutheast%s", a, b) == 2)
  {
    where = "southeast";
  }
  else if (sscanf(phrase, "%ssouthwest%s", a, b) == 2)
  {
    where = "southwest";
  }
  else if (sscanf(phrase, "%snortheast%s", a, b) == 2)
  {
    where = "northeast";
  }
  else if (sscanf(phrase, "%snorthwest%s", a, b) == 2)
  {
    where = "northwest";
  }
  if (where)
  {
    say("Sir Obliterator says: " + capitalize(where) +
        ", you say! Thank you for the information!\n");
    last_talker = talker;
    this_object()->init_command(where);
    return;
  }
  if (sscanf(phrase, "%sfollows%s", a, b) == 2)
  {
    say("Sir Obliterator says: Well then, " + who +
        ", now lead me to prince Violens!\n");
    last_talker = 0;
    follow = talker;
    follow_name = capitalize(who);
    return;
  }
  if (sscanf(phrase, "%sviolens%s", a, b) == 2)
  {
    say("Sir Obliterator says: Yes! Yes! Tell me where he is1\n");
    return;
  }
  say("Sir Obliterator says: Stop talking nonsense! Tell me where prince Violens is!\n");
  return;
}

status
check_violens()
{
  if (found_him && !violens)
  {
    say("Sir Obliterator says: Done! My quest is solved!\n");
    say("Sir Obliterator disappears in a puff of smoke.\n");
    move_object(this_object(), "/players/padrone/store");
    this_object()->hit_player(1000000);
    return 1;
  }
  if (!found_him)
  {
    violens = present("violens", environment(this_object()));
    if (violens)
    {
      found_him = 1;
      /* Stop talking */
      this_object()->remove_chat();
      this_object()->remove_a_chat();
      say("Sir Obliterator says: Well then! We meet at last, you bastard!\n");
      this_object()->init_command("wield unholy avenger");
      this_object()->set_wc(35);
      this_object()->attacked_by(violens);
      return 1;
    }
  }
  return 0;
}
