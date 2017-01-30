#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Gnoll village";
 long_desc =
 "  The smell is almost enough to make you sick.  Garbage and\n"+
 "feces is everywhere.  Small tents are almost outnumbered by\n"+
 "the garbage on the ground.  To the west is an extra large\n"+
 "tent with many torches around the entrance.\n";

 items = ({
   "garbage",
   "The smell coming from all of the garbage almost makes you sick", 
   "feces",
   "Obviously, the gnolls haven't found the luxury of a decent latrine", 
   "ground",
   "The ground looks like a land fill",
   "tent",
   "The tent is a very crude dwelling but strange smells come from within",
   "torches",
   "The torches provide the only light for the village",
   "entrance",
   "The entrance is back to the east"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/gnollvil4.c","west",
   "/players/catacomb/barbtribe/brooms/gnollentrance.c","northeast",
   "/players/catacomb/barbtribe/brooms/gnollvil1.c","north", 
   });

}

init(){
  ::init();
      add_action("smellem","smell");  
  }

smellem(str)
{
  write("You smell something strange coming from within the tent.\n");
  say(TPN+" smells the air.\n");
  return 1;  
}