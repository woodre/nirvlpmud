/*
 * Plauge object - Does random(10) damage for 5 heart beats
 * Rumplemintz
 */

#include <ansi.h>

int time;
object owner, badge;

string short() { return 0; }

int set_owner(object ob) {
  owner = ob;
  badge = present("V-GUILD", owner);
  return 1;
}

int id(string str) { return str == "dopple_plague_ob"; }

void reset(status arg) {
  if (arg) return;
  time = 0;
}

int start_me() {
  if (environment(this_object())->is_npc())
    set_heart_beat(1);
}

void heart_beat() {

  if (environment(this_object())->query_npc()) {
    if (environment(this_object())->query_hp() > 0 && time < 5) {
      time++;
      environment(this_object())->add_hit_point(-(random(10)));
      tell_room(environment(owner),
                  environment(this_object())->query_name() +
                  " writhes in pain from the plauge!\n", ({ owner }) );
      tell_object(owner,
                  environment(this_object())->query_name() +
                  " writhes in pain from your plague!\n");
    }
    else {
      tell_room(environment(owner),
                  environment(this_object())->query_name() +
                  " shakes the plague.\n", ({ owner }));
      tell_object(owner,
                  "Your plauge spell has worn off " +
                  environment(this_object())->short() + ".\n");
      set_heart_beat(0);
      badge->set_plagued(0);
      destruct(this_object());
    }
  }
}

