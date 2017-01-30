#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  The passageway gives way to a large hole in the ground with a\n"+
 "ladder going down.  The evil presence strengthens down the ladder\n"+
 "giving all who enter the room an eerie feeling.  Not only are the \n"+
 "Durkor living in this cavern, but also their diety, Shimmergloom\n"+
 "lurks deep under the earth.  Loud screeches from the many bats that\n"+
 "inhabit this cave can be heard.\n");

 items = ({
   "passageway",
   "The darkness of the passageway makes passage difficult", 
   "hole",
   "A dark hole is in the center of the passageway", 
   "ground",
   "A dark hole is in the center of the passageway",
   "ladder",
   "A small ladder descends into the darkness",
   "cavern",
   "The darkness of the passageway makes passage difficult",
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_2.c","west",
   "/players/catacomb/Cavern/rooms/lvl1_4.c","north",
   "/players/catacomb/Cavern/rooms/lvl1_5.c","south",
   "/players/catacomb/Cavern/rooms/lvl2_1.c","ladder" 
   });

if(!present("bat"))
	move_object(clone_object("/players/catacomb/Cavern/mobs/bigbat.c"),
	  this_object());
}
