/*
Vampire Guild Hall
*/

inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

object board;

reset(arg) {
  if(arg) return;

  if(!present("board")) {
    /*move_object("/players/eurale/VAMPIRES/OBJ/dboard.c", this_object());*/
      board=clone_object("/players/illarion/test/board");
      board->set_name("Vampire Discussion Board");
      board->set_remove_level(40);
      board->set_short_color(HIR);
      move_object(board);
    }

set_light(0);

short_desc = "Vampire Guild Hall";
long_desc = "\
The central Vampire Guild Hall is a large, cathedral-style hall, with\n\
arched doorways to the north, east and west, and a high, domed ceiling.\n\
The dome is filled with swirling grey mist, nearly obscuring a large hole\n\
in its south slope. A floor of polished black stone reflects what little\n\
light there is, and echoes with the footsteps of anyone who passes\n\
through.  In the northeast corner of the hall, a spiral staircase leads\n\
downward, and a large sign with ornate lettering is mounted on the\n\
southern wall.\n";

items = ({
  "doorways","\
The doorways are wide, arched openings, outlined with large, smooth,\n\
perfectly-fitted stones",
  "doorway","\
The doorways are wide, arched openings, outlined with large, smooth,\n\
perfectly-fitted stones",
  "ceiling","\
The ceiling is high and domed, and filled with a slowly churning grey mist",
  "hole","\
A large, oval-shaped hole, with smooth sides, that could only be reached\n\
by flying, or perhaps by falling down from above",
  "mist","Dark grey mist, constantly moving, yet never thinning",
  "floor","\
The floor is polished black stone, worn and buffed to a reflective finish",
  "sign","\
An antique-looking sign with red-black letters.  It might be more productive\n\
to read it",
  "staircase","\
A spiral stair of black wrought iron, wound around a post of the same\n\
material, descending downwards into the darkness",
  "wall","\
The walls are made of black stone and hold up the ceiling, contain three\n\
archways, and have a sign mounted on them.  They are otherwise unremarkable",
  "walls","\
The walls are made of black stone and hold up the ceiling, contain three\n\
archways, and have a sign mounted on them.  They are otherwise unremarkable",
});



dest_dir = ({
  "players/nooneelse/black/guild_members_room","north",
  "players/eurale/VAMPIRES/RMS/boardroom","east",
  "players/eurale/VAMPIRES/RMS/equip","west",
  "players/eurale/VAMPIRES/RMS/vgent","up",
  "players/eurale/VAMPIRES/RMS/basement","down",
});

}

drop_castle() { return 1; }
realm() { return "NT"; }

init() {
  ::init();
  add_action("post_office",        "post_office");
  add_action("post_office",        "Post_Office");
  add_action("old_post",        "post");
  add_action("Warp",        "warp");
  add_action("Dock","dock");
  add_action("Pass","pass");
  add_action("Board","board");
  add_action("Board","chalkboard");
  add_action("adv_guild",   "advance");
  add_action("church",      "church");
  add_action("lockers",     "lockers");
  add_action("hotel",       "hotel");
  add_action("rift","rift");
  add_action("read","read");
}

Board() {
  write("You spread your wings and fly to the "+BOLD+"CHALKBOARD.\n\n"+NORM);
  TP->move_player("into the mist#room/south/sforst24.c");
  return 1; }

Dock() {
  write("You spread your wings and fly to the "+BOLD+"Dock.\n\n"+NORM);
  TP->move_player("into the mist#players/wren/Area/coastline/coast2.c");
  return 1; }

Pass() {
  write("You spread your wings and fly to the "+BOLD+"PASS"+NORM+".\n\n");
  TP->move_player("into the mist#players/mythos/enterance.c");
  return 1; }

old_post() {
  write("To avoid confusion with the bulletin board, use the command post_office\n\
to fly to the post office.\n");
  return 0;
}
  
post_office() {
  write("You spread your wings and fly to the "+BOLD+"POST OFFICE"+
        NORM+".\n\n");
  TP->move_player("into the mist#room/post.c");
  return 1;
}

Warp() {
  write("You spread your wings and fly to the "+BOLD+
        "WARP"+NORM+".\n\n");
  TP->move_player("into the mist#players/eurale/RMS/warp");
  return 1;
}

adv_guild() {
  write("You flap your wings and fly to the "+BOLD+"ADVANCE HALL"+
        NORM+".\n\n");
  TP->move_player("into the mist#room/adv_guild");
  return 1;
}

church() {
  write("You flap your wings and fly to the "+BOLD+"CHURCH"+
        NORM+".\n\n");
  TP->move_player("up into the mist#room/church.c");
  return 1;
}

lockers() {
  write("You fly through the mist to the "+BOLD+"LOCKERS"+
        NORM+".\n\n");
  TP->move_player("into the mist#players/catwoman/tl.c");
  return 1;
}

hotel() {
  write("You sprout wings and fly to the "+BOLD+"HOTEL"+NORM+".\n\n");
  TP->move_player("into the mist#players/boltar/hotel/hotel");
  return 1; }

rift() {
  write("You flap your wings and fly to the "+BOLD+"RIFT"+NORM+".\n\n");
  TP->move_player("into the mist#players/saber/ryllian/rift.c");
  return 1; }

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str != "sign") {
  write("You cannot read that here.\n");
  return 1; }
else { write(BOLD+
  "The sign reads: You may exit this hallowed hall to a number of\n"+
  "places.  Travel carefully as there are dangers lurking about.\n\n"+
  HIR+
  "     Church     Advance     Lockers     Post_Office     Hotel\n"+
  "     Dock       Rift        Warp        Chalkboard      Pass\n"+
  "\n"+BOLD+
  "Take care, Children of the Night, and return before sunrise.\n\n"+
  "                                    The Vampire Elders"+NORM+".\n");
  say(capitalize(TPRN)+" reads the sign.\n");
  return 1; }
}
