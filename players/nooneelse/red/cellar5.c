/*
 cellar5.c
*/

inherit "room/room";

object scorpion, whip;

realm() { return "NT"; }

reset(arg) {
  if (arg) return;

  set_light(0);
  short_desc = "large wine room";
  no_castle_flag=1;
  long_desc =
    "This large room contains several racks of wooden wine casks.\n"
    + "All have been split open and contain nothing of value.  There\n"
    + "are scratches covering everything in the room.  There is also\n"
    + "a small hole in the floor.\n";
  items =
    ({
      "racks",
      "These are big wooden beams built into racks to hold large wine barrels.",
      "casks", "They are large wooden wine barrels.",
      "scratches", "They seem to be the tracks of something with strong claws.",
      "hole", "This small hole seems to lead to a room below.  You might "+
              "fit through it.",
    });
  dest_dir =
    ({
      "players/nooneelse/red/cellar4", "north",
      "players/nooneelse/red/cellar9", "east",
      "players/nooneelse/red/cellar7", "south",
      "players/nooneelse/red/cellar6", "down",
    });
  if (!find_living("nooneelsescorpion")) {
    scorpion=clone_object("obj/monster");
    scorpion->set_name("scorpion");
    scorpion->set_alt_name("nooneelsescorpion");
    scorpion->set_level(10);
    scorpion->set_hp(325);
    scorpion->set_wc(16);
    scorpion->set_ac(5);
    scorpion->set_ep(200000);
    scorpion->set_al(0);
    scorpion->set_short("A scorpion");
    scorpion->set_long("It's a huge, deadly scorpion.\n");
    scorpion->set_whimpy(1);
    scorpion->set_aggressive(1);
    scorpion->set_spell_mess1("Poison drips from the scorpion's tail.\n");
    scorpion->set_spell_mess2(
      "You feel the scorpion's poison burning through your veins.\n");
    scorpion->set_chance(10);
    scorpion->set_spell_dam(20);
    move_object(clone_object("players/nooneelse/obj/whip"), scorpion);
    move_object(scorpion, this_object());
  }
}
