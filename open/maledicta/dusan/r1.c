/* This is the first room and entrance into the ruins area. A secret way leads to
   room r4.c, which can be found out if you talk to the hunter in that same room
   allowing easier access on later adventures. */
#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define TP this_player()
#define QN query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc = 
"  Dark ruins stand looming before you, it's blackened walls crumbled\n"+
"and laying about in scattered piles.  A cobblestone path leads to the\n"+ 
"ruins and disappears through a doorway and into darkness.  Lining the\n"+
"path are numerous black rose bushes and burned out tree stumps. The\n"+
"landscape to the west is glimmering slightly, as if a curtain of energy\n"+
"is before it.\n";

items = ({
  "landscape",
  "You look at the landscape and notice that it is blurred, as if\n"+
  "a field of energy hovers before it",	
  "energy",
  "The same as the curtain of energy that came to life between the\n"+
  "great pillars, this same energy holds the power to bring you\n"+
  "back to the world in which you came. You need only enter it",
  "curtain",
  "The same as the curtain of energy that came to life between the\n"+
  "great pillars, this same energy holds the power to bring you\n"+
  "back to the world in which you came. You need only enter it",	
  "ruins",
  "Dark and foreboding, you aren't quite sure what the building\n"+
  "used to be, but whatever it was, it was torn to pieces and\n"+
  "burned a long time ago",
  "walls",
  "The few that remain standing near the entrance are deeply\n"+
  "scarred and burned. In some places the fire was so intense\n"+
  "as to melt the stones",
  "piles",
  "The last remnants of parts of the walls",
  "path",
  "The path is broken and leads to the ruins entrance, what lays\n"+
  "within is unknown",
  "entrance",
  "You cannot see much beyond the darkness cast by the burned walls",
  "doorway",
  "Not really much of a doorway, it resembles more of a hole torn\n"+
  "into a wall, although you can tell that some type of door frame\n"+
  "used to exist here",
  "darkness",
  "Cast by the shadows of the broken walls. The sky allows little\n"+
  "light to shine through its blackness, giving little relief",
  "bushes",
  "They might have once been beautiful, but now they are as ruined\n"+
  "as the land and building before them",
  "stumps",
  "You look closely at the burned up stumps and see that they are huge. A\n"+
  "past reminder of what they might have been",
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r2.c","path",
});

}


init(){
    ::init();
    
    add_action("secret_way", "circle");
    add_action("portal_enter", "enter");
}
portal_enter(string str){
	if(!str){ write("What?\n"); return 1; }
	if(str == "landscape" || str == "curtain" || str == "energy"){
	  write("\n\n");	
	  write("You walk into the curtain of energy that stands before the landscape...\n\n");
          write("And find yourself elsewhere.\n\n");
          say(tpn+" disappears.\n");
          move_object(tp, "/players/maledicta/castle/rooms/m6.c");
          tell_room(environment(tp), tpn+" appears suddenly between the pillars.\n", ({tp}));
          command("look", tp);
          return 1;	
          }
        write("What?\n");
        return 1;
        }
secret_way(string str){
	if(!str){ write("What?\n"); return 1; }
	if(str == "ruins"){
       write("You follow a secret path around the ruins and arrive in safety.\n");
          say(tpn+" leaves.\n");
          move_object(tp, "/players/maledicta/ruins/rooms/r4.c");
          tell_room(environment(tp), tpn+" crawls out of a hole in the wall.\n", ({tp}));
          command("look", tp);
          return 1;	
        }
        write("What?\n");
        return 1;
}
