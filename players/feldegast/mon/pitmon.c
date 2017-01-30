#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("pit monster");
  set_alt_name("monster");
  set_short(GRN + "Pit" + NORM + " Monster");
  set_long(
    "This twisted creature is about ten feet wide, and covered with long\n"+
    "slimy tentacles.  Its body has a gaping maw with sharp pointy teeth\n"+
    "and a long tongue.\n"
  );
  set_gender("male");
  set_race("creature");
  set_level(19);
  set_wc(29);
  set_ac(16);
  set_hp(460);
  set_al(-200);
  set_chat_chance(5);
  load_chat("The Pit monster waves its tentacles at you.\n");
  set_a_chat_chance(20);
  load_a_chat("The Pit Monster bashes its foe against a wall!\n");
  load_spell(15,25,0,
    "\nThe Pit Monster wrabs its tentacles around you and squeezes!\n\n",
    "\nThe Pit Monster wraps its tentacles around #ATT#!\n\n");
}

void aggr_hb() {
  object ob;
  if(!environment()) return;
  if(!attacker_ob) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->is_player()) {
         say("The Pit Monster notices you!\n");
         this_object()->attacked_by(ob);
         call_out("aggr_hb",30);
         return;
      }
      ob=next_inventory(ob);
    }
  }
  call_out("aggr_hb",10);
}
