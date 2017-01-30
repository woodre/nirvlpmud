/*
  maze_8.c
*/

inherit "room/room";
inherit "/players/nooneelse/WIZARD_LEVEL";

int mirror_broken;

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "A plain white room with a mirrored wall";
  no_castle_flag=1;
  dest_dir =
    ({
      "players/nooneelse/red/coffin_room", "north",
      "players/nooneelse/red/maze_x", "east",
      "players/nooneelse/red/maze_x", "south",
      "players/nooneelse/red/maze_x", "west",
    });
  mirror_broken=0;
}

long() {
  if (mirror_broken)
    write(
      "Your senses reel as you enter this stark white.\n"+
      "Your eyes hurt as they strugle to focus on something.  Anything.\n"+
      "Though you see nothing in the room, you sense danger from the north.\n"+
      "   There are four obvious exits: north, east, south, west\n");
  else
    write(
      "Your senses reel as you enter this stark white.\n"+
      "Your eyes hurt as they strugle to focus on something.  Anything.\n"+
      "Though you see nothing in the room, you sense danger from the north.\n"+
      "Perhaps the evil is behind the floor-to-ceiling wall-to-wall mirror.\n"+
      "   There are three obvious exits: east, south, west\n");
}

init() {
  ::init();

  add_action("view_mirror", "look", 1);
  add_action("view_mirror", "examine", 3);
  add_action("north",    "north", 1);
  add_action("no_break", "break");
  add_action("no_break", "hit");
  add_action("no_break", "kick");
  add_action("break_it", "shoot");
  add_action("break_it", "fire");
}

view_mirror(str) {
  int n;
  object stuff;
  if (str != "mirror" && str != "at mirror" && str != "in mirror") return 0;
  if (mirror_broken) {
    write("Look at what mirror?\n");
    return 1;
  }
  write("It is so large, it covers the entire north wall.  In it, you see:\n");
  write(this_object()->short()+".\n");
  write("   There are three obvious exits: east, south, west\n");
  stuff=first_inventory(this_object());
  while (stuff) {
    if (stuff->short() && stuff->query_invis()<=0) {
      write(stuff->short()+"\n");
      n=1;
    }
    stuff=next_inventory(stuff);
  }
  return 1;
}

north() {
  if (!mirror_broken) {
    write("Booooiiinnnggg!  The mirror flexes but doesn't break.\n"+
          "Perhaps you need to remove the mirror before proceeding.\n");
    if (this_player()->query_level() >= WIZARD_LEVEL)
      write("\n<<< But, since you're a wizard, you can pass. >>>\n");
    else
      return 1;
  }
  move_object(this_player(), "players/nooneelse/red/coffin_room");
  if (this_player()->query_brief())
    tell_object(this_player(), environment(this_player())->short()+"\n");
  else
    command("look", this_player());
  return 1;
}

no_break(str) {
  string str2, str3;
  if (!str) return 0;
  sscanf(str, "%s %s", str2, str3);
  if (str=="mirror" || str3=="mirror") {
    write("Booooiiinnnggg!  The mirror flexes but doesn't break.\n"+
          "Perhaps you need to shoot a capsule at it.\n");
    return 1;
  }
}

break_it(str) {
  string str2;
  if (!str) return 0;
  if (!present("slingshot", this_player()) ||
      (str!="mirror" && str!="mirror with slingshot" &&
       str!="at mirror" && str!="at mirror with slingshot")) {
    write("Booooiiinnnggg!  The mirror flexes but doesn't break.\n"+
          "Perhaps you need to fire a capsule at it.\n");
    return 1;
  }
  write("Crash!  The mirror shatters!  Before the shards can reach the\n"+
        "floor, they glow red and vaporize.\n");
  mirror_broken=1;
  return 1;
}
