/*
  vampire_bloodgem.c  - teleport to/from an area & limited healing
                        prize given for solving nooneelse's quest
*/

#include "/players/nooneelse/color.h"

inherit "obj/treasure";

int healing_timer, user_hp, user_sp, user_max_hp, user_max_sp;

string str, return_room;

init() {
  ::init();

  add_action("go_to_inn",   "inn");
  add_action("go_back",     "back");
  add_action("destroy",     "destroy");
  add_action("heal_me",     "heal");
}


/* ------------------ go to the inn ---------------------------- */
go_to_inn() {
  if (environment(this_player())->realm()=="NT") {
    tell_object(this_player(), "You can't do that in this area.\n");
    return 1;
  }
  return_room=environment(environment(this_object()));
  move_object(this_player(), "players/nooneelse/restaurant");
  write(RED+
        "You are magically moved to a new location.\n"+
        END);
  command("look", this_player());
  return 1;
}

/* ------------------ return from the inn --------------------- */
go_back() {
  move_object(this_player(), return_room);
  write(RED+
        "You are magically moved to a new location.\n"+
        END);
  command("look", this_player());
  return 1;
}

/* ------------------ destroy the monitor ----------------------- */
destroy(str) {
  if (str != "bloodgem") return;
  tell_object(this_player(),
              RED+"The bloodgem shimmers, then vanishes.\n"+END);
  destruct(this_object());
  return 1;
}

/* ------------------ healing --------------------- */
heal_me() {
  if (healing_timer) {
    write(RED+
          "The bloodgem starts to glow, but quickly dims.  Perhaps it needs\n"+
          "time to recharge.\n"+
          END);
    return 1;
  }
  write(RED+
        "You feel a little better.\n"+
        END);
  this_player()->heal_self(20);
  healing_timer=300;
  call_out("tick_tock", 2);
  return 1;
}

tick_tock() {
  if (healing_timer) healing_timer--;
  if (healing_timer <= 0) {
    healing_timer=0;
    remove_call_out("tick_tock");
  }
  call_out("tick_tock", 2);
}

reset(arg) {
  if (arg) return 0;

  set_id("bloodgem");
  set_alias("gem");
  set_value(10000);
  set_weight(1);
}

short() {
  if (healing_timer)
    return RED+"A bloodgem"+END;
  else
    return REV_RED+"A bloodgem"+END;
}

long() {
  write(RED+
        "This is a magic bloodgem.\n\n"+
        "It can heal you a little.\n"+
        "  use: 'heal'             to heal yourself some\n\n"+
        "It also gives you the ability to quickly go places.\n"+
        "  use: 'inn'              go to the entrance of the Rainbow Inn\n"+
        "       'back'             to return whence you came\n\n"+
        "When you decide you want to be rid of it, you can.\n"+
        "  use: 'destroy bloodgem' to get rid of this device.\n"+
        END);
  return 1;
}

get() { return 1; }
