#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(0);

 short_desc ="Barbarian forest";
 long_desc =
 "  You have reached the center of the forest.  The thick trees\n"+
 "block out all light from above.  The trees are too dense to the\n"+
 "east to permit passage.  The death cries are almost deafening.\n";

 if(!present("wolf"))
	  move_object(clone_object("/players/catacomb/barbtribe/wolf.c"), this_object());

 items = ({
   "tree",
   "The trees themselves appear to be alive, refusing passage to the east", 
   "trees",
   "The trees themselves appear to be alive, refusing passage to the east", 
   "center",
   "Looking around you are able to see nothing but blood stained ground"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest1.c","west",
   "/players/catacomb/barbtribe/brooms/barbforest2.c","southwest",
   "/players/catacomb/barbtribe/brooms/barbforest6.c","southeast", 
   "/players/catacomb/barbtribe/brooms/barbforest5.c","north", 
   });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("The screams of pain and agony, become almost unbearable.\n");
  say(TPN+" closes their eyes, listens and opens them quickly, with\n"+
      "a look of utter fear.");
  return 1;  
}