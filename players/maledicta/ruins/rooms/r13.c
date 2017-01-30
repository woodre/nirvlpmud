#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("mane")){
  move_object(clone_object("/players/maledicta/ruins/mobs/shadowmane.c"), this_object()); }
  if(arg) return;
set_light(0);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"   This is a large room, carved from the blackened stone that surrounds\n"+
"you.  Standing against the far wall is a beautiful onyx unholy symbol,\n"+
"seemingly out of place among so much crude stone.  A small tunnel lies\n"+
"to the south leading into darkness.  Back to the west is the entrance\n"+
"into the tunnels.\n";

items = ({
  "onyx",
  "A shiney black stone, its surface is smooth to the touch",
  	
  "stone",
  "Carved by intense heat, it is all melted and blasted into\n"+
  "dried smooth pools",
  "unholy symbol",
  "A large symbol carved from pure onyx stone, it looks extremely\n"+
  "large and heavy. Its surface is covered with some unknown writing,\n"+
  "and a large engraving of a flaming sphere adorns its center.  Near\n"+
  "the top of the symbol is a huge black pearl, its shining surface\n"+
  "showing your reflection",
  "symbol",
  "A large symbol carved from pure onyx stone, it looks extremely\n"+
  "large and heavy. Its surface is covered with some unknown writing,\n"+
  "and a large engraving of a flaming sphere adorns its center.  Near\n"+
  "the top of the symbol is a huge black pearl, its shining surface\n"+
  "showing your reflection",
  "writing",
  "You cannot make it out",
  "pearl",
  "The largest pearl the world has ever seen. Upon closer inspection\n"+
  "you notice the stone around it is slightly scratched, as if claws\n"+
  "had made a circular mark around the pearl's setting",
  
  
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r12.c","west",
  "/players/maledicta/ruins/rooms/r14.c","south",
});

}


init(){
    ::init();
    
    add_action("move_pearl", "turn");
    
}

move_pearl(string str){
	if(!str){ write("turn what?\n"); return 1; }
	
	if(str == "pearl"){
	  write("\n\nYou turn the black pearl and find that it moves very easily within\n");
	  write("its setting. You feel it click and watch in astonishment as your\n");
	  write("settings shimmer and fade away to be replaced by that of a new room.\n\n\n");	
	  say(tpn+" fades away.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r23.c");
          tell_room(environment(tp), tpn+" arrives.\n", ({tp}));
          command("look", tp);
          return 1;
	}
	write("That didn't seem to work.\n");
	return 1;
	}
 
	