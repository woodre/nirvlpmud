#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Entrance to barbarian encampment";
 long_desc =
 "  The encampment is surrounded by large wooden fences standing\n"+
 "over ten feet tall.  The door to the encampment is guarded by\n"+
 "the two barbarians set atop the fence.  To the west is the forest.\n";

 if(!present("guard"))
	  move_object(clone_object("/players/catacomb/barbtribe/barb2.c"),
	    this_object());

 items = ({
   "encampment",
   "The fences block off the view of the village", 
   "fence",
   "The guards watch for intruders from the forest", 
   "fences",
   "The guards watch for intruders from the forest",
   "door",
   "The guards atop the fences watch for evil trying to enter their village",
   "guards",
   "The guards look at you wondering if you are friend or foe",
   "forest",
   "The forest looms to the west, begging for more victims",
   "village",
   "The fences block off the view of the village"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest5.c","west",
   "/players/catacomb/barbtribe/brooms/barbvil2.c","door" 
   });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("Listening carefully you here the ring of steel on steel.\n");
  say(TPN+" closes their eyes and listens intently.\n");
  return 1;  
}