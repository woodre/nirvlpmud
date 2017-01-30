#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
"  Gutteral moaning can be heard reverberating throughout the\n"+
"room.  It seems to be originating to the east. The passage\n"+
"opens up to the east allowing safe passage.  To the southwest \n"+
"the passage grows smaller.\n");

items = ({
  "passage",
  "The passage leads off to the east and to the southwest"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_3.c","southwest",
  "/players/catacomb/Cavern/rooms/lvl4_5.c","east"
 
});
}


