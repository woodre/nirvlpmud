#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("vampire")) {
  move_object(clone_object("/players/eurale/VAMPIRES/NPC/wingman.c"),
    this_object()); }
set_light(0);

short_desc = "Room of the Forsaken";
long_desc =
  "This small, cozy room has a narrow shelf running around its whole\n"+
  "perimeter.  Lighted candles burn, giving off an eerie, flickering\n"+
  "light.  A small, mattress is nestled against the rear wall beside\n"+
  "the door so that the guild guardian might rest when his tired old\n"+
  "bones get weary.\n";

items = ({
  "shelf","A narrow shelf following the walls about head height that\n"+
          "holds many lighted candles",
  "candles","Wax candles of various sizes and shapes.  Some are burnt\n"+
            "down while others appear to be new.  They provide light\n"+
            "for this otherwise dark room",
  "mattress","A soft, stuffed mattress to provide comfort when sleeping",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/init_room.c","north",
  "players/eurale/VAMPIRES/RMS/equip.c","south",
  "players/eurale/VAMPIRES/RMS/library.c","east",
  "players/eurale/VAMPIRES/RMS/donation.c","west",
});

}

realm() { return "NT"; }
is_castle() { return 1; }
clean_up() { return 0; }

