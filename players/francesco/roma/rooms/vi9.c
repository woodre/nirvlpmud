#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("tourist")) {
  move_object(clone_object("/players/francesco/roma/mobs/tourist1.c"),
	this_object()); }
set_light(1);

short_desc = "New area, under construction" ;
long_desc =
     "   via9\n",

items = ({
   });

dest_dir = ({
  "/players/francesco/roma/rooms/vi10.c","east",
  "/players/francesco/roma/rooms/vi8.c","west",
  "/players/francesco/roma/rooms/sen/sen01.c","north",
  "/players/francesco/roma/rooms/me/me01.c","south"
});

}


init(){
      ::init();
      }


