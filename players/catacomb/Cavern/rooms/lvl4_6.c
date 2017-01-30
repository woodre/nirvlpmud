#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
" The passageway takes a sharp turn.  The smell of sulfur is very\n"+
"strong.  The walls are covered in blood from the many victims that\n"+
"fell to the creatures looming in the cavern.\n");

items = ({
  "passageway",
  "The passageway leads to the southwest and southeast",
  "walls",
  "The walls are covered in blood",
  "blood",
  "The blood almost seems to form some kind of picture",
  "picture",
  "The blood appears to form a set of runes",
  "runes",
  "The runes seem to form the word 'flames'"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_3.c","southeast",
  "/players/catacomb/Cavern/rooms/lvl4_7.c","southwest"
 
});
}


