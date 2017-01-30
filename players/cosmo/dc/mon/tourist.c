#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

  set_name("tourist");
  set_alias("tourist");
  set_alt_name("tourist");
  set_race("creature");
  set_short("a tourist");
  set_long(
    "The tourist chats in a strange tongue, which oddly\n"+
    "enough, you understand.  Pictures are constantly being\n"+
    "snapped and videos are filmed non-stop, as the tourist\n"+
    "rudely pushes others aside to get the best shot.\n\n");
  set_level(11);
  set_hp(165);
  set_al(100 + random(100));
  set_wc(15);
  set_ac(9);
  set_aggressive(0);

  set_chat_chance(5);
    load_chat(
      "A tourist asks: Will you take a picture of me and my spouse?\n");
  set_a_chat_chance(15);
    load_a_chat(
      "A tourist cries out: No wonder this city has the highest\n"+
      "                     murder rate in the country!\n");

  gold = clone_object("obj/money");
  gold->set_money(450 + random(50));
  move_object(gold,this_object());
}

