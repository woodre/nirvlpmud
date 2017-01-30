#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

  set_name("guide");
  set_alias("guide");
  set_alt_name("tourguide");
  set_race("creature");
  set_short("a tour guide");
  set_long(
    "The tour guide waves her hands wildly, trying to get the\n"+
    "attention of everyone in her group.  She points out all of\n"+
    "the attractions and explains the history of each attraction\n"+
    "in excrutiating detail.  This tour guide has more energy than\n"+
    "anyone you have ever seen.\n\n");
  set_level(11);
  set_hp(165);
  set_al(100 + random(100));
  set_wc(15);
  set_ac(9);
  set_aggressive(0);

  set_chat_chance(15);
    load_chat(
      "The tour guide mumbles: And to the left you see the wondrous...\n");
  set_a_chat_chance(15);
    load_a_chat(
      "The tour guide cries out: Now who is going to guide all of\n"+
      "                          these tourists?\n");

  gold = clone_object("obj/money");
  gold->set_money(450 + random(50));
  move_object(gold,this_object());
}

