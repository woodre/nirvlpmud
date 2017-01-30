#include "/players/linus/def.h"
inherit "/obj/monster";
object master;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spirit");
  set_short(HIM+"Guardian spirit"+NORM);
  set_long(
   "A guardian spirit, summoned from the heavens to assist King Reuben in his battles.\n"
  );
  set_gender("male");
  set_race("spirit");
  set_level(5);
  set_wc(12);
  set_ac(6);
  set_hp(50);
  set_al(100);
  set_a_chat_chance(4);
  load_a_chat("The spirit fights to defend his King!\n");
}

heart_beat()
{
  ::heart_beat();
  if(!master || !attacker_ob || !random(30))
  {
    say("The spirit returns to the heavens.\n");
    move_object(TO,"/room/void");
    destruct(this_object());
  }
}

set_master(ob) { master=ob; }

