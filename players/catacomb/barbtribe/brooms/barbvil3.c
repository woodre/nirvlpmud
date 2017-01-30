#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Barbarian village";
 long_desc =
 "  Primitive housing lines the mountain range to the north.\n"+
 "Many torches provide light for the barbarians.  Looking to\n"+
 "the southeast you can see a large house with guards in front\n"+
 "of the door.\n";

 items = ({
   "torches",
   "Many torches on the outsides of the houses provide light for the residents", 
   "torch",
   "A single torch is on the outside of each house", 
   "mountain",
   "The large mountain range block passage to the north",
   "house",
   "The house appears much larger than the other housing, perhaps you could 'enter'",
   "guards",
   "The guards stand at attention allowing only certain people to 'enter'",
   "door",
   "The guards stand at attention protecting their chief"
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbvil4.c","south",
   "/players/catacomb/barbtribe/brooms/barbvil1.c","west",
 });

}

init(){
  ::init();
      add_action("listenem","listen");
      add_action("getPastGuards","enter");  
  }

listenem(str)
{
  write("You hear the guards whispering about whether to\n"+
	"let you pass or not.\n");
  say(TPN+" listens to the guards at the door.\n");
  return 1;  
}

getPastGuards(str)
{
  write("The guards look at you and warn of their chieftan's power,\n"+
        "then allow you to enter.\n");
  say("The guards mutter something and allow them to enter.\n");
  this_player()->move_player("enter#/players/catacomb/barbtribe/brooms/chieftent.c");
  return 1;
}
