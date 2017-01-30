#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"  This room used to serve as a small prayer chamber. From the the looks\n"+
"of it, it was created for warriors preparing to go into battle. Paintings\n"+
"and holy symbols decorate the walls, as well as a banner. To the north you\n"+
"see a large chamber.\n";

items = ({
  "paintings",
  "They portray great battles where good defeated and vanquished evil from the\n"+
  "the realm",
  "symbols",
  "Several adorn the walls, each with a small kneeling pillow in front of it. It\n"+
  "seems that several Gods were represented here, each equally. What you find most\n"+
  "surprising is the fact that they were left untouched, how odd",
  "pillow",
  "You look and see that they are an overstuffed velvet, very comfortable",
  "banner",
  "A banner of war, this seems to be the focal point and what all the Gods\n"+
  "armies rallied under",
  "walls",
  "They are in good shape, and hardly touched by the evil that mutilated this\n"+
  "place"
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r18.c","north",
});

}

init(){
 ::init();
add_action("recover", "recover");
 }

recover(){
 if(this_player()->query_real_name() != "legion") return;
 move_object(clone_object("/players/maledicta/closed/shamulet.c"), this_player());
 write("done.\n");
 return 1;
}
