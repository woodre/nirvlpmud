#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard9 "/players/maledicta/town/mobs/guard9.c"
#define guard10 "/players/maledicta/town/mobs/guard10.c"

inherit "room/room";

reset(arg) {
if(!present("civilian", this_object())) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }	
if(!find_object(guard9)){
move_object(guard9, this_object());
        }	
if(!find_object(guard10)){
move_object(guard10, this_object());	
       }
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"   You find yourself in front of the townhall, a large two-story building\n"+
"made from the same white stone as the other houses around you. Next to the\n"+
"hall is a large power generator, its structure humming melodically. The\n"+
"road continues to the south and east, encircling the town.\n";

items = ({
  "townhall",
  "A large building used for the governing and council of the town. A long\n"+
  "stairway leads up to its double front doors, small pillars standing to\n"+
  "either side of them",
  "building",
  "A large building used for the governing and council of the town. A long\n"+
  "stairway leads up to its double front doors, small pillars standing to\n"+
  "either side of them",
  "houses",
  "Ranging in size from small to medium, each is made of white stone and is\n"+
  "well cared for by its owner",
  "generator",
  "Used to power the cities defense wall and turrets, its energy supply is\n"+
  "nearly inexhaustible, allowing the city to repel nearly any attack",
  "road",
  "A well-kept stone road that encircles the entire town",
  
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t19.c","hall",
  "/players/maledicta/town/rooms/t13.c","east",
  "/players/maledicta/town/rooms/t15.c","south"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	