/*
 cellar10.c
*/

inherit "room/room";

int door_is_open, door_is_locked;
string door_long_desc;
object door1, door2;

init() {
  ::init();

  add_action("sniff",      "sniff");
}

sniff() {
  write("As you sniff, the dust tickles your nose.\n");
  command("sneeze", this_player());
  return 1;
}

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  no_castle_flag=1;
  short_desc = "east end of cellar hall";
  long_desc =
    "You have reached the end of the hallway.  There seems to\n"+
    "be some scuffing in the dust and it is clear of cobwebs.\n";
  items =
    ({
      "scuffing", "They seem to be footprints leading to the door.",
      "dust", "It's very fine powdery dust.  There seem to be footprints "+
              "leading to the door",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar1", "west",
      "players/nooneelse/red/cellar11", "south",
    });
  if (arg) {
    door1->set_locked(1);
    door2->set_locked(0);
    return;
  }
  if (!present("door")) {
    door1=clone_object("players/nooneelse/obj/door");
    door2=clone_object("players/nooneelse/obj/door");
    door_long_desc = ("Dark ironbound door.\n");
    door1->set_all(
             "players/nooneelse/red/cellar10 south tarnished alchemkey 1 1 1");
    door2->set_all(
             "players/nooneelse/red/cellar11 north tarnished alchemkey 1 0 1");
    door1->set_door(door2);
    door2->set_door(door1);
    door1->set_door_long(door_long_desc);
    door2->set_door_long(door_long_desc);
    move_object(door1,this_object());
    call_other("players/nooneelse/red/cellar11", "???", 0);
    move_object(door2,"players/nooneelse/red/cellar11");
  }
  return;
}
