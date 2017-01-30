/*
 * eliza.c
 * Eliza the psychiatrist
 */

inherit "obj/monster";

/* prototypes */
void handle_say(string str);
void handle_arrival(string str);
void handle_leaving(string str);
string turn_phrase(string phrase);
string replace_word(string phrase, string replace_from, string replace_to);
status word_in_phrase(string word, string phrase);

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("eliza");
  set_alias("Eliza");
#if 0 /* To make this the same as Padrone did it -- Rumplemintz */
  set_short("Eliza the psychiatrist");
#endif
  set_long("This is Eliza, a professional psychatrist.\n"+
           "She is middle-aged and a bit plump, and she looks at you\n"+
           "understandingly.\n");
  set_level(3);
#if 0  /* Adjusted for Nirvana monster.guild - Rumplemintz */
  set_female();
#else
  set_hp(45);
  set_wc(7);
  set_ac(3);
#endif
  set_al(100);

  /* Setup spells */
  set_chance(10);
  set_spell_dam(10);
  set_spell_mess1("Eliza gives some medicine to her patient.");
  set_spell_mess2("Eliza forces some vile-tasting medicine down your throat.");

  /* Load the chats */
  set_chat_chance(5);
  load_chat("Eliza says: Tell me about your problems!\n");
  load_chat("Eliza says: Tell me about your mother!\n");
  load_chat("Eliza says: Lie down and tell me about your problems!\n");
  load_chat("Eliza says: How do you feel?\n");
  load_chat("Eliza looks at you understandingly.\n");

  /* Load the attacking chats */
  set_a_chat_chance(40);
  load_a_chat("Eliza says: It is obvious that you have some serious problems.\n");
  load_a_chat("Eliza says: Haven't you taken your medicine today?\n");
  load_a_chat("Eliza says: Have you had these violent tendencies before?\n");
  load_a_chat("Eliza says: For your own good, you should be put in a hospital.\n");
  load_a_chat("Eliza says: Wait here for the nice young men in the clean white coats.\n");
  load_a_chat("Eliza says: This case is too hard for me. Consult Sir Obliterator instead.\n");

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
  set_function("handle_leaving");
  set_type("leaves");
  set_match("");

  /* Give her a ticket */
  move_object((object)"/players/padrone/outside/front_yard"->make_ticket(),
              this_object());
}

void
handle_say(string str)
{
  string who, phrase, a, b;
  object client;
  int n;

  if ((sscanf(str, "%s says: %s\n", who, phrase) != 2)
      && (sscanf(str, "%s tells you: %s\n", who, phrase) != 2))
  {
    say("Eliza looks brain damaged.\n");
    return;
  }
  if (who == "Eliza")
    return;
  client = present(lower_case(who), environment(this_object()));
  if (!client)
  {
    say("Eliza looks confused.\n");
    return;
  }
  if (sscanf(phrase, "%s %s", a, b) != 2)
    say("Eliza says: You seem to be a bit short with me. Please tell me more!\n");
  else if (sscanf(phrase, "%s?", a) == 1)
  {
    while (sscanf(phrase, "%s?", a) == 1)
      phrase = a;
    say("Eliza says: Why do you ask if " + turn_phrase(phrase) + "?\n");
  }
  else if (word_in_phrase("mother", phrase)
        || word_in_phrase("father", phrase)
        || word_in_phrase("sister", phrase)
        || word_in_phrase("brother", phrase))
    say("Eliza says: Tell me more about your family!\n");
  else if (word_in_phrase("sex", phrase))
    say("Eliza says: Please tell me more. Don't forget any details.\n");
  else if (word_in_phrase("computer", phrase)
        || word_in_phrase("computers", phrase))
    say("Eliza says: You have your mind on computers, it seems.\n");
  else if (word_in_phrase("monster", phrase)
        || word_in_phrase("monsters", phrase))
    say("Eliza says: Why do you talk about monsters? There are no monsters.\n");
  else if (word_in_phrase("kill", phrase)
        || word_in_phrase("murder", phrase)
        || word_in_phrase("weapon", phrase)
        || word_in_phrase("destroy", phrase))
    say("Eliza says: This is not a healthy way of thinking.\n");
  else if (word_in_phrase("Eliza", phrase)
        || word_in_phrase("eliza", phrase))
    say("Eliza says: Don't talk about me, tell me about yourself instead.\n");
  else
  {
    while (sscanf(phrase, "%s!", a) == 1)
      phrase = a;
    while (sscanf(phrase, "%s.", a) == 1)
      phrase = a;
    n = random(6);
    switch (n)
    {
      case 1:
        say("Eliza says: Go on, don't be afraid.\n");
        break;
      case 2:
        say("Eliza says: Perhaps this has something to do with your inhibitions?\n");
        break;
      case 3:
        say("Eliza says: Do you say that because of some problems in your childhood?\n");
        break;
      case 4:
        say("Eliza says: Why do you say that " + turn_phrase(phrase) + "?\n");
        break;
      case 5:
        say("Eliza says: What makes you think that " + turn_phrase(phrase) + "?\n");
      default:
        say("Eliza says: Maybe your life has something to do with this.\n");
        break;
    }
  }
  if (!random(20))
  {
    tell_object(client, "Talking to Eliza is good for you. You feel "+
                        "mentally strong.\n");
    client->restore_spell_points(4);
  }
}

