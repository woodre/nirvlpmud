#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The barbarian forest";
 long_desc =
 "  The sunlight is very scarce here making it almost impossible\n"+
 "to see.  Looking closer at the ground you are able to see small\n"+
 "animal tracks.  The forest is too thick to continue to the south.\n"+
 "Returning to the clearing is your only hope for protection.\n";

 if(!present("snake"))
	  move_object(clone_object("/players/catacomb/barbtribe/snake.c"),
	    this_object());

 items = ({
   "tree",
   "Looking up at the trees you wonder what horrors they contain", 
   "trees",
   "Looking up at the trees you wonder what horrors they contain", 
   "clearing",
   "The forest opens up to a clearing to the west",
   "sunlight",
   "The sunlight filters down through the tall trees",
   "tracks",
   "Looking closer at the tracks you conclude they must belong to a wolf",
   "forest",
   "The vegetation to the south makes passage impossible",
   "ground",
   "Looking at the ground you can see some tracks",
   "vegetation",
   "The thick vegetation blocks passage to the south"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest1.c","north",
   "/players/catacomb/barbtribe/brooms/barbforest6.c","east",
   "/players/catacomb/barbtribe/brooms/barbforest3.c","northeast",
   "/players/catacomb/barbtribe/brooms/barbentrance.c","west", 
   });

}

init(){
  ::init();
      add_action("listenem","listen");  
  }

listenem(str)
{
  write("As you listen carefully, you hear death cries from deeper within\n"+
        "the forest.\n");
  say(TPN+" closes their eyes and listens intently.\n");
  return 1;  
}