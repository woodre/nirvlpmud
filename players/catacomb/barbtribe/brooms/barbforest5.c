#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Barbarian forest";
 long_desc =
 "  The trees above you have grown more scarce letting the light\n"+
 "down upon the ground.  The ground is covered in what appear to\n"+
 "be the tracks of humans.  The trees to the west seem to be dying\n"+
 "from some kind of disease.  The mountain range to the north blocks\n"+
 "passage in that direction.\n";

 items = ({
   "tree",
   "The canopy of trees above you has lessened making it easier to see", 
   "trees",
   "The canopy of trees above you has lessened making it easier to see", 
   "mountain",
   "The large mountain range blocks passage to the north",
   "range",
   "The large mountain range blocks passage to the north",
   "tracks",
   "The tracks lead to the east",
   "ground",
   "The ground is covered with tracks"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest4.c","west",
   "/players/catacomb/barbtribe/brooms/barbforest3.c","south",
   "/players/catacomb/barbtribe/brooms/barbVilEnt.c","east" 
   });

}

init(){
  ::init();
  
	add_action("listenem","listen");  
  }

listenem(str)
{
  write("You hear the sound of steel clashing against steel.\n");
  say(TPN+" closes their eyes and listens.\n");
  return 1;  
}