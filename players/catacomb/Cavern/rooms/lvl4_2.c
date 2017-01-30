#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
"  The cavern passageway leads off to the northwest and to the east. \n"+
"Both ways are completely dark making it impossible to determine what \n"+
"evils may await.  The passageways seem to grow smaller to the \n"+
"northwest while openining up to the east.\n");

items = ({
  "passageway",
  "The passage leads off to the northwest and to the east",
  "passage",
  "The passage leads off to the northwest and to the east"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_1.c","east",
  "/players/catacomb/Cavern/rooms/lvl4_3.c","northwest"
 
});
}


