#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(ob->query_name())

int num;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Soldier of Fortune");
  set_alias("soldier");
  set_short("Soldier of Fortune");
  set_long(
  "This man looks very out of place here.  He is dressed in jungle\n"+
  "fatigues and carries an M-60 automatic machine gun.  The Soldier\n"+
  "looks confused and perhaps a little lost.\n");
  set_race("human");
  set_gender("male");
  set_level(23);
  set_hp(1000);
  set_al(0);
  set_aggressive(0);
  set_chat_chance(30);
  set_a_chat_chance(40);
  load_chat("Soldier says: Sh*t, I don't think I'm in Kansas anymore.\n");
  load_chat("Soldier says: Where the f*ck am I!?\n");
  load_chat("Soldier says: Are you a communist?\n");
  load_chat("Soldier looks around.\n");
  load_chat("Soldier of Fortune looks you over.\n");
  load_chat("Soldier of Fortune looks lost.\n");
  load_chat("Soldier of Fortune says: This place is full of wierdos!\n");
  load_a_chat("Soldier screams:  Take that, motherf*cker!\n");
  load_a_chat("Soldier says: Who the hell do you think you are, King Arthur?\n");
  load_a_chat("Soldier of Fortune looks a little nervous.\n");
  load_a_chat("Soldier screams: Die Commie!\n");
  load_a_chat("Soldier of Fortune says: Don't f*ck with me, man!\n");
  load_a_chat("Soldier kicks you in the stomach!\n");
  move_object(clone_object("players/pavlik/weapons/machine_gun"),
  this_object());
  move_object(clone_object("players/pavlik/items/ilstkarn/ammo_box"),
  this_object());
  init_command("wield gun");
  set_wc_bonus(18);
  set_wc(24);  /* low WC because the weapon has high return */
  set_ac(21);
}

query_ilstkarn(){ return 1; }

/*
 * As usual, I don't like players being able to stop a fight.
 */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * None of this heal_self crap
 */
heal_self(i) {
  if(i <= 0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

