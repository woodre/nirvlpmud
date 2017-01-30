#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="The barbarian forest";
 long_desc =
 "  All around you are trees blocking out most of the sunlight.\n"+
 "To the west a large mountain blocks your path.  There appear\n"+
 "to be paths to the east and to the south.  The forest seems to\n"+
 "clear to the southwest.\n";

if(!present("snake"))
	move_object(clone_object("/players/catacomb/barbtribe/snake.c"),
	  this_object());

 items = ({
   "tree",
   "Looking up at the trees you wonder what horrors they contain", 
   "trees",
   "Looking up at the trees you wonder what horrors they contain", 
   "mountain",
   "The large mountain ranges block passage to the west",
   "sunlight",
   "The sunlight filters down through the tall trees",
   "path",
   "The foliage clears to the east and to the south allowing passage",
   "forest",
   "A small path lies to the southwest, allowing passage deeper into the forest"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest3.c","east",
   "/players/catacomb/barbtribe/brooms/barbforest2.c","south",
   "/players/catacomb/barbtribe/brooms/barbentrance.c","southwest",
   });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("As you listen carefully, you hear death cries from the forest.\n");
  say(TPN+" closes their eyes and listens intently.\n");
  return 1;  
}