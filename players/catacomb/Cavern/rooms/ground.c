#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Entrance to an underground lair";
 long_desc =(
 "  The ground quivers in fear from the evil contained within.  The\n"+
 "Durkor talk of a great dragon living beneath the earth.  Only \n"+
 "the bravest of their warriors have ventured deep into the cave to \n"+
 "find the dragon and its treasures.  A small sign is posted in the \n"+
 "ground with a glyph of a cave.  A ladder descends into the evil \n"+
 "beneath.\n");

 items = ({
   "ground",
   "As you stand before the cavern, the ground quivers in fear", 
   "earth",
   "As you stand before the cavern, the ground quivers in fear", 
   "cave",
   "A ladder descends into the darkness of the cavern",
   "cavern",
   "A ladder descends into the darkness of the cavern",
   "sign",
   "A small sign is posted in the ground with a picture of a cave.\n"+
   "Perhaps you could 'trace' the cave",
   "ladder",
   "The ladder acts as an entrance to the terror beneath the earth",
   });

 dest_dir = ({
   "/players/catacomb/Cavern/rooms/lvl1_1.c","ladder", 
   });

}

init(){
  ::init();
  
      add_action("tracem","trace");  
  }


tracem(str)
{
  if (str != "cave")
  {
    write("Try 'trace cave'.\n");
    return 1;
  }
  if (str == "cave")
  {
    write("You trace the cave and fade away.\n");
    say(TPN+" traces the glyph of a cave and fades away.\n");
    this_player()->move_player("trace#players/catacomb/cave.c");
    return 1;
  }
}