#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="A clearing before a forest";
 long_desc =(
 "  You enter a lush clearing with some small shrubs.  Looking to\n"+
 "the west you are able to see a dark forest.  To the east and\n"+
 "south there is a large mountain range blocking passage.  Looking\n"+
 "closer at the eastern mountains, a glyph of a cave can be seen.\n");

 items = ({
   "shrub",
   "Some small vegetation in the clearing", 
   "shrubs",
   "Some small vegetation in the clearing", 
   "forest",
   "A path to the east leads into the dark forest",
   "vines",
   "Looking closer at the vines you see a small cave behind them",
   "vine",
   "Looking closer at the vines you see a small cave behind them",
   "section",
   "Looking closer at the vines you see a small cave behind them",
   "mountain",
   "The large mountain ranges block passage to the south and west",
   "mountains",
   "The large mountain ranges block passage to the south and west",
   "path",
   "A simple path leading deeper into the forest",
   "vegetation",
   "Some small shrubs are in front of the forest",
   "clearing",
   "A small dirt clearing before the forest",
   "cave",
   "A hole in the mountain"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest1.c","northeast",
   "/players/catacomb/barbtribe/brooms/barbforest2.c","east", 
   });

}

init(){
  ::init();
  
      add_action("listenem","listen");
      add_action("tracem","trace");  
  }

listenem(str)
{
  write("As you listen carefully, you hear death cries from the forest.\n");
  say(TPN+" closes their eyes and listens intently.\n");
  return 1;  
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