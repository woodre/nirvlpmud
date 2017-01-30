#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(1);

 short_desc ="Gnoll village";
 long_desc =
 "  The village is cluttered with garbage from the gnoll's last\n"+
 "battle.  Small tents line the mountain range to the north.  A\n"+
 "small gnoll child sits in front of a tent chewing on a slab of meat.\n";

 items = ({
   "garbage",
   "The smell coming from all of the garbage almost makes you sick", 
   "village",
   "The ground looks like a land fill",
   "ground",
   "The ground looks like a land fill",
   "tent",
   "The tents are very crude but work as shelter from some of the elements",
   "tent",
   "The tents are very crude but work as shelter from some of the elements",
   "child",
   "The gnoll child looks at you then returns to devouring the slab.",
   "mountain",
   "The mountain range serves as a natural barrier from enemies.",
   "range",
   "The mountain range serves as a natural defense against enemies."

});

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/gnollentrance.c","east",
   "/players/catacomb/barbtribe/brooms/gnollvil3.c","west",
   "/players/catacomb/barbtribe/brooms/gnollvil2.c","south", 
   });

}

init(){
  ::init();
      add_action("smellem","smell");  
  }

smellem(str)
{
  write("The stench assails you, making you almost pass out.\n");
  say(TPN+" smells the air and becomes pale.\n");
  return 1;  
}