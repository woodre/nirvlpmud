#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The Durkor caverns";
 long_desc =(
 "  A presence of evil pervades the area.  The Durkor have lived\n"+
 "in these caverns for many centuries coming to the surface only to\n"+
 "spread war and chaos.  The light from above does little to comfort\n"+
 "the adventurers who enter.  Several have entered to dispose of the\n"+
 "evil living in the cave, but none who have ventured to the deepest\n"+
 "depths have ever returned.\n");

 items = ({
   "caverns",
   "The light from above provides little shelter to those venturing into the caverns", 
   "cavern",
   "The light from above provides little shelter to those venturing into the caverns", 
   "light",
   "The light from above provides little shelter to those venturing into the caverns",
   "above",
   "The bright of the sun acts as an intruder into the darkness of the caverns",
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/ground.c","ladder",
   "/players/catacomb/Cavern/rooms/lvl1_2.c","east", 
   });

}
