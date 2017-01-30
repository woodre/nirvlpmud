/*
 * Pizza Hut Manager
 *
 * Changelog:
 * 
 *   2/00 - Snow:
 *          Changed level from 20 to 16, stats from guide level 20 to slightly
 *          weak 16 due to the managers being guarded. Money reduced but still
 *          high for 16.
 *
 *  9/23/2014 - Rumplemintz
 *              Added quest for Wicket's Ninja Turtles and fixed some
 *              formatting / casting.
 */

#pragma strong_types  /* Rumplemintz */

#if 1 /* 0 to disable quest, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#define MSAY(x) say("The Manager says: " + x + "\n")

object quester;
#endif

inherit "/obj/monster";

#ifdef NINJA_TURTLE_QUEST
/* Prototypes for the quest - Rumplemintz */
int start_quest(string color, object player);
int one_more(string color, object player);
int end_quest(object player);
#endif

void reset(int arg) {
  object obj;

  ::reset(arg);
  if (arg)
    return;

  set_name("manager");
  set_alias("hutboss");
  set_short("A Pizza Hut Manager");
  set_long("This is a mean looking Manager, she looks very busy.\n");
  set_gender("female"); /* Rumplemintz - female in long so make it a female! */
  set_race("human");
  set_level(16);
  set_ac(14);
  set_wc(22);
  set_hp(300);
  set_al(-650);
  set_whimpy();
  set_chat_chance(20);
  set_a_chat_chance(20);
  load_chat("The Manager grins evilly at you.\n");
  load_chat("The Manager yells at one of the drivers.\n");
  load_chat("The Manager says: What the hell do you want?!\n");
  load_chat("The Manager says: Is there a problem with your order?\n");
  load_a_chat("The Manager says: You fool!  You can't be this stupid!\n");
  load_a_chat("The Manager slaps you across the face.\n");
  load_a_chat("The Manager punches you in the stomach.\n");
  load_a_chat("The Manager says: Surrender and I shall let you live...\n");

  obj = clone_object("obj/money");
  obj->set_money(random(1000) + 1000);
  move_object(obj, this_object());
  obj = clone_object("/players/emerson/weap/pencil.c");
  move_object(obj, this_object());
  init_command("wield pencil");
}

#ifdef NINJA_TURTLE_QUEST /* Rumplemintz */
void init() {
  ::init();
  add_action("start_quest", "inquire");
}

int start_quest(string color, object player) {
  switch(color) {
    case "blue":
      call_out("BLUE", 2, player);
      return 1;
      break;
    case "purple":
      call_out("PURPLE", 2, player);
      return 1;
      break;
    default:
      if (this_player()->query_quests("ninja_turtles")) {
        write("The Manager says: You have already completed this quest.\n");
        return 1;
      }
      say(this_player()->query_name() +
          " inquires about problems with pizza service.\n",
          ({ this_player() }));
      write("You inquire about problems with pizza service.\n");
      call_out("PIZZA", 2);
      return 1;
      break;
  }
  return 0;
}

/* PIZZA - Called by the 'inquire' command, begin the quest ------------- */
int PIZZA() {
  MSAY("Indeed I have been having issues with a mutant turtle!");
  call_out("PIZZA2", 2);
  return 1;
}

int PIZZA2() {
  MSAY("The turtle wears a blue mask and wields dual katanas.\n");
  MSAY("He has been sneaking off with the pizza from my delivery\n" +
       "                  guys and I need help to stop this thing before\n" +
       "                  my business goes broke.....\n");
  call_out("PIZZA3", 2);
  return 1;
}

int PIZZA3() {
  MSAY("Bring me his mask and turn it in.\n");
  return 1;
}
/* ---------------------------------------------------------------------- */

/* BLUE - Called by handing in the blue bandana mask - 2nd stage of quest */
int BLUE(object player) {
  quester = player;
  MSAY("Thank you for this favor " + quester->query_name() + "!\n");
  call_out("BLUE2", 2);
  return 1;
}

int BLUE2() {
  MSAY("I need you to address one of the same monsters.\n");
  call_out("BLUE3", 2);
  return 1;
}

int BLUE3() {
  MSAY("This one wears a purple mask and seems to be sneaking around\n" +
       "                  at night as well, stealing pizza and cold drinks\n" +
       "                  from my cooler and other places.\n");
  call_out("BLUE4", 2);
  return 1;
}

int BLUE4() {
  MSAY("Please bring back his mask and turn it in.\n");
  return 1;
}
/* ---------------------------------------------------------------------- */
/* PURPLE - Called by handing in the purple mask - final stage of quest   */
int PURPLE(object player) {
  quester = player;
  MSAY("Thank you " + quester->query_name() + "!\n");
  call_out("PURPLE2", 2);
  return 1;
}

int PURPLE2() {
  say("The Manager sighs deeply and shakes her head.\n");
  call_out("PURPLE3", 2);
  return 1;
}

int PURPLE3() {
  MSAY("I'm sorry to ask " + quester->query_name() + ", but I have\n" +
       "                  two more of those beasts that remain a terror\n" +
       "                  and a big impact on the funds and profits of my\n" +
       "                  company.\n");
  call_out("PURPLE4", 2);
  return 1;
}

int PURPLE4() {
  MSAY("They seem to pull pranks and harass the drivers to distract\n" +
       "                  them.  Then they take the pizza and vanish\n" +
       "                  without a trace.\n");
  call_out("PURPLE5", 2);
  return 1;
}

int PURPLE5() {
  MSAY("Bring me back the two remaining masks and I will reward you\n" +
       "                  greatly.\n");
  return 1;
}
/* ---------------------------------------------------------------------- */
/* one_more() - Called when you hand in one of the final masks, without
 *              having done the other
 */
int one_more(string color, object player) {
  quester = player;
  MSAY("That's great " + quester->query_name() + "!\n" +
        "                  Do you have the " + color + " mask as well?\n");
  return 1;
}
/* ---------------------------------------------------------------------- */
/* end_quest() - complete the quest, set it, and reward the points        */
int end_quest(object player) {
  quester = player;
  say("The Manager dances around praising " + quester->query_name() +
      "!\n", ({ quester }));
  tell_object(quester, "The Manager exclaims: You have fulfilled my quest!\n");
  tell_object(quester, "The Manager dances around praising you!\n");
  tell_object(quester, "The Manager thanks you deeply, and hands you a " +
                       "Martial Arts bandana.\n");
  move_object(clone_object("/players/wicket/ninja_turtles/quest/bandana"),
              quester);
  quester->set_quest("ninja_turtles");
  return 1;
}
#endif /* NINJA_TURTLE_QUEST */
