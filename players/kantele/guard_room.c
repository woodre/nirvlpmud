#pragma strong_types

inherit "room/room";

int gate1, gate2, gate3;

void populate();

void reset(status arg) {
  ::reset(arg);
  populate();
  if (arg)
    return;
  set_light(1);
  set_short("A guard room");
  set_long(
"A guard room. You can leave to the east into a hall,\n"+
"west into a torture room and south into a dungeon corridor.\n"+
"Three large iron rings are fastened in the wall.\n");
  dest_dir = ({
    "players/kantele/torture_chamber", "west",
    "players/kantele/west_bridge.c", "east",
    "players/kantele/dungeon_corridor", "south"
  });
  items = ({
    "ring", "They look like they are fastened to some sort of wire",
    "rings", "They look like they are fastened to some sort of wire"
  });
}



void populate() {
  object watchman, wep, dog;

  gate1 = gate2 = gate3 = 0;
  if (!watchman && !present("watchman")) {
    watchman = clone_object("obj/monster");
    watchman->set_name("watchman");
    watchman->set_level(14);
    watchman->set_short("The night watchman");
    watchman->set_ac(11);
    watchman->set_wc(18);
    watchman->set_aggressive(1);
    move_object(watchman, this_object());
    wep = clone_object("obj/weapon");
    wep->set_name("sturdy sword");
    wep->set_short("A sturdy sword");
    wep->set_class(15);
    wep->set_alias("sword");
    wep->set_value(700);
    move_object(wep, watchman);
  }
  if (!dog && !present("dog")) {
    dog  = clone_object("obj/monster");
    dog->set_name("dog");
    dog->set_short("A guard dog");
    dog->set_ac(7);
    dog->set_level(8);
    dog->set_wc(12);
    dog->set_aggressive(1);
    move_object(dog, this_object());
  }
}

void init() {
  ::init();
  add_action("pull_ring", "pull");
}

status pull_ring(string str) {
  int ringnum;
  string gatemsg;
  
  if (sscanf(str, "ring %d", ringnum) != 1) {
    write("Which ring would you like to pull, 1, 2, or 3?\n");
  }
  write("You pull ring "+ringnum+".\n");
  say(this_player()->query_name()+" pulls ring "+ringnum+".\n");
  switch(ringnum) {
    case 1:
      if(!gate1) {
        gate1 = 1;
        gatemsg = "grinding";
      } else {
        gate1 = 0;
        gatemsg = "crunching";
      }
      break;
    case 2:
      if (!gate2) {
        gate2 = 1;
        gatemsg = "grinding";
      } else {
        gate2 = 0;
        gatemsg = "crunching";
      }
      break;
    case 3:
      if (!gate3) {
        gate3 = 1;
        gatemsg = "grinding";
      } else {
        gate3 = 0;
        gatemsg = "crunching";
      }
      break;
    default:
      write("There are not that many rings here.\n");
      return 1;
      gatemsg = "";
      break;
  }
  if (sizeof (explode(gatemsg, "")) > 0)
    tell_room(this_object(), "You hear a "+gatemsg+" sound.\n");
  return 1;
}

int query_gate1() { return !gate1; }
int query_gate2() { return !gate2; }
int query_gate3() { return !gate3; }
