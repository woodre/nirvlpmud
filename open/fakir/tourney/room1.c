#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "  The granite walls of the arena's main hall are covered with colorful guild\n"+
    "crests from across the land of Nirvana.  Individual pennants and banners\n"+
    "hang from stout poles and flutter in the light draft created by the open\n"+
    "portal leading to the village green and the wide circular stairway to the\n"+
    "spectator stands above.  Two armed tournament guards stand at each side of\n"+
    "a stone archway which bears the insignia of the crossed swords over a silver\n"+
    "shield.  Only those who possess a tournament amulet may proceed north through\n"+
    "the arch.  A dark mahogany sign is nailed to the granite wall above the arch.\n"+
    "You should (RED) READ THE SIGN (OFF) before going north.\n";
  items=({
    "granite",  "A very hard stone with white undertones and light grey veins.",
    "walls",    "The walls are built of polished white granite, with the outside wall\n"+
                "being perhaps five times the height of a man, while the interior walls\n"+
                "taper in height as they approch the arena at the center of the complex.",
    "hall",     "This is where both gladiators and patrons enter the arena.",
    "crests",   "Symbolic representations of the many guilds of Nirvana.",
    "pennants", "Small triangular flags of different colors.",
    "banners",  "Long strips of cloth of different colors and length tied off from\n"+
                "pole to pole.  Names of former tournament champions are written on\n"+
                "each.",
    "poles",    "Long,  clear grained lengths of wood about two inches in diameter.",
    "doorway",  "The main door of the arena's great hall, it leads to the village green.",
    "stairway", "Unlike the walls, it is made of rough stone of various colors.  The\n"+
                "stairway itself is perhaps ten feet wide, and curves upward to the left.",
    "guards",   "Standing in full dress armor they guard the arched door to the interior\n"+
                "of the arena.",
    "archway",  "A dark opening in the middle of an otherwise solid interior wall, it is\n"+
                "built of the same colored stone as the stairway.   There are two crossed\n"+
                "swords on the face of the keystone in the center of the arch.",
    "swords",   "Silver longswords with gold gilt handguards...symbol of the Grand Tournament.",
    "arch",     "A dark opening in the middle of an otherwise solid interior wall, it is\n"+
                "built of the same colored stone as the stairway.   There are two crossed\n"+
                "swords on the face of its keystone."
  });
         
    


  dest_dir=({
    "/room/vill_green.c","leave",
    PATH+"room2.c","north",
    PATH+"stands.c","up",
  });
}
void init() {
  ::init();
  add_action("cmd_res","res");
  add_action("cmd_read","read");
}

int cmd_move(string str) {
  if(query_verb()=="north") {
    if(!present("tournament amulet",this_player())) {
      write("The guards will not you let you go through the arch\n"+
            "unless you have a tournament amulet.\n");
      say(TPN+" tries to go north, but is blocked by the guards.\n");
      return 1;
    }
  }
  return (int)::cmd_move(str);
}

int cmd_read(string str) {
  if(!str || str!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("If you are entering the tournament, please proceed north.  Do not bring\n"+
        "any outside equipment or heals with you.  If you do so, it will be removed\n"+
        "automatically in the next room.\n");
  return 1;
}

int cmd_res(string str) {
  TP->remove_ghost();
  return 1;
}
