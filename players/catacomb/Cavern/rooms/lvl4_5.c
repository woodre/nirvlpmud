#define TP this_player()
#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc =("Durkor Caverns");
long_desc =(
"  A dead end.  The passage ends with a rock wall.  The walls\n"+
"are covered in blood.  One wall has a sort of picture drawn\n"+
"in blood.  The room has a very evil presence about it.  A \n"+
"passage leaves to the west.\n");

if(!present("jumak"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Jumak2.c"),
	    this_object());

items = ({
  "passage",
  "The passage leads off to the west",
  "wall",
  "The wall is covered in blood",
  "blood",
  "The blood almost seems to form some kind of picture",
  "picture",
  "The blood appears to form a creature engulfed in flames",
  "creature",
  "The creature appears to be the great Ifreet, lord of fire"
  });

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl4_4.c","west"
 
});
}


