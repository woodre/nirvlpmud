#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Barbarian forest";
 long_desc =
 "  The trees appear to be sick in this area of the forest.  A\n"+
 "foul stench seems to be emitting from the northeast.  The\n"+
 "mountain to the north prevents movement in that direction.\n";

 items = ({
   "tree",
   "The trees look sickly with their drooping branches and dying leaves", 
   "trees",
   "The trees look sickly with their drooping branches and dying leaves", 
   "mountain",
   "The large mountain range blocks passage to the north",
   "branches",
   "The branches droop low, signifiying some kind of poison in this area",
   "leaves",
   "The leaves crunch under your feet, withered and discolored"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest5.c","east",
   "/players/catacomb/barbtribe/brooms/gnollentrance.c","northwest" 
   });

}

init(){
  ::init();
  
	add_action("smellem","smell");  
  }

smellem(str)
{
  write("The stench of refuse and feces overwhelms you from the northeast.\n");
  say(TPN+" sniffs the air and almost faints.\n");
  return 1;  
}