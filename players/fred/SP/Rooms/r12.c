#include "/players/fred/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "South Park";
long_desc =
"  You are heading north through the town.  There is a sign next\n"+
"to a pond on the left of the street and several shops on the\n"+  
"right side.  There are some kids splashing around in a puddle and\n"+
"you can just make out the shape of a building to the north.\n";

items = ({
  "pond",
  "A picturesque pond with several ducks swimming in it", 
  "street",
  "The street is made of smooth black asphalt",
  "shops",
  "They all appear to be closed and locked up",
  "building",
  "From here it looks like it could be the town bar",
  "ducks",
  "They are diving under the water for food",
  "sign",
  "The Sign reads: Stark's Pond",
  "kids",
  "They are laughing and giggling as they run through the puddle",
  "puddle",
  "The puddle is about 5 feet in length and the water is very murky",
  });

dest_dir = ({
  "/players/fred/SP/Rooms/r1.c","south",
  "/players/fred/SP/Rooms/r13.c","north",
  });
}
