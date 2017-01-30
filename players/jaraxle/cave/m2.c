#include "/players/jaraxle/ansi.h"

#define tp this_player()

#define tpn this_player()->query_name()

#define tpp this_player()->query_possessive()

inherit "room/room";



reset(arg) {

  if(arg) return;

set_light(1);



short_desc = "a trail in the mountains";

long_desc =

"  The pass begins to rise here, rounding the northern mountain at a\n"+

"gradual slope. The trail continues to the north over a small rise on\n"+

"the mountain, and also back to the east. A giant rock stands over you\n"+

"throwing the area into shadow.\n";  



items = ({

  "shadow",

  "The shadow from the huge rock before you. It is dark",	

  "pass",

  "Here the pass is gradually sloping upward toward the mountain, its\n"+

  "ground a little uneven as you continue",

  "vegetation",

  "You see small plants and tree's, the mountain not allowing for\n"+

  "anything larger to grow",

  "boulders",

  "Huge, they seem to have fallen from the mountains top, and rolled\n"+

  "a long way down",

  "mountain",

  "Much closer now, you see that the mountain is covered with small\n"+

  "amounts of vegetation, and huge boulders",

  "trail",

  "The trail is very worn, showing signs of heavy use. It continues\n"+

  "over a small jutting on the mountain and also back to the east",

  "rock",

  "You look at it and marvel at how closely it resembles a lion's\n"+

  "head. A small dirty stone lies to the side, its shape making you\n"+

  "think its not of natural make",

  "stone",

  "A small octagonal stone with some type of writing on it. It looks\n"+

  "like you could dust it off and maybe see what it says",

  "rise",

  "A small outcropping from the mountain that seems easy to traverse",

  

  });



dest_dir = ({

  "/players/jaraxle/castle/rooms/m3.c","north",

  "/players/jaraxle/castle/rooms/m1.c", "east",

});



}





init(){

  ::init();

  add_action("dust_stone", "dust");

  }



dust_stone(string str){

if(!str){

  write("dust what?\n");

  return 1;

    }	

if(str == "stone"){

  write("As you reach out to the stone a small electrical charge leaps out!\n");

  write(

  "You fall back feeling a jolt of energy erupt up and around you\n"+

  "encompassing the entire area!\n\n");

  write(

  "The rock of the lions head comes alive, its entire form a liquid state...\n"+

  "It turns to you, its eyes squinting slightly to stare down at you.\n");

  write(

  "\n\n\nIt suddenly lunges down at you!\n"+

  "                        "+HIR+"YOU ARE SWALLOWED WHOLE!"+NORM+"\n");

  say(this_player()->query_name()+" is swallowed up by a huge lions head!\n");

  move_object(this_player(), "/players/jaraxle/cave/rooms/entrance.c");

  tell_object(this_player(),

  "You find yourself somewhere else, and completely safe.\n");

  command("look", this_player());

  tell_room(environment(this_player()),

  this_player()->query_name()+" arrives suddenly.\n", ({ this_player() }));

  return 1;

  }

return 0;

}	

















	