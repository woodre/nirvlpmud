#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard3 "/players/maledicta/town/mobs/guard3.c"
inherit "room/room";

reset(arg) {
if(!present("civilian", this_object())) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }	
if(!find_object(guard3)){
move_object(guard3, this_object());
}	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  Here the road T's, leading eastward to a Medical store. To the north\n"+
"the road continues, following the east defense wall. You see that the\n"+
"road also goes south, leading to the southern end of town. Several small\n"+
"houses and shops line the street. A huge building dominates the western\n"+
"view.\n";

items = ({
  "store",
  "A small store created to serve the travelers of these lands. It is made\n"+
  "of white stone",
  "road",
  "Smooth and well-kept, the road is made of stone which was expertly layed",
  "wall",
  "The cities defense wall. It is made of stone and steel and is partially\n"+
  "covered by small trees",
  "houses",
  "Made of white stone and ranging from small to medium in size, each is well\n"+
  "constructed and carefully kept",
  "shops",
  "Small shops that sell trinkets and necessaries for the population of\n"+
  "Derellia",
  "street",
  "Smooth and well-kept, the street is made of stone which was expertly layed",
  "building",
  "A tall building that towers over the other structures in the town. It is\n"+
  "made of white stone and steel" 
});

dest_dir = ({
  "/players/maledicta/town/rooms/t11.c","north",
  "/players/maledicta/town/rooms/t7.c", "south",
  "/players/maledicta/town/rooms/t10.c","shop"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	