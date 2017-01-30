#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int i;
reset(arg) {
if(!present("civilian", this_object())) {
    for(i=0; i < 3; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
  }		
	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  Here the road continues to the north and south. A small shop stands\n"+
"to the west, a sign hanging in its window. To the south the road turns\n"+
"eastward following the defense wall. A large tower stands to the north-\n"+
"east in the center of the town, its walls glimmering brightly. Trees\n"+
"and shrubs line the street here, with very few houses within sight.\n";

items = ({
  "shop",
  "A shop made of white stone with a wood roof. A large window in the front\n"+
  "displays guns and other weapons of offense. A sign is hanging in its\n"+
  "window",
  "sign", 
  "A wood and metal sign with green lettering. Perhaps you should\n"+
  "try reading it?",
  "road",
  "A wide stone street that is very clean and well-worn",
  "wall",
  "A large stone and steel wall that glimmers with the power of an energy\n"+
  "barrier",
  "tower",
  "A large beautiful tower, its stone walls glimmering brightly in the light",
  "walls",
  "The walls of the tower glimmer with the power of an energy field",
  "trees",
  "Large trees that are very healthy",
  "shrubs",
  "You look about and see several shrubs that have been planted here by the\n"+
  "inhabitants of this town. They look very healthy",
  "houses",
  "This part of town has very few houses, the few that are here are mostly medium\n"+
  "sized and made of white stone",
  "street",
  "A wide stone road that is very clean and well-worn",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t15.c","north",
  "/players/maledicta/town/rooms/t3.c","south",
  "/players/maledicta/town/rooms/t17.c","shop"
});

}


init(){
  ::init();
  add_action("read_it", "read");
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	


read_it(string str){
	if(!str){ write("Read what?\n"); return 1; }
	  if(str = "sign"){
  	write("      The sign reads.....\n\n");
  	write("                "+HIR+"Derellia's Defense"+NORM+"\n");
  	write("                   [gun and weaponsmith]\n\n");
  	return 1;
        }
  return;
  }		
	