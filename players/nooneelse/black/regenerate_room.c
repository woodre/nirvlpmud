/*
  regenerate_room.c
*/

inherit "room/room";
inherit "players/nooneelse/black/guild_rooms";

reset(arg) {
  if (arg) return;

  set_light(0);
  no_castle_flag=1;
  call_out("check_for_box", 300);
}


check_for_box() {
  object obj;
  obj = present("magic box", this_object());
  if (obj) {
    move_object(obj, environment(this_object()));
    destruct(this_object());
    return;
  }
  call_out("check_for_box", 300);
}

id(str) { return str=="regenerate room" ||
                 str=="vampire regenerate room"; }

realm() { return "NT"; }
