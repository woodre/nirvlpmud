#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Entrance to the gnoll village";
 long_desc =
 "  The smell is almost enough to make you sick.  Garbage and\n"+
 "feces are everywhere.  Small tents can be seen to the west.\n"+
 "The forest is to the southeast.\n";

 if(!present("gnoll"))
	  move_object(clone_object("/players/catacomb/barbtribe/gnoll2.c"),
	    this_object());

 items = ({
   "garbage",
   "The smell coming from all of the garbage almost makes you sick", 
   "feces",
   "Obviously, the gnolls haven't found the luxury of a decent latrine", 
   "forest",
   "Snake Forest is back to the southeast",
   "tent",
   "The tents are very crude but work as shelter from some of the elements",
   "tents",
   "The tents are very crude but work as shelter from some of the elements"

   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest4.c","southeast",
   "/players/catacomb/barbtribe/brooms/gnollvil1.c","west",
   "/players/catacomb/barbtribe/brooms/gnollvil2.c","southwest", 
   });

}

init(){
  ::init();
  add_action("smellem","smell");  
  }

smellem(str)
{
  write("The stench assails you, making you almost pass out.\n");
  say(TPN+" smells the air and becomes pale.\n");
  return 1;  
}