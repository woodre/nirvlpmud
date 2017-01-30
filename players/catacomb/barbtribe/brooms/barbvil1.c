#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Barbarian village";
 long_desc =
 "  Primitive housing lines the mountain range to the north.\n"+
 "Many torches provide light for the barbarians.  To the south\n"+
 "and east are more houses.\n";

 if(!present("barbarian"))
	  move_object(clone_object("/players/catacomb/barbtribe/barb3.c"),
	    this_object());

 items = ({
   "torches",
   "Many torches on the outsides of the houses provide light for the residents", 
   "torch",
   "A single torch is on the outside of each house", 
   "mountain",
   "The large mountain ranges block passage to the north",
   "house",
   "The houses are made out of wood and clay"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbvil2.c","south",
   "/players/catacomb/barbtribe/brooms/barbvil3.c","east"
 });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("You can hear the sound of steel on heated metal.\n");
  say(TPN+" listens to the sounds of a blacksmith.\n");
  return 1;  
}
