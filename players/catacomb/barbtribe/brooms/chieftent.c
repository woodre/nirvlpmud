#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="In the chieftain's dwelling";
 long_desc =
 "  Upon entering the dwelling you are almost blinded by all of\n"+
 "the light in here.  On each side of the table are barbarians\n"+
 "discussing plans for ridding their forest of the disgusting gnolls.\n"+
 "A large throne-like chair sits at the head of the table.\n";

 if(!present("barbarian"))
	  move_object(clone_object("/players/catacomb/barbtribe/barb1.c"),
	    this_object());

 items = ({
   "barbarians",
   "These are the head guards of the chief of the Clan of Snakes", 
   "table",
   "A large wooden table littered with paper", 
   "chair",
   "The chieftain's seat, made of an old redwood",
   "paper",
   "The papers are full of battle tactics",
   "light",
   "No torches give off the light, but rather a magical enhancement"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbvil4.c","southwest",
   "/players/catacomb/barbtribe/brooms/barbvil3.c","northwest"
 });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("You listen to the council talk of their battle plans.\n");
  say(TPN+" listens to the barbarian council.\n");
  return 1;  
}