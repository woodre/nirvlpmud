/*
  g_path_cryptw.c
*/

inherit "room/room";

int door_is_open, door_is_locked;
string door_long_desc;
object door1, door2;

realm() { return "NT"; }

reset(arg) {
  if (arg) {
    door1->set_locked(1);
    door2->set_locked(0);
    return 0;
  }

  set_light(0);
  short_desc="Crypt";
  long_desc="You are in a dark crypt.  There is a door set in the west wall.\n";
  dest_dir=({
             "players/nooneelse/graveyard/g_path8", "east",
             "players/nooneelse/graveyard/g_path_cryptw_inner", "west",
           });
  if (!present("door")) {
    door1=clone_object("players/nooneelse/obj/door");
    door2=clone_object("players/nooneelse/obj/door");
    door_long_desc = ("The door seems to be made of solid marble.\n");
    door1->set_all(
    "players/nooneelse/graveyard/g_path_cryptw west marble marblekey 1 1 1");
    door2->set_all(
"players/nooneelse/graveyard/g_path_cryptw_inner east marble marblekey 1 0 1");
    door1->set_door(door2);
    door2->set_door(door1);
    door1->set_door_long(door_long_desc);
    door2->set_door_long(door_long_desc);
    move_object(door1, this_object());
    call_other("players/nooneelse/graveyard/g_path_cryptw_inner", "???", 0);
    move_object(door2, "players/nooneelse/graveyard/g_path_cryptw_inner");
  }
}
