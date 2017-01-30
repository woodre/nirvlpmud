#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(0);

 short_desc ="Deep within the barbarian forest";
 long_desc =
 "  The trees are very thick here making movement almost\n"+
 "impossible.  You are able to hear annoying screeches\n"+
 "of some kind of creature coming from the east.\n";

 items = ({
   "tree",
   "You are able to see a nest of some sort high in the trees to the east", 
   "trees",
   "You are able to see a nest of some sort high in the trees to the east",
   "nest",
   "High in the trees to the east is a large nest housing some monstrosity" 
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest7.c","east",
   "/players/catacomb/barbtribe/brooms/barbforest3.c","northwest",
   "/players/catacomb/barbtribe/brooms/barbforest2.c","west", 
   });

}

init(){
  ::init();
  
	add_action("listenem","listen");  
  }

listenem(str)
{
  write("A high pitched screech comes from the east.\n");
  say(TPN+" covers their ears in defense.\n");
  return 1;  
}