void
handle_arrival(string str)
{
  string who, rest;

  if (sscanf(str, "%s arrives%s", who, rest) != 2)
  {
    say("Eliza looks brain damaged.\n");
    return;
  }
  if (who == "Eliza")
    return;
  if (!present(lower_case(who), environment(this_object())))
  {
    say("Eliza looks confused.\n");
    return;
  }
  say("Eliza says: Hello, " + who + ". Tell me about your problems!\n");
}

void
handle_leaving(string str)
{
  string who, rest;
  if (sscanf(str, "%s leaves %s.\n", who, rest) != 2)
  {
    say("Eliza looks brain damaged.\n");
    return;
  }
  if (who == "Eliza")
    return;
  if (random(4))
  {
    init_command(rest);
    if (present(lower_case(who), environment(this_object())))
    say("Eliza says: Don't go yet, "+who+". We must discuss your problems.\n");
  }
}

string
turn_phrase(string phrase)
{
  phrase = replace_word(phrase, "yours", "PUT-MINE-HERE");
  phrase = replace_word(phrase, "your", "PUT-MY-HERE");
  phrase = replace_word(phrase, "you", "PUT-I-HERE");
  phrase = replace_word(phrase, "Your", "PUT-MY-HERE");
  phrase = replace_word(phrase, "You", "PUT-I-HERE");
  phrase = replace_word(phrase, "I", "you");
  phrase = replace_word(phrase, "i", "you");
  phrase = replace_word(phrase, "me", "you");
  phrase = replace_word(phrase, "my", "your");
  phrase = replace_word(phrase, "My", "your");
  phrase = replace_word(phrase, "mine", "yours");
  phrase = replace_word(phrase, "PUT-I-HERE", "I");
  phrase = replace_word(phrase, "PUT-MY-HERE", "my");
  phrase = replace_word(phrase, "PUT-MINE-HERE", "mine");
  phrase = replace_word(phrase, "I are", "I am");
  phrase = replace_word(phrase, "are I", "am I");
  phrase = replace_word(phrase, "you am", "you are");
  phrase = replace_word(phrase, "am you", "are you");
  return phrase;
}

string
replace_word(string phrase, string replace_from, string replace_to)
{
  string a, b;

  phrase = "BEGIN-SENTINAL " + phrase + " END-SENTINAL";
  while (sscanf(phrase, "%s "+replace_from+" %s",a,b) == 2) /* " from " */
    phrase = a + " " + replace_to + " " + b;
  while (sscanf(phrase, "%s "+replace_from+",%s",a,b) == 2) /* " from," */
    phrase = a + " " + replace_to + "," + b;
  while (sscanf(phrase, "%s "+replace_from+".%s",a,b) == 2) /* " from." */
    phrase = a + replace_to + "." + b;
  while (sscanf(phrase, "%s "+replace_from+"!%s",a,b) == 2) /* " from!" */
    phrase = a + " " + replace_to + "!" + b;
  sscanf(phrase, "BEGIN-SENTINEL %s END-SENTINEL", phrase);
  return phrase;
}

status
word_in_phrase(string word, string phrase)
{
  string a, b;
  return (sscanf("BEGIN-SENTINEL "+phrase+" END-SENTINEL","%s "+word+"%s",
                 a, b) == 2);
}
