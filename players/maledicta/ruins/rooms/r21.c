#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("archangel")){
  move_object(clone_object("/players/maledicta/ruins/mobs/iceangel4.c"), this_object()); }
    if(!present("mane")){
  move_object(clone_object("/players/maledicta/ruins/mobs/shadowmane.c"), this_object()); }
  if(arg) return;
set_light(1);

short_desc = "The "+BOLD+""+BLK+"Ruins"+NORM+"";
long_desc =
"  As you follow the hallway you round the corner only to find that what\n"+
"seemed untouched has been mauled by whatever powerful forces assaulted\n"+
"this place. Before you the hallway has been burned and torn asunder. The\n"+
"walls, although still standing, are completely marred their old glory wiped\n"+
"away by the evil that has enveloped everything in this place. The broken\n"+
"hallway continues eastward through an archway into an open room and also\n"+
"back to the north.\n";

items = ({
  "walls",
  "You look closely and see that fire and claws have torn away the beauty\n"+
  "and perfection that once was, leaving now a reminder of what happened\n"+
  "here",
  "archway",
  "It looks as though perhaps a huge door might have once stood in its\n"+
  "frame, but now you only see a gaping hole",
});

dest_dir = ({
  "/players/maledicta/ruins/rooms/r19.c","north",
  "/players/maledicta/ruins/rooms/r22.c","east",
});

}
