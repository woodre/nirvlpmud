#include "/players/linus/def.h"
inherit "/obj/monster";
object master;
id(str) { return str == "linus_assist_skeleton" || str == "skeleton"; }
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("skeleton");
  set_short("A skeleton");
  set_long(
 "A skeleton, raised with dark necromantic powers.  Its only\n"+
 "purpose is to fight for its master.\n");
  set_gender("male");
  set_race("undead");
  set_level(7);
  set_wc(15);
  set_ac(6);
  set_hp(75);
  set_al(-500);
  set_a_chat_chance(4);
 load_a_chat("The skeleton attacks with a great fury!\n");
 load_a_chat("The skeleton lashes out with it's boney fingers.\n");
 load_a_chat("The skeleton lunges at his master's attacker!\n");
}

heart_beat() {
  ::heart_beat();
    if(!master || !attacker_ob || !random(30))
  {
    say("The skeleton crumbles into a pile of dust.\n");
    move_object(TO,"/room/void");
    destruct(this_object());
  }
}

set_master(ob) { master=ob; }

