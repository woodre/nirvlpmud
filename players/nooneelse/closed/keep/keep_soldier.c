/*
  keep_soldier.c - designed for use in the keeps
*/

inherit "obj/monster";
inherit "/players/nooneelse/closed/keep/keep_common";

int last_move;
object this_keep;

reset(arg) {
  object sword, coins;
  if (arg) return;
  ::reset();

  set_name("soldier");
  set_alias("man");
  set_level(10);
  set_hp(250);
  set_wc(14);
  set_ac(7);
  set_short("A soldier");
  set_long("He's a very strong looking soldier.\n");
  set_aggressive(0);
  coins=clone_object("obj/money");
  coins->set_money(250);
  move_object(coins, this_object());
  sword=clone_object("/players/nooneelse/closed/keep/keep_soldier_sword");
  move_object(sword, this_object());
  call_out("soldier_move", 15);
}

soldier_move() {
tell_room(environment(this_object()),
          ">>> in soldier_move.  last_move="+last_move+"\n");
  if (last_move==0) {
    command("up");
    last_move=1;
  }
  if (last_move==1) {
    command("down");
    last_move=2;
  }
  if (last_move==2) {
    command("east");
    last_move=3;
  }
  if (last_move==3) {
    command("west");
    last_move=0;
  }
  call_out("soldier_move", random(20)+10);
}

heart_beat() {
  object player_obj, next_obj;
  int found_one, i;
  player_obj = first_inventory(environment(this_object()));
  while(player_obj) {
    next_obj=next_inventory(player_obj);
    if (player_obj->is_player()) {
      if (!THRONE_ROOM->query_protected(player_obj->query_name())) {
        tell_object(player_obj,
                    "\nThe soldier decides you are an intruder and attacks!\n");
        if (player_obj->query_level() >= 32)
          tell_object(player_obj, "Since you're a wizard, he won't really.\n");
        else
          this_object()->attack_object(player_obj);
      }
      else
        tell_object(player_obj,
          "\nThe soldier decides you are not an intruder and ignores you.\n");
    }
    player_obj=next_obj;
  }
  ::heart_beat();
}
