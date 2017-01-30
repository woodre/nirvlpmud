#include "/players/mythos/closed/guild/def.h"
inherit "obj/monster";
reset(arg)  {
  object weapon;
  ::reset(arg);
  if(arg) return;
  set_name("ruler");
  set_race("avatar");
  set_short("Dream Master");
  set_alias("master");
  set_long("He is the 'ruler' of this realm.  He spins your dreams and he banishes them.\n"+
    "He is the master of where he is- the dreams of the mortals.\n");
  set_hp(225);
  set_level(15);
  set_al(500);
  weapon = clone_object("/players/mythos/awep/dstaff.c");
  move_object(weapon,this_object());
  init_command("wield staff");
  set_wc(17);
  set_ac(15);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("Something has changed......\n");
  load_chat("You feel like you lost something...\n");
  load_a_chat("You feel weak.\n");
  load_a_chat("You can no longer see!\n");
  set_chance(7);
  set_spell_dam(random(50));
  set_spell_mess1("The old man looks up and whispers a word.  You feel funny.\n");
  set_spell_mess2("The old man glances up and intones.\n"+
    "\nEverything grows hazy.....then....\n"+
    "\n\n       YOU  FEEL GREAT PAIN    \n\n"+
    "\nThings come back and all you know is that you are AFRAID.\n");
}

monster_died() {
  if(present(fear,this_object()->query_attack())) {
    present(fear,this_object()->query_attack())->set_sif(1);
    present(fear,this_object()->query_attack())->save_dark();
    command("uu",this_object()->query_attack());
    tell_object(this_object()->query_attack(),
      "You feel power flood you!\nThe power to take energy from another is in your hands!\n"+
      "To cast type <siphon>\n");
/*
  write_file("/players/mythos/closed/guild/task_spell",
    ctime(time())+" "+(this_object()->query_attack())->query_real_name()+
    "  siphon\n");
*/
  }
}
