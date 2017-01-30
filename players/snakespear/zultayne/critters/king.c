#include "/players/snakespear/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;
set_short(HIC+"The King of "+GRY+"Zultayne"+NORM);
set_name("king");
set_alias("monster");
set_alt_name("protector");
set_race("spirit");
set_long(HIC+
  "  This is the King of Zultayne.  He hides from outsiders and is quite\n"+
  "ready to finish what his family could not.  Thriving on Majik, the King\n"+
  "studies all he can, in hopes of one day bringing back his lovely bride,\n"+
  "Lady Turton.  His mourning has been long and his tears have dried.  Now\n"+
  "he works hard everyday to do nothing more than return his bride to her\n"+
  "home and bring back all the Gargoyle Family.  Are you gonna stand in his\n"+
  "way of happiness?\n"+
  "\t\tMajik swiftly moves in and out of the King.\n\n"+NORM);

set_level(20);
set_hp(600+random(100));
set_al(-100+random(100));
set_wc(25+random(10));
set_ac(21);
set_heal(10,5);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat(HIW+"You can feel the power here...\n"+NORM);
set_a_chat_chance(5);
  load_a_chat(HIW+"Colors fly all around the King.\n"+NORM);

set_chance(20);
set_spell_dam(35+random(15));

set_spell_mess1(
  HIC+"\n\n\tSwirling colors flow freely!\n\n"+NORM);
set_spell_mess2(
  HIC+"\n\n\n\tSwirling colors flow through you!\n\n\n"+NORM);


gold = clone_object("obj/money");
gold->set_money(2000+random(1000));
move_object(gold,this_object());
}

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/staff.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      HIW+"\nThe King groans, 'You shall feel the power!'\n"+NORM);
return 0; }
