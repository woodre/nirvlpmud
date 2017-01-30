#include "/players/nikki/ansi.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIY+"Gates of Tintagel"+NORM;
long_desc = CYN+
  "   Here at the end of the world, where the sea ravishes endlessly\n"+
  "against the crags below the castle and city walls, it is easy to be\n"+
  "dwarfed by the loom of these ancient stones that stretch into the\n"+
  "sea.  The herdsmen believed that the castle had been built by the\n"+
  "Ancient Ones from the lost lands of Lyonnesse and Ys.  On a clear\n"+
  "day, so the fisherman said, their old castles could be seen far out\n"+
  "under the water.  But to the non-believer, they look like towers of\n"+
  "rock, ancient mountains and hills now, at the very crags below the\n"+
  "the castle. The huge gates are open now, welcoming all visitors to\n"+
  "the city of Tintagel.\n"+NORM;


items = ({
  "sign","A large metal sign.  Perhaps you should read it",
  "stones",GRY+"The stones appear to have been worn from the sea and time"+NORM,
  "sea",HIC+"The sea is dark and brooding with its power"+NORM,
  "crags",RED+"Large rocks that make the castle look like it was carved from the cliffs\n"+
              "themselves"+NORM,
  "walls",GRY+"The walls surround the city and protect the castle"+NORM,
  "water",HIC+"The water is rough and demanding as it beats against the cliffs"+NORM,
  "cliffs",RED+"The cliffs are steep and jagged as they sink into the sea"+NORM,
  "gates",HIY+"The gates are made of thick wood and are very strong"+NORM,
  "castle","Made of many large stones, this castle is magnificent in size and architecture",

});

dest_dir = ({
	"room/forest8","out",
        "players/nikki/Tintagel/Rooms/courtyrd.c","north",
});

}

init() {
  ::init();
  add_action("read_sign","read");
}

/*  Read the sign  */
read_sign(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign" || str == "lettering") {
  write(HIY+"WELCOME TO TINTAGEL!\n"+NORM);
  return 1; }

}
