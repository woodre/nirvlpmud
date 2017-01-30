inherit "/players/vertebraker/closed/std/monster.c";
#include "/players/tristian/lib/goblin_define.h"
object gold;

reset(arg){

  ::reset(arg);
  if (arg) return;

  set_name("Goblin Wizard");
  set_alt_name("wizard");
  set_race("goblin");
  set_alias("goblin");
  set_short("Goblin Wizard");
  set_long("A goblin of slightly larger stature than all the rest.\n"+
           "He is wearing some robes of high quality.  He is muttering\n"+
           "under his breath and weaving his hands around in the air.\n");
  set_level(10);
  set_ac(14);
  set_wc(5+random(5));
  set_hp(180);
  set_al(-100);
  set_aggressive(0);
  set_chat_chance(4);
      load_chat("The Wizard mutters under his breath.\n");
      load_chat("The Wizard orders you out of his tent.\n");
  set_a_chat_chance(8);
      load_a_chat("The Wizard says, 'Sprong oinko boinko prong!'\n");
      load_a_chat("The Wizard throws some bat guano at you!'\n");
  set_dead_ob(this_object());

  set_chance(20);
  set_spell_dam(5);

  set_spell_mess1(
    "\nThe tips of the wizards fingers"+HIR+ " flare"+NORM+ " and you get hit with a "+HIG+"magic missile."+NORM+"\n");
  set_spell_mess2(
    "\nThe tips of the wizards fingers"+HIR+ " flare"+NORM+ " and you get hit with a "+HIG+"magic missile."+NORM+"\n");

  move_object(
      clone_object("/players/tristian/realms/goblin/obj/goblin_robe.c"),
         (this_object()));
  init_command("wear misc");

}

monster_died(){
    tell_room(environment(),
        "You discover a pile of coins among the remains of the goblin.\n");
  gold = clone_object("/obj/money.c");
  gold->set_money(300+random(50));
  move_object(gold, environment());
}