/*
Vampire Guild Hall
*/

inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Vampire Guild Hall";
long_desc =
  "A large, cathedral-style hall surrounds you.  There are arched doorways\n"+
  "that lead off in multiple directions.  A domed ceiling has a sizeable\n"+
  "hole in its south side that is shrouded in a swirling grey mist.  The\n"+
  "polished black floor reflects what little light there is and echoes\n"+
  "the footsteps of anyone passing through.  On the wall is an ornate\n"+
  "sign written in old english.\n";

items = ({
  "doorways","Wide openings with curved tops.  They are outlined with\n"+
             "large, smooth stones fitted together perfectly.",
  "ceiling","High and curved from all sides.  It it filled with a grey\n"+
            "mist that moves of its own accord.",
  "hole","Cut into the ceiling is a smooth opening as if it were there\n"+
         "to allow winged creatures to enter or leave at will.",
  "mist","Swirling and dark grey, it never seems to dissipate.",
  "floor","Polished black stone that you can see your reflection in.",
  "sign","An antique-looking sign with red letters.",
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
  add_action("post",        "post");
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

post() {
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
  "     Church     Advance     Lockers     Post Office     Hotel\n"+
  "     Dock       Rift        Warp        Chalkboard      Pass\n"+
  "\n"+BOLD+
  "Take care, Children of the Night, and return before sunrise.\n\n"+
  "                                    The Vampire Elders"+NORM+".\n");
  say(capitalize(TPRN)+" reads the sign.\n");
  return 1; }
}
