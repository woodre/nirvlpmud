#include "/players/jamila/ansi.h"
#define tp this_player()
inherit "/players/vertebraker/closed/std/room.c";


reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Boardwalk";
long_desc =
"  You have just stepped onto a boardwalk that has a few\n"+
"small shops running down the east side and the water\n"+
"splashing up underneath on the west.  There is a small\n"+
"bench here that tourists can rest on.\n";

add_listen("main", "You hear the bustling of tourists and the sound of the water rushing beneath.");
add_smell("main", "The smells of food mixed with the smells of the beach fill your nostrils.");

items = ({
  "boards",
  "The boards are a dark brown with stains from the salty water on them.", 
  "waves",
  "You look over the side and see the frothy waves rolling under the boardwalk.",
  "shops",
  "A few shops along the side of the boardwalk, they look friendly and welcoming.",
  "bench",
  "There is a bench close by that you may sit at to rest and watch the horizon.",
    });

dest_dir = ({
  "/players/jamila/sponge.c","sponge",
  "/players/jamila/boardwalk/bw2.c","south",
  });
  
}
