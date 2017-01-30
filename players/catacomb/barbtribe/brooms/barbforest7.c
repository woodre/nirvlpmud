#define TPN this_player()->query_name()
inherit "room/room";

reset(arg) 
{
  if(arg) return;
 set_light(0);

 short_desc ="Deep within the barbarian forest";
 long_desc =
 "  The trees are very thick here making movement almost impossible.\n"+
 "You are finally able to see what is making that irritating noise.\n"+
 "You have come upon a nest of stirges and they are not pleased to\n"+
 "have been disturbed.\n";

if (!present("stirge"))
	   move_object(clone_object("/players/catacomb/barbtribe/stirge.c"),
	   this_object());

 items = ({
   "tree",
   "You are able to see a nest of some sort high in the trees", 
   "trees",
   "You are able to see a nest of some sort high in the trees",
   "nest",
   "The nest is much larger than any nest you have ever seen" 
   });

 dest_dir = ({
   "/players/catacomb/barbtribe/brooms/barbforest6.c","west", 
   });

}

init(){
  ::init();
  add_action("listenem","listen");  
  }

listenem(str)
{
  write("The stirges screech at you in defense of their home.\n");
  say(TPN+" covers their ears in defense.\n");
  return 1;  
}