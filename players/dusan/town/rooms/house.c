#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
 if(!present("father")){
     move_object(clone_object("/players/dusan/town/mobs/father.c"), this_object());}  
  if(arg) return;
set_light(1);

short_desc = "Wooden Shack.";
long_desc =	
           "   A chill wind howls through the poorly made wooden walls \n"+
           "A small table, an old iron stove, a couple dingy matts, and \n"+
           "a small pantry is all this house calls furnishings.  The muddy\n"+
           "road is visible through the crooked doorway to the south.\n" ;

items = ({
  "road","You can see the main road to through the door",
  "wind","The wind howls through the cracks in the walls",
  "table","A crooked wooden table",
  "stove","A small, black, stout, iron stove",
  "matts","Small well used matts made of foul feathers bound in a cloth",
  "pantry","A wooden pantry",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn2","south",
});

}
