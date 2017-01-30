#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
"  This is a small road in the town of Derellia. Along its sides are\n"+
"numerous trees and shrubs, blocking the sight of the wall to the\n"+
"south. Several small houses line the north side of the street, green\n"+
"yards and small gardens leading up to the road. Ahead to the east the\n"+
"road veers, circling the inside of the defense wall. To the west the\n"+
"road leads back to the gate and continues to circle the town.\n";

items = ({
  "road",
  "Well kept and made from smooth stone, they encircle the entire town",
  "trees",
  "Healthy looking and tall, they block out the site of the defense wall\n"+
  "beyond",
  "shrubs",
  "Small and healthy, they are mixed in with small flowers and grass",
  "flowers",
  "Each flower is beautiful, a wonderful fragrance arising from them",  
  "wall",
  "The cities defense wall. It is made of stone and steel and encircles"+
  "the entire town",
  "houses",
  "They are made of a white stone, each similar to the next. Small yards\n"+
  "and gardens are in front of them",
  "street",
  "Well kept and made from smooth stone, they encircle the entire town",
  "gate",
  "The entrance into the city, it is made of steel and reinforced by an\n"+
  "energy field",
  "yards",
  "Well-trimmed and carefully kept by their owners, they are very beautiful",
  "gardens",
  "Ranging from medium to small, each garden is beautifully done with\n"+
  "much care by its owner",
  
});

dest_dir = ({
  "/players/maledicta/town/rooms/t6.c","east",
  "/players/maledicta/town/rooms/t1.c","west"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